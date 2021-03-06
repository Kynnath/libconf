/*
 * File:   Expression.hpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:04
 */

#ifndef EXPRESSION_HPP
#define	EXPRESSION_HPP

#include "Property.hpp"
#include "Scope.hpp"

namespace cfg
{
    namespace syn
    {
        class Expression
        {
            public:
                enum Type
                {
                    e_Property,
                    e_Scope
                };

            private:
                Property m_property;
                Scope m_scope;
                Type m_type;

            public:
                Expression( Property const& i_property );
                Expression( Scope const& i_scope );
                Type const& GetType() const;
                Scope const& GetScope() const;
                Scope & GetScope();
                Property const& GetProperty() const;

                void Print( int const& i_indent = 0 ) const;
        };

    }
}

#endif	/* EXPRESSION_HPP */

