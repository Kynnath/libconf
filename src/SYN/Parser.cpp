/*
 * File:   Parser.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:00
 */

#include "Parser.hpp"

#include "Expression.hpp"

namespace cfg
{
    namespace syn
    {
        std::vector< std::unique_ptr< Expression > > BuildSyntaxTree( std::vector<lex::Token> const& i_tokenSequence )
        {
            std::vector< std::unique_ptr< Expression > > test;
            return test;
        }
    }
}
