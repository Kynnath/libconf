/*
 * File:   Config.hpp
 * Author: JoPe
 *
 * Created on 28 de abril de 2014, 23:42
 */

#ifndef CONFIG_HPP
#define	CONFIG_HPP

#include <map>
#include <string>
#include "SYN/Value.hpp"

namespace cfg
{
    class Config
    {
        std::map< std::string, syn::Value > m_symbolTable;

        public:
            Config( std::string const& i_configFile );
            bool const& GetBoolProperty( std::string const& i_boolProperty ) const;
            int const& GetIntProperty( std::string const& i_intProperty ) const;
            float const& GetFloatProperty( std::string const& i_floatProperty ) const;
            std::string const& GetStringProperty( std::string const& i_stringProperty ) const;
            bool PropertyExists( std::string const& i_propertyName, syn::Value::Type const& i_valueType ) const;
    };
}

#endif	/* CONFIG_HPP */

