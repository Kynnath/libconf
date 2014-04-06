/*
 * File:   Parser.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:00
 */

#include "Parser.hpp"

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
        void FirstToken( ParserData & io_data );
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

            ParserData( std::vector<lex::Token> const& i_tokenSequence );
        };

        ParserData::ParserData( std::vector<lex::Token> const& i_tokenSequence )
            : m_state ( ExpressionList )
            , m_currentToken ( i_tokenSequence.begin() )
            , m_endToken ( i_tokenSequence.end() )
        {}

        void ExpressionListState( ParserData & io_data )
        {
            if ( io_data.m_currentToken == io_data.m_endToken )
            {
                io_data.m_state = nullptr;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::Name )
            {
                io_data.m_state = ReadProperty;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::ScopeLeftDelimiter )
            {
                io_data.m_state = PushScope;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::LineDelimiter )
            {
                ++io_data.m_currentToken;
            }
            else if ( io_data.m_currentToken->GetType() == lex::Token::ScopeBottomDelimiter )
            {
                io_data.m_state = PopScope;
            }
            else
            {
                throw SyntaxError();
            }
        }

        void FirstTokenState( ParserData & io_data )
        {}

        void PropertyState( ParserData & io_data )
        {}

        void ScopeState( ParserData & io_data )
        {}

        void PropertyListState( ParserData & io_data )
        {}

        std::vector< Expression > BuildSyntaxTree( std::vector<lex::Token> const& i_tokenSequence )
        {
            ParserData data ( i_tokenSequence );

            while ( data.m_state )
            {
                data.m_state( data );
            }

            return data.m_expressionTree;
        }
    }
}
