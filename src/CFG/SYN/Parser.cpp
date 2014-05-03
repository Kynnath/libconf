/*
 * File:   Parser.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:00
 */

#include "Parser.hpp"

#include <cassert>
#include "Expression.hpp"
#include "SyntaxError.hpp"
#include "CFG/LEX/Token.hpp"

namespace cfg
{
    namespace syn
    {
        struct ParserData;
        typedef void(*StateFunction)( ParserData& );

        Value GetValue( lex::Token const& i_token );
        void ExpressionList( ParserData & io_data );
        void ReadProperty( ParserData & io_data );
        void PushScope( ParserData & io_data );
        void PopScope( ParserData & io_data );
        void PropertyList( ParserData & io_data );

        struct ParserData
        {
            Scope m_root;
            StateFunction m_state;
            StateFunction m_propertyReturn;
            std::vector<lex::Token>::const_iterator m_currentToken;
            std::vector<lex::Token>::const_iterator const m_endToken;
            std::vector<Scope*> m_scopeStack;
            int m_braces;

            ParserData( std::vector<lex::Token> const& i_tokenSequence );
        };

        ParserData::ParserData( std::vector<lex::Token> const& i_tokenSequence )
            : m_root ( std::string() )
            , m_state ( ExpressionList )
            , m_propertyReturn ( ExpressionList )
            , m_currentToken ( i_tokenSequence.begin() )
            , m_endToken ( i_tokenSequence.end() )
            , m_braces ( 0 )
        {
            m_scopeStack.push_back( &m_root );
        }

        Value GetValue( lex::Token const& i_token )
        {
            assert( i_token.GetType() == lex::Token::e_Bool ||
                    i_token.GetType() == lex::Token::e_Integer ||
                    i_token.GetType() == lex::Token::e_Float ||
                    i_token.GetType() == lex::Token::e_String );

            if ( i_token.GetType() == lex::Token::e_Bool )
            {
                return Value( i_token.GetBool() );
            }
            else if ( i_token.GetType() == lex::Token::e_Integer )
            {
                return Value( i_token.GetInt() );
            }
            else if ( i_token.GetType() == lex::Token::e_Float )
            {
                return Value( i_token.GetFloat() );
            }
            else
            {
                return Value( i_token.GetString() );
            }
        }

        void ExpressionList( ParserData & io_data )
        {
            if ( io_data.m_currentToken == io_data.m_endToken )
            {
                io_data.m_state = nullptr;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_Name )
            {
                io_data.m_propertyReturn = ExpressionList;
                io_data.m_state = ReadProperty;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeLeftDelimiter )
            {
                io_data.m_state = PushScope;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeBottomDelimiter )
            {
                io_data.m_state = PopScope;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter ||
                      io_data.m_currentToken->GetType() == lex::Token::e_Comment )
            {
                ++io_data.m_currentToken;
            }
            else
            {
                throw SyntaxError( SyntaxError::e_UnknownExpression, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Bad Expression
            }
        }

        void ReadProperty( ParserData & io_data )
        {
            std::string const& name ( io_data.m_currentToken->GetString() );

            ++io_data.m_currentToken;
            if ( io_data.m_currentToken != io_data.m_endToken &&
                 io_data.m_currentToken->GetType() == lex::Token::e_Assignment )
            {
                ++io_data.m_currentToken;
                if ( io_data.m_currentToken != io_data.m_endToken &&
                     ( io_data.m_currentToken->GetType() == lex::Token::e_Bool ||
                       io_data.m_currentToken->GetType() == lex::Token::e_Integer ||
                       io_data.m_currentToken->GetType() == lex::Token::e_Float ||
                       io_data.m_currentToken->GetType() == lex::Token::e_String ) )
                {
                    Value value ( GetValue( *io_data.m_currentToken ) );

                    io_data.m_scopeStack.back()->PushExpression( Expression( Property( name, value ) ) );
                    io_data.m_state = io_data.m_propertyReturn;

                    ++io_data.m_currentToken;

                    if ( io_data.m_currentToken == io_data.m_endToken )
                    {
                        io_data.m_state = nullptr; // Allowed to end on a value
                    }
                    else
                    {
                        if ( io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter )
                        {
                            ++io_data.m_currentToken;
                        }
                        else
                        {
                            throw SyntaxError( SyntaxError::e_ExpectedLineDelimiter, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Expected line delimiter
                        }
                    }
                }
                else
                {
                    throw SyntaxError( SyntaxError::e_ExpectedValue, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Expected value
                }
            }
            else
            {
                throw SyntaxError( SyntaxError::e_ExpectedAssignment, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Expected assignment
            }
        }

        void PushScope( ParserData & io_data )
        {
            ++io_data.m_currentToken;
            if ( io_data.m_currentToken != io_data.m_endToken &&
                 io_data.m_currentToken->GetType() == lex::Token::e_Name )
            {
                std::string const& name ( io_data.m_currentToken->GetString() );

                ++io_data.m_currentToken;
                if ( io_data.m_currentToken != io_data.m_endToken &&
                     io_data.m_currentToken->GetType() == lex::Token::e_ScopeRightDelimiter )
                {
                    ++io_data.m_currentToken;
                    if ( io_data.m_currentToken != io_data.m_endToken &&
                         io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter )
                    {
                        ++io_data.m_currentToken;
                        if ( io_data.m_currentToken != io_data.m_endToken )
                        {
                            if ( io_data.m_currentToken->GetType() == lex::Token::e_Name )
                            {
                                io_data.m_scopeStack.back()->PushExpression( Expression( Scope( name ) ) );
                                io_data.m_scopeStack.push_back( static_cast<Scope*>(&io_data.m_scopeStack.back()->GetScope()) );
                                io_data.m_state = PropertyList;
                            }
                            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeTopDelimiter )
                            {
                                ++io_data.m_currentToken;
                                if ( io_data.m_currentToken != io_data.m_endToken &&
                                     io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter )
                                {
                                    io_data.m_scopeStack.back()->PushExpression( Expression( Scope( name ) ) );
                                    io_data.m_scopeStack.push_back( static_cast<Scope*>(&io_data.m_scopeStack.back()->GetScope()) );
                                    ++io_data.m_currentToken;
                                    ++io_data.m_braces;
                                    io_data.m_state = ExpressionList;
                                }
                                else
                                {
                                    throw SyntaxError( SyntaxError::e_IllformedScope, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Can't read scope
                                }
                            }
                            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeLeftDelimiter )
                            {
                                io_data.m_state = PushScope;
                            }
                            else
                            {
                                throw SyntaxError( SyntaxError::e_IllformedScope, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Can't read scope
                            }
                        }
                        else
                        {
                            io_data.m_state = nullptr;
                        }
                    }
                    else
                    {
                        throw SyntaxError( SyntaxError::e_ExpectedLineDelimiter, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Expected Line Delimiter
                    }
                }
                else
                {
                    throw SyntaxError( SyntaxError::e_ExpectedScopeRightDelimiter, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Expected Scope Right Delimiter
                }
            }
            else
            {
                throw SyntaxError( SyntaxError::e_ExpectedName, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Expected Name
            }
        }

        void PopScope( ParserData & io_data )
        {
            --io_data.m_braces;
            if ( io_data.m_braces >= 0 )
            {
                io_data.m_scopeStack.pop_back(); // After the if to ensure we don't try to pop an empty vector

                ++io_data.m_currentToken;
                if ( io_data.m_currentToken != io_data.m_endToken )
                {
                    if ( io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter )
                    {
                        ++io_data.m_currentToken;
                        io_data.m_state = ExpressionList;
                    }
                    else
                    {
                        throw SyntaxError( SyntaxError::e_ExpectedLineDelimiter, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Expected Line Delimiter
                    }
                }
                else
                {
                    io_data.m_state = nullptr; // Valid to end on a brace
                }
            }
            else
            {
                throw SyntaxError( SyntaxError::e_MismatchedBracers, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Mismatched braces
            }
        }

        void PropertyList( ParserData & io_data )
        {
            if ( io_data.m_currentToken->GetType() == lex::Token::e_Name )
            {
                io_data.m_propertyReturn = PropertyList;
                io_data.m_state = ReadProperty;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeLeftDelimiter )
            {
                io_data.m_scopeStack.pop_back();
                io_data.m_state = PushScope;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeBottomDelimiter )
            {
                io_data.m_scopeStack.pop_back();
                io_data.m_state = PopScope;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter ||
                      io_data.m_currentToken->GetType() == lex::Token::e_Comment )
            {
                ++io_data.m_currentToken;
            }
            else
            {
                throw SyntaxError( SyntaxError::e_IllformedProperty, io_data.m_currentToken->GetRow(), io_data.m_currentToken->GetColumn() ); // Bad Property
            }
        }

        std::vector< Expression > BuildSyntaxTree( std::vector<lex::Token> const& i_tokenSequence )
        {
            ParserData data ( i_tokenSequence );

            while ( data.m_state )
            {
                data.m_state( data );
            }

            if ( data.m_braces != 0 )
            {
                throw SyntaxError( SyntaxError::e_MismatchedBracers, (data.m_endToken-1)->GetRow(), (data.m_endToken-1)->GetColumn() ); // Mismatched braces
            }

            return data.m_root.GetExpressions();
        }
    }
}
