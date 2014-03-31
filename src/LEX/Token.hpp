/*
 * File:   Token.hpp
 * Author: juan.garibotti
 *
 * Created on 28 de marzo de 2014, 14:10
 */

#ifndef TOKEN_HPP
#define	TOKEN_HPP

#include <string>

namespace cfg
{
    namespace lex
    {
        class Token
        {
            public:
                enum Type
                {
                    Comment,
                    Integer,
                    Float,
                    Bool,
                    String,
                    Name,
                    ScopeLeftDelimiter,
                    ScopeRightDelimiter,
                    ScopeTopDelimiter,
                    ScopeBottomDelimiter,
                    LineDelimeter,
                    Assignment
                };

            private:
                Type m_type;
                int m_row;
                int m_column;
                int m_integerValue;
                float m_floatValue;
                bool m_boolValue;
                std::string stringValue;

            public:
                Token( int const& i_row, int const& i_column, int const& i_value );
                Token( int const& i_row, int const& i_column, float const& i_value );
                Token( int const& i_row, int const& i_column, bool const& i_value );
                Token( int const& i_row, int const& i_column, Type const& i_type );
                Token( int const& i_row, int const& i_column, Type const& i_type, std::string const& i_value );
        };
    }
}

#endif	/* TOKEN_HPP */

