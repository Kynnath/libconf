/*
 * File:   Config.cpp
 * Author: JoPe
 *
 * Created on 28 de abril de 2014, 23:42
 */

#include "Config.hpp"

#include "LEX/Lexer.hpp"
#include "SEM/SemanticAnalyzer.hpp"
#include "SYN/Expression.hpp"
#include "SYN/Parser.hpp"
#include "ConfigError.hpp"

namespace cfg
{
    Config::Config()
    {}

    Config::Config( std::string const& i_configFile )
        : m_symbolTable { sem::BuildSymbolTable( syn::BuildSyntaxTree( lex::BuildTokenSequence( i_configFile ) ) ) }
    {}

    void Config::LoadConfiguration( std::string const& i_configFile )
    {
        m_symbolTable = sem::BuildSymbolTable( syn::BuildSyntaxTree( lex::BuildTokenSequence( i_configFile ) ) );
    }

    Value const& Config::GetProperty( std::string const& i_property, Value::Type const& i_type ) const
    {
        auto const property ( m_symbolTable.find( i_property ) );

        if ( property != m_symbolTable.end() )
        {
            if ( property->second.GetType() == i_type )
            {
                return property->second;
            }
            else
            {
                throw ConfigError ( ConfigError::e_TypeMismatch );
            }
        }
        else
        {
            throw ConfigError ( ConfigError::e_MissingProperty );
        }
    }

    bool const& Config::GetBoolProperty( std::string const& i_boolProperty ) const
    {
        return GetProperty( i_boolProperty, Value::e_Bool ).GetBool();
    }

    int const& Config::GetIntProperty( std::string const& i_intProperty ) const
    {
        return GetProperty( i_intProperty, Value::e_Int ).GetInt();
    }

    float const& Config::GetFloatProperty( std::string const& i_floatProperty ) const
    {
        return GetProperty( i_floatProperty, Value::e_Float ).GetFloat();
    }

    std::string const& Config::GetStringProperty( std::string const& i_stringProperty ) const
    {
        return GetProperty( i_stringProperty, Value::e_String ).GetString();
    }

    bool Config::PropertyExists( std::string const& i_propertyName, Value::Type const& i_valueType ) const
    {
        auto const property ( m_symbolTable.find( i_propertyName ) );
        return ( property != m_symbolTable.end() && i_valueType == property->second.GetType() );
    }
}

