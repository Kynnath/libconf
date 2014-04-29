/*
 * File:   Expression.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:04
 */

#include "Expression.hpp"

#include <cassert>

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

        Expression::Type const& Expression::GetType() const
        {
            return m_type;
        }

        Scope const& Expression::GetScope() const
        {
            assert( m_type == e_Scope );
            return m_scope;
        }

        Scope & Expression::GetScope()
        {
            return ( const_cast<Scope&>( static_cast<Expression const&>(*this).GetScope() ) );
        }

        Property const& Expression::GetProperty() const
        {
            assert( m_type == e_Property );
            return m_property;
        }

        void Expression::Print( int const& i_indent ) const
        {
            if ( m_type == Expression::e_Property )
            {
                m_property.Print( i_indent );
            }
            else if ( m_type == Expression::e_Scope )
            {
                m_scope.Print( i_indent );
            }
        }
    }
}