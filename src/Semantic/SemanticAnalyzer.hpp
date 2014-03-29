/*
 * File:   SemanticAnalyzer.hpp
 * Author: juan.garibotti
 *
 * Created on 28 de marzo de 2014, 11:46
 */

#ifndef SEMANTICANALYZER_HPP
#define	SEMANTICANALYZER_HPP

#include <vector>
#include <string>
#include "../ConfigParser.hpp"

namespace cfg
{
    namespace sem
    {
        struct Property
        {
            enum Type
            {
                String,
                Int,
                Float,
                Bool
            };
            Type m_type;
            std::string m_name;

            std::string m_string;
            int m_int;
            float m_float;
            bool m_bool;
        };

        struct Scope
        {
            std::string m_name;
            std::vector< Property > m_properties;
        };

        struct SymbolTable
        {
            std::vector< Scope > m_scopes;

            SymbolTable( ConfigAST const& i_ast );
        };
    }
}
#endif	/* SEMANTICANALYZER_HPP */

