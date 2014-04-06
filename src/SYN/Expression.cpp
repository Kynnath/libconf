/*
 * File:   Expression.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:04
 */

#include "Expression.hpp"

namespace cfg
{
    namespace syn
    {
        Expression::Expression( Property const& i_property )
            : m_property ( i_property )
            , m_scope ( std::string() )
            , m_type ( Expression::e_Property )
        {}

        Expression::Expression( Scope const& i_scope )
            : m_property ( std::string(), Value( 0 ) )
            , m_scope ( i_scope )
            , m_type ( Expression::e_Scope )
        {}
    }
}