/*
 * File:   Scope.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:06
 */

#include "Scope.hpp"

#include "Expression.hpp"

namespace cfg
{
    namespace syn
    {
        Scope::Scope( std::string const& i_name )
            : m_name ( i_name )
        {}
    }
}