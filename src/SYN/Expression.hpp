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
        };

    }
}

#endif	/* EXPRESSION_HPP */

