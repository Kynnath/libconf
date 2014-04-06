/*
 * File:   Scope.hpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:06
 */

#ifndef SCOPE_HPP
#define	SCOPE_HPP

#include <memory>
#include <string>
#include <vector>


namespace cfg
{
    namespace syn
    {
        class Expression;
        class Scope
        {
            std::string m_name;
            std::vector< Expression > m_expressions;

            public:
                Scope( std::string const& i_name );
        };
    }
}

#endif	/* SCOPE_HPP */

