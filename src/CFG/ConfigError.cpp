/*
 * File:   ConfigError.cpp
 * Author: JoPe
 *
 * Created on 2 de mayo de 2014, 12:38
 */

#include "ConfigError.hpp"

namespace cfg
{
    char const k_description[][36] =
    {
        "Could not find property",
        "Property type doesn't match request"
    };

    ConfigError::ConfigError(const Type& i_type)
        : std::runtime_error ( k_description[ i_type ] )
        , m_type ( i_type )
    {}
}