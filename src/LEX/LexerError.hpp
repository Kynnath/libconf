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
                    IllegalFirstCharacter,
                    MisformedNumber
                };
                LexerError( Type const& i_errorType );
        };
    }
}

#endif	/* LEXERERROR_HPP */

