/*
 * File:   SyntaxError.hpp
 * Author: JoPe
 *
 * Created on 6 de abril de 2014, 01:05
 */

#ifndef SYNTAXERROR_HPP
#define	SYNTAXERROR_HPP

#include <stdexcept>

namespace cfg
{
    namespace syn
    {
        class SyntaxError
            : public std::runtime_error
        {
            public:
                enum Type
                {
                    IllegalEscape,
                    IllegalFirstCharacter,
                    IllegalName,
                    MisformedNumber,
                    MissingQuote
                };
            private:
                Type m_type;
                int m_row;
                int m_column;
            public:
                SyntaxError();
                int const& GetRow() const;
                int const& GetColumn() const;
        };
    }
}

#endif	/* SYNTAXERROR_HPP */

