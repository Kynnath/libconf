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
            : m_type ( Token::e_Integer )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_integerValue ( i_value )
        {}

        Token::Token( int const& i_row, int const& i_column, float const& i_value )
            : m_type ( Token::e_Float )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_floatValue ( i_value )
        {}

        Token::Token( int const& i_row, int const& i_column, bool const& i_value )
            : m_type ( Token::e_Bool )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_boolValue ( i_value )
        {}

        Token::Token( int const& i_row, int const& i_column, Type const& i_type )
            : m_type ( i_type )
            , m_row ( i_row )
            , m_column ( i_column )
        {
            assert( m_type == e_ScopeLeftDelimiter ||
                    m_type == e_ScopeRightDelimiter ||
                    m_type == e_ScopeTopDelimiter ||
                    m_type == e_ScopeBottomDelimiter ||
                    m_type == e_LineDelimiter ||
                    m_type == e_Assignment );
        }

        Token::Token( int const& i_row, int const& i_column, Type const& i_type, std::string const& i_value )
            : m_type ( i_type )
            , m_row ( i_row )
            , m_column ( i_column )
            , m_stringValue ( i_value )
        {
            assert( m_type == e_Comment ||
                    m_type == e_String ||
                    m_type == e_Name );
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
            "LineDelimiter",
            "Assignment"
        };

        Token::Type const& Token::GetType() const
        {
            return m_type;
        }

        bool const& Token::GetBool() const
        {
            assert( m_type == e_Bool );
            return m_boolValue;
        }

        int const& Token::GetInt() const
        {
            assert( m_type == e_Integer );
            return m_integerValue;
        }

        float const& Token::GetFloat() const
        {
            assert( m_type == e_Float );
            return m_floatValue;
        }

        std::string const& Token::GetString() const
        {
            assert( m_type == e_Comment ||
                    m_type == e_String ||
                    m_type == e_Name );
            return m_stringValue;
        }

        void Token::Print() const
        {
            std::cout << m_row << ":" << m_column << " " << k_tokenType[ m_type ] << std::endl;
        }
    }
}


