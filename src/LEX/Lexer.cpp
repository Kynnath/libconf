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

        struct LexerData
        {
            std::ifstream m_configFile;
            int m_row;
            int m_column;
            std::vector<Token> m_tokenSequence;
            char m_character;
            bool m_runLexer;
            StateFunction m_currentState;
        };

        void FirstCharacter( LexerData & io_lexerData )
        {
            if ( std::isblank( io_lexerData.m_character ) )
            {
                
            }

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
                io_lexerData.m_runLexer = false;
            }
        }

        // ReservedCharacter
        // NegativeNumber
        // Number
        // Name
        // String
        // Comment
        // Decimal
        // Escaped



        std::vector<Token> BuildTokenSequence( std::string i_configFile )
        {
            LexerData data;

            while ( data.m_runLexer )
            {
                data.m_currentState( data );
            }

            return data.m_tokenSequence;
        }
    }
}

