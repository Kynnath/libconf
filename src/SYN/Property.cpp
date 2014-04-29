/*
 * File:   Property.cpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2014, 00:06
 */

#include "Property.hpp"

#include <iostream>
#include <string>

namespace cfg
{
    namespace syn
    {
        Property::Property( std::string const& i_name, Value const& i_value )
            : m_name ( i_name )
            , m_value ( i_value )
        {}

        std::string const& Property::GetName() const
        {
            return m_name;
        }

        Value const& Property::GetValue() const
        {
            return m_value;
        }

        void Property::Print( int const& i_indent ) const
        {
            std::cout << std::string( i_indent*4, ' ' ) << m_name << " = ";

            switch ( m_value.GetType() )
            {
                case ( Value::e_Bool ):
                {
                    if ( m_value.GetBool() )
                    {
                        std::cout<< "true";
                    }
                    else
                    {
                        std::cout<< "false";
                    }
                    break;
                }
                case ( Value::e_Float ):
                {
                    std::cout << m_value.GetFloat();
                    break;
                }
                case ( Value::e_Int ):
                {
                    std::cout << m_value.GetInt();
                    break;
                }
                case ( Value::e_String ):
                {
                    std::cout << "\"" << m_value.GetString() << "\"";
                    break;
                }
            }

            std::cout << std::endl;
        }
    }
}