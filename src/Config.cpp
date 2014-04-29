/*
 * File:   Config.cpp
 * Author: JoPe
 *
 * Created on 28 de abril de 2014, 23:42
 */

#include "Config.hpp"

namespace cfg
{
    Config::Config( std::string const& i_configFile )
    {

    }

    bool const& Config::GetBoolProperty( std::string const& i_boolProperty ) const
    {
        return false;
    }

    int const& Config::GetIntProperty( std::string const& i_intProperty ) const
    {
        return 0;
    }

    float const& Config::GetFloatProperty( std::string const& i_floatProperty ) const
    {
        return 0.0f;
    }

    std::string const& Config::GetStringProperty( std::string const& i_stringProperty ) const
    {
        return std::string();
    }

    bool Config::PropertyExists( std::string const& i_propertyName, syn::Value::Type const& i_valueType ) const
    {
        return false;
    }
}

