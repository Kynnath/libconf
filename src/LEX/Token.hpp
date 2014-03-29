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
                    Integer,
                    Float,
                    Bool,
                    String,
                    Name,
                    ScopeLeftDelimiter,
                    ScopeRightDelimiter,
                    ScopeTopDelimiter,
                    ScopeBottomDelimiter,
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
                Token( std::string const& i_characterSequence );
        };
    }
}

#endif	/* TOKEN_HPP */

