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
    std::vector<Token> BuildTokenSequence(std::string const& i_configFile);
    std::vector<Token> BuildTokenSequence(std::ifstream & i_configFile);
  }
}

#endif	/* LEXER_HPP */

