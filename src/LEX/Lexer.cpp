/*
 * File:   Lexer.cpp
 * Author: JoPe
 *
 * Created on 29 de marzo de 2014, 01:23
 */

#include "Lexer.hpp"

#include <fstream>
#include "LexerError.hpp"
#include "Token.hpp"

namespace cfg
{
    namespace lex
    {
        struct LexerData;
        typedef void(*StateFunction)( LexerData& );

        // States
        void Initial( LexerData & io_lexerData );
        void FirstCharacter( LexerData & io_lexerData );
        void ReservedCharacter( LexerData & io_lexerData );
        void NegativeNumber( LexerData & io_lexerData );
        void Number( LexerData & io_lexerData );
        void Name( LexerData & io_lexerData );
        void String( LexerData & io_lexerData );
        void Comment( LexerData & io_lexerData );
        void Decimal( LexerData & io_lexerData );
        void Escaped( LexerData & io_lexerData );

        struct LexerData
        {
            std::ifstream m_configFile;
            int m_row, m_rowFirst;
            int m_column, m_columnFirst;
            std::vector<Token> m_tokenSequence;
            char m_character;
            StateFunction m_currentState;

            LexerData( std::string const& i_configFile );
        };

        LexerData::LexerData( std::string const& i_configFile )
            : m_configFile ( i_configFile )
            , m_currentState ( Initial )
        {}

        bool IsReserved( char const& i_character );
        bool IsNumber( char const& i_character );
        bool IsAlpha( char const& i_character );

        char const k_reserved[] =
        {
            ';',
            '[',
            ']',
            '{',
            '}',
            '=',
            '\"',
            '\n'
        };

        enum class Reserved
        {
            Comment,
            ScopeLeftDelimiter,
            ScopeRightDelimiter,
            ScopeTopDelimiter,
            ScopeBottomDelimiter,
            Assignment,
            Quote,
            LineDelimeter
        };

        bool IsReserved( char const& i_character )
        {
            for ( std::size_t index ( 0 ); index < sizeof( k_reserved ); ++index )
            {
                if ( i_character == k_reserved[ index ] )
                {
                    return true;
                }
            }
            return false;
        }

        void Initial( LexerData & io_lexerData )
        {
            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_row += 1;
                io_lexerData.m_currentState = FirstCharacter;
            }
            else
            {
                io_lexerData.m_currentState = NULL;
            }
        }

        void FirstCharacter( LexerData & io_lexerData )
        {
            io_lexerData.m_rowFirst = io_lexerData.m_row;
            io_lexerData.m_columnFirst = io_lexerData.m_column;

            if ( std::isblank( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = Initial;
            }
            else if ( IsReserved( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = ReservedCharacter;
            }
            else if ( io_lexerData.m_character == '-' )
            {
                io_lexerData.m_currentState = NegativeNumber;
            }
            else if ( std::isdigit( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = Number;
            }
            else if ( std::isalpha( io_lexerData.m_character ) || io_lexerData.m_character == '_' )
            {
                io_lexerData.m_currentState = Name;
            }
            else
            {
                throw LexerError( LexerError::IllegalFirstCharacter );
            }
        }

        void ReservedCharacter( LexerData & io_lexerData )
        {
            if ( io_lexerData.m_character == k_reserved[ Reserved::Assignment ] )
            {
                io_lexerData.m_currentState = String;
            }
            else if ( io_lexerData.m_character == k_reserved[ Reserved::Comment ] )
            {
                io_lexerData.m_currentState = Comment;
            }
            else
            {
                if ( io_lexerData.m_character == k_reserved[ Reserved::LineDelimeter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::LineDelimeter ) );

                    io_lexerData.m_row = 0;
                    io_lexerData.m_column += 1;
                }
                if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeLeftDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::ScopeLeftDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeRightDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::ScopeRightDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeTopDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::ScopeTopDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeBottomDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::ScopeBottomDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::Assignment ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::Assignment ) );
                }

                io_lexerData.m_currentState = Initial;
            }
        }

        std::vector<Token> BuildTokenSequence( std::string i_configFile )
        {
            LexerData data ( i_configFile );

            while ( data.m_currentState )
            {
                data.m_currentState( data );
            }

            return data.m_tokenSequence;
        }
    }
}

