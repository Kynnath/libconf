/*
 * File:   Config.cpp
 * Author: JoPe
 *
 * Created on 28 de abril de 2014, 23:42
 */

#include "Config.hpp"

#include <stdexcept>
#include "LEX/Lexer.hpp"
#include "SEM/SemanticAnalyzer.hpp"
#include "SYN/Expression.hpp"
#include "SYN/Parser.hpp"

namespace cfg
{
    Value const& Config::GetValue( std::string const& i_property ) const
    {
        auto const property ( m_symbolTable.find( i_property ) );

        if ( property == m_symbolTable.end() )
        {
            throw std::exception(); // property not found
        }
        else
        {
            return property->second;
        }
    }

    Config::Config( std::string const& i_configFile )
        : m_symbolTable ( sem::BuildSymbolTable( syn::BuildSyntaxTree( lex::BuildTokenSequence( i_configFile ) ) ) )
    {}

    bool const& Config::GetBoolProperty( std::string const& i_boolProperty ) const
    {
        Value const& value ( GetValue( i_boolProperty ) );
        if ( value.GetType() != Value::e_Bool )
        {
            throw std::exception(); // wrong type
        }
        else
        {
            return value.GetBool();
        }
    }

    int const& Config::GetIntProperty( std::string const& i_intProperty ) const
    {
        Value const& value ( GetValue( i_intProperty ) );
        if ( value.GetType() != Value::e_Int )
        {
            throw std::exception(); // wrong type
        }
        else
        {
            return value.GetInt();
        }
    }

    float const& Config::GetFloatProperty( std::string const& i_floatProperty ) const
    {
        Value const& value ( GetValue( i_floatProperty ) );
        if ( value.GetType() != Value::e_Float )
        {
            throw std::exception(); // wrong type
        }
        else
        {
            return value.GetFloat();
        }
    }

    std::string const& Config::GetStringProperty( std::string const& i_stringProperty ) const
    {
        Value const& value ( GetValue( i_stringProperty ) );
        if ( value.GetType() != Value::e_String )
        {
            throw std::exception(); // wrong type
        }
        else
        {
            return value.GetString();
        }
    }

    bool Config::PropertyExists( std::string const& i_propertyName, Value::Type const& i_valueType ) const
    {
        auto property ( m_symbolTable.find( i_propertyName ) );
        return ( property != m_symbolTable.end() && i_valueType == property->second.GetType() );
    }
}

