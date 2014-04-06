/*
 * File:   Parser.hpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:00
 */

#ifndef PARSER_HPP
#define	PARSER_HPP

#include <memory>
#include <vector>

namespace cfg
{
    namespace lex
    {
        class Token;
    }
    namespace syn
    {
        class Expression;
        std::vector< std::unique_ptr< Expression > > BuildSyntaxTree( std::vector<lex::Token> const& i_tokenSequence );
    }
}

#endif	/* PARSER_HPP */

