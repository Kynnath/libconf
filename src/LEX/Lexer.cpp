/*
 * File:   Lexer.cpp
 * Author: JoPe
 *
 * Created on 29 de marzo de 2014, 01:23
 */

#include "Lexer.hpp"

#include <fstream>

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
            NewLine
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
            if ( std::isblank( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = Initial;
            }
            else if ( IsReserved( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = ReservedCharacter;
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

