/*
 * File:   Token.cpp
 * Author: juan.garibotti
 *
 * Created on 28 de marzo de 2014, 14:10
 */

#include "Token.hpp"

#include <cassert>
#include <iostream>

namespace cfg
{
    namespace lex
    {
        Token::Token( int const& i_row, int const& i_column, int const& i_value )
            : m_type ( Token::Integer )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_integerValue ( i_value )
        {}

        Token::Token( int const& i_row, int const& i_column, float const& i_value )
            : m_type ( Token::Float )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_floatValue ( i_value )
        {}

        Token::Token( int const& i_row, int const& i_column, bool const& i_value )
            : m_type ( Token::Bool )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_boolValue ( i_value )
        {}

        Token::Token( int const& i_row, int const& i_column, Type const& i_type )
            : m_type ( i_type )
            , m_row ( i_row )
            , m_column ( i_column )
        {
            assert( m_type == ScopeLeftDelimiter ||
                    m_type == ScopeRightDelimiter ||
                    m_type == ScopeTopDelimiter ||
                    m_type == ScopeBottomDelimiter ||
                    m_type == LineDelimeter ||
                    m_type == Assignment );
        }

        Token::Token( int const& i_row, int const& i_column, Type const& i_type, std::string const& i_value )
            : m_type ( i_type )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_stringValue ( i_value )
        {
            assert( m_type == Comment ||
                    m_type == String ||
                    m_type == Name );
        }

        char const k_tokenType[][21] =
        {
            "Comment",
            "Integer",
            "Float",
            "Bool",
            "String",
            "Name",
            "ScopeLeftDelimiter",
            "ScopeRightDelimiter",
            "ScopeTopDelimiter",
            "ScopeBottomDelimiter",
            "LineDelimeter",
            "Assignment"
        };
        void Token::Print() const
        {
            std::cout << m_row << ":" << m_column << " " << k_tokenType[ m_type ] << std::endl;
        }
    }
}


