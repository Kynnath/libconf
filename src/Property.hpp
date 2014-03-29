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
    class Config
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
            std::vector<Config> m_section;

            Config const& GetProperty( std::string const& i_name ) const;

        public:
            Config() = default;
            Config( std::string const& i_filename );
            Config( std::string const& i_name, std::string const& i_value );
            Config( std::string const& i_name, int const& i_value );
            Config( std::string const& i_name, float const& i_value );
            Config( std::string const& i_name, bool const& i_value );
            Config( std::string const& i_name, std::vector<Config> const& i_value );

            void Print( int const& i_indent = 0 ) const;

            std::string const& GetStringProperty( std::string const& i_name ) const;
            int const& GetIntProperty( std::string const& i_name ) const;
            float const& GetFloatProperty( std::string const& i_name ) const;
            bool const& GetBoolProperty( std::string const& i_name ) const;
            std::vector<Config> const& GetSection( std::string const& i_name ) const;

            Config & SetStringProperty( std::string const& i_name, std::string const& i_value );
            Config & SetIntProperty( std::string const& i_name, int const& i_value );
            Config & SetFloatProperty( std::string const& i_name, float const& i_value );
            Config & SetBoolProperty( std::string const& i_name, bool const& i_value );
            Config & SetSection( std::string const& i_name );
    };
}
#endif	/* PROPERTY_HPP */

