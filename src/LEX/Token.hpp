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
                    e_Comment,
                    e_Integer,
                    e_Float,
                    e_Bool,
                    e_String,
                    e_Name,
                    e_ScopeLeftDelimiter,
                    e_ScopeRightDelimiter,
                    e_ScopeTopDelimiter,
                    e_ScopeBottomDelimiter,
                    e_LineDelimiter,
                    e_Assignment
                };

            private:
                Type m_type;
                int m_row;
                int m_column;
                int m_integerValue;
                float m_floatValue;
                bool m_boolValue;
                std::string m_stringValue;

            public:
                Token( int const& i_row, int const& i_column, int const& i_value );
                Token( int const& i_row, int const& i_column, float const& i_value );
                Token( int const& i_row, int const& i_column, bool const& i_value );
                Token( int const& i_row, int const& i_column, Type const& i_type );
                Token( int const& i_row, int const& i_column, Type const& i_type, std::string const& i_value );

                Type const& GetType() const;
                bool const& GetBool() const;
                int const& GetInt() const;
                float const& GetFloat() const;
                std::string const& GetString() const;
                int const& GetRow() const;
                int const& GetColumn() const;

                void Print() const;
        };
    }
}

#endif	/* TOKEN_HPP */

