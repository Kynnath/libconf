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

namespace cfg
{
    namespace syn
    {
        class Value;
    }

    enum class Value
    {
        e_Bool,
        e_Int,
        e_Float,
        e_String
    };

    class Config
    {
        std::map< std::string, syn::Value > m_symbolTable;

        syn::Value const& GetValue( std::string const& i_property ) const;

        public:
            Config( std::string const& i_configFile );
            bool const& GetBoolProperty( std::string const& i_boolProperty ) const;
            int const& GetIntProperty( std::string const& i_intProperty ) const;
            float const& GetFloatProperty( std::string const& i_floatProperty ) const;
            std::string const& GetStringProperty( std::string const& i_stringProperty ) const;
            bool PropertyExists( std::string const& i_propertyName, Value const& i_valueType ) const;
    };
}

#endif	/* CONFIG_HPP */

