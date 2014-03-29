/*
 * File:   Lexer.hpp
 * Author: JoPe
 *
 * Created on 29 de marzo de 2014, 01:23
 */

#ifndef LEXER_HPP
#define	LEXER_HPP

#include <vector>
#include "Token.hpp"

namespace cfg
{
    namespace lex
    {

        std::vector<Token> BuildTokenSequence( std::string i_configFile );


    }
}

#endif	/* LEXER_HPP */

