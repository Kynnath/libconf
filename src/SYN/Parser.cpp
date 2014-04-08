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
#include "LEX/Token.hpp"

namespace cfg
{
    namespace syn
    {
        struct ParserData;
        typedef void(*StateFunction)( ParserData& );

        void ExpressionList( ParserData & io_data );
        void ReadProperty( ParserData & io_data );
        void PushScope( ParserData & io_data );
        void PopScope( ParserData & io_data );
        void PropertyList( ParserData & io_data );

        struct ParserData
        {
            std::vector< Expression > m_expressionTree;
            StateFunction m_state;
            std::vector<lex::Token>::const_iterator m_currentToken;
            std::vector<lex::Token>::const_iterator const m_endToken;
            std::vector<std::string> m_currentScope;
            int m_braces;

            ParserData( std::vector<lex::Token> const& i_tokenSequence );
        };

        ParserData::ParserData( std::vector<lex::Token> const& i_tokenSequence )
            : m_state ( ExpressionList )
            , m_currentToken ( i_tokenSequence.begin() )
            , m_endToken ( i_tokenSequence.end() )
            , m_braces ( 0 )
        {}

        void ExpressionList( ParserData & io_data )
        {
            if ( io_data.m_currentToken == io_data.m_endToken )
            {
                io_data.m_state = nullptr;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::e_Name )
            {
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
                throw SyntaxError(); // Bad Expression
            }
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
                    ++io_data.m_currentToken;
                    if ( io_data.m_currentToken != io_data.m_endToken &&
                         io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter )
                    {
                        io_data.m_expressionTree.push_back( Expression( Property( name, value ) ) );
                        io_data.m_state = ExpressionList;
                        ++io_data.m_currentToken;
                    }
                    else
                    {
                        throw SyntaxError(); // Expected end of line
                    }
                }
                else
                {
                    throw SyntaxError(); // Expected value
                }
            }
            else
            {
                throw SyntaxError(); // Expected assignment
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
                                io_data.m_currentScope.push_back( name );
                                io_data.m_state = PropertyList;
                            }
                            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeTopDelimiter )
                            {

                                ++io_data.m_currentToken;
                                if ( io_data.m_currentToken != io_data.m_endToken &&
                                     io_data.m_currentToken->GetType() == lex::Token::e_LineDelimiter )
                                {
                                    io_data.m_currentScope.push_back( name );
                                    ++io_data.m_currentToken;
                                    ++io_data.m_braces;
                                    io_data.m_state = ExpressionList;
                                }
                                else
                                {
                                    throw SyntaxError(); // Can't read scope
                                }

                            }
                            else if ( io_data.m_currentToken->GetType() == lex::Token::e_ScopeLeftDelimiter )
                            {
                                io_data.m_state = PushScope;
                            }
                            else
                            {
                                throw SyntaxError(); // Can't read scope
                            }
                        }
                        else
                        {
                            io_data.m_state = nullptr;
                        }
                    }
                    else
                    {
                        throw SyntaxError(); // Expected Line Delimiter
                    }
                }
                else
                {
                    throw SyntaxError(); // Expected Scope Right Delimiter
                }
            }
            else
            {
                throw SyntaxError(); // Expected Name
            }
        }

        void PopScope( ParserData & io_data )
        {}

        void PropertyList( ParserData & io_data )
        {}

        std::vector< Expression > BuildSyntaxTree( std::vector<lex::Token> const& i_tokenSequence )
        {
            ParserData data ( i_tokenSequence );

            while ( data.m_state )
            {
                data.m_state( data );
            }

            if ( data.m_braces != 0 )
            {
                throw SyntaxError(); // Missing braces
            }

            return data.m_expressionTree;
        }
    }
}
