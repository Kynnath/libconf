/*
 * File:   Property.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:06
 */

#include "Property.hpp"

namespace cfg
{
    namespace syn
    {
        Property::Property( std::string const& i_name, Value const& i_value )
            : m_name ( i_name )
            , m_value ( i_value )
        {}
    }
}