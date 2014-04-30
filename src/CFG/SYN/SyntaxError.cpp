/*
 * File:   SyntaxError.cpp
 * Author: JoPe
 *
 * Created on 6 de abril de 2014, 01:05
 */

#include "SyntaxError.hpp"

namespace cfg
{
    namespace syn
    {
        char const k_description[][31] =
        {
            "Could not recognize expression",
            "Expected line delimiter",
            "Expected a value",
            "Expected assignment",
            "Could not read scope",
            "Expected scope right delimiter",
            "Expected a name",
            "Mismatched bracers",
            "Could not read property"
        };

        SyntaxError::SyntaxError( Type const& i_errorType, int const& i_row, int const& i_column )
        : std::runtime_error ( k_description[ i_errorType ] )
        , m_type ( i_errorType )
        , m_row ( i_row )
        , m_column ( i_column )
        {}

        int const& SyntaxError::GetRow() const
        {
            return m_row;
        }

        int const& SyntaxError::GetColumn() const
        {
            return m_column;
        }
    }
}