/*
 * File:   Property.hpp
 * Author: juan.garibotti
 *
 * Created on 18 de marzo de 2014, 17:22
 */

#ifndef PROPERTY_HPP
#define	PROPERTY_HPP

#include <string>
#include <vector>

namespace cfg
{
    class Property
    {
        public:
            enum Type
            {
                String,
                Int,
                Float,
                Bool,
                Section,
                File
            };

        private:
            Type m_type;
            std::string m_name;
            std::string m_string;
            int m_int;
            float m_float;
            bool m_bool;
            std::vector<Property> m_section;

        public:
            Property() = default;
            Property( std::string const& i_filename );
            Property( std::string const& i_name, std::string const& i_value );
            Property( std::string const& i_name, int const& i_value );
            Property( std::string const& i_name, float const& i_value );
            Property( std::string const& i_name, bool const& i_value );
            Property( std::string const& i_name, std::vector<Property> const& i_value );

            std::string const& GetStringProperty( std::string const& i_name ) const;
            int const& GetIntProperty( std::string const& i_name ) const;
            float const& GetFloatProperty( std::string const& i_name ) const;
            bool const& GetBoolProperty( std::string const& i_name ) const;
            std::vector<Property> const& GetSection( std::string const& i_name ) const;

            Property & SetStringProperty( std::string const& i_name, std::string const& i_value );
            Property & SetIntProperty( std::string const& i_name, int const& i_value );
            Property & SetFloatProperty( std::string const& i_name, float const& i_value );
            Property & SetBoolProperty( std::string const& i_name, bool const& i_value );
            Property & SetSection( std::string const& i_name );
    };
}
#endif	/* PROPERTY_HPP */

