/*
 * File:   Property.hpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:06
 */

#ifndef PROPERTY_HPP
#define	PROPERTY_HPP

#include <string>
#include "Value.hpp"

namespace cfg
{
    namespace syn
    {
        class Property
        {
            std::string m_name;
            Value m_value;

            public:
                Property( std::string const& i_name, Value const& i_value );

                void Print( int const& i_indent ) const;
        };
    }
}

#endif	/* PROPERTY_HPP */

