/*
 * File:   SemanticAnalyzer.hpp
 * Author: juan.garibotti
 *
 * Created on 28 de abril de 2014, 16:48
 */

#ifndef SEMANTICANALYZER_HPP
#define	SEMANTICANALYZER_HPP

#include <map>
#include <string>
#include <vector>

namespace cfg
{
    namespace syn
    {
        class Expression;
        class Value;
    }
    namespace sem
    {
        std::map< std::string, syn::Value > BuildSymbolTable( std::vector< syn::Expression > const& i_syntaxTree );
    }
}

#endif	/* SEMANTICANALYZER_HPP */

