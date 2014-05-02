/*
 * File:   LexerError.cpp
 * Author: JoPe
 *
 * Created on 30 de marzo de 2014, 17:19
 */

#include "LexerError.hpp"

namespace cfg
{
    namespace lex
    {
        char const k_description[][37] =
        {
            "Could not open file for reading",
            "Escaped character not recognized",
            "Character not allowed to start token",
            "Name contains forbidden character",
            "Bad number format",
            "Ending quote missing from string"
        };

        LexerError::LexerError(const Type& i_errorType, const int& i_row, const int& i_column )
            : std::runtime_error ( k_description[ i_errorType ] )
            , m_type ( i_errorType )
            , m_row ( i_row )
            , m_column ( i_column )
        {}

        int const& LexerError::GetRow() const
        {
            return m_row;
        }
        int const& LexerError::GetColumn() const
        {
            return m_column;
        }
    }
}