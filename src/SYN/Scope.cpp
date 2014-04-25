/*
 * File:   Scope.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:06
 */

#include "Scope.hpp"

#include <iostream>
#include <string>
#include "Expression.hpp" // Needed because of the expression vector

namespace cfg
{
    namespace syn
    {
        Scope::Scope( std::string const& i_name )
            : m_name ( i_name )
        {}

        std::vector< Expression > const& Scope::GetExpressions() const
        {
            return m_expressions;
        }

        void Scope::Print( int const& i_indent ) const
        {
            std::cout << std::string( " ", i_indent*4 ) << "[ " << m_name << "]" << std::endl;
        }
    }
}