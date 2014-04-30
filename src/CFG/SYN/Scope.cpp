/*
 * File:   Scope.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:06
 */

#include "Scope.hpp"

#include <cassert>
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

        std::string const& Scope::GetName() const
        {
            return m_name;
        }

        std::vector< Expression > const& Scope::GetExpressions() const
        {
            return m_expressions;
        }

        void Scope::PushExpression( Expression const& i_expression )
        {
            m_expressions.push_back( i_expression );
        }

        Scope & Scope::GetScope()
        {
            assert( m_expressions.back().GetType() == Expression::e_Scope );
            return m_expressions.back().GetScope();
        }

        void Scope::Print( int const& i_indent ) const
        {
            std::cout << std::string( i_indent*4, ' ' ) << "[ " << m_name << " ]" << std::endl;
            for ( auto const& expression : m_expressions )
            {
                expression.Print( i_indent + 1 );
            }
        }
    }
}