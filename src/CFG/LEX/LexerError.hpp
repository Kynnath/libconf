/*
 * File:   LexerError.hpp
 * Author: JoPe
 *
 * Created on 30 de marzo de 2014, 17:19
 */

#ifndef LEXERERROR_HPP
#define	LEXERERROR_HPP

#include <stdexcept>

namespace cfg
{
    namespace lex
    {
        class LexerError
            : public std::runtime_error
        {
            public:
                enum Type
                {
                    e_MissingFile,
                    e_IllegalEscape,
                    e_IllegalFirstCharacter,
                    e_IllegalName,
                    e_MisformedNumber,
                    e_MissingQuote
                };
            private:
                Type m_type;
                int m_row;
                int m_column;
            public:
                LexerError( Type const& i_errorType, int const& i_row, int const& i_column );
                int const& GetRow() const;
                int const& GetColumn() const;
        };
    }
}

#endif	/* LEXERERROR_HPP */

