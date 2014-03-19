/*
 * File:   Property.cpp
 * Author: juan.garibotti
 *
 * Created on 18 de marzo de 2014, 17:22
 */

#include "Property.hpp"

#include <fstream>
#include <cassert>

namespace cfg
{
    char const k_reservedCharacter[][2] =
    {
        ";",
        "[",
        "]",
        "{",
        "}",
        "="
    };

    enum ReservedCharacter
    {
        Comment,
        SectionStart,
        SectionEnd,
        GroupStart,
        GroupEnd,
        Assignment
    };

    Property::Property( std::string const& i_filename )
        : m_type ( Property::File )
        , m_name ( i_filename )
        , m_string ()
        , m_int ()
        , m_float ()
        , m_bool ()
        , m_section ()
    {
        // Break file into lines
        std::vector<std::string> lines;
        {
            std::ifstream confFile ( i_filename );
            std::string line;
            while ( std::getline( confFile, line ) )
            {
                lines.push_back( line );
            }
        }

        // For each line, determine if each line is a property or section
        for ( auto const& line : lines )
        {
            if ( line.front() == k_reservedCharacter[ SectionStart ] )
            {
                // New section
                assert( line.back() == k_reservedCharacter[ SectionEnd ] );
                m_section.push_back( Property( line.substr( 1, line.size()-2 ), std::vector<Property>() ) );
            }
        }

    }

    Property::Property( std::string const& i_name, std::string const& i_value )
        : m_type ( Property::String )
        , m_name ( i_name )
        , m_string ( i_value )
        , m_int ()
        , m_float ()
        , m_bool ()
        , m_section (){}

    Property::Property( std::string const& i_name, int const& i_value )
        : m_type ( Property::Int )
        , m_name ( i_name )
        , m_string ()
        , m_int ( i_value )
        , m_float ()
        , m_bool ()
        , m_section (){}

    Property::Property( std::string const& i_name, float const& i_value )
        : m_type ( Property::Float )
        , m_name ( i_name )
        , m_string ()
        , m_int ()
        , m_float ( i_value )
        , m_bool ()
        , m_section (){}

    Property::Property( std::string const& i_name, bool const& i_value )
        : m_type ( Property::Bool )
        , m_name ( i_name )
        , m_string ()
        , m_int ()
        , m_float ()
        , m_bool ( i_value)
        , m_section (){}

    Property::Property( std::string const& i_name, std::vector<Property> const& i_value )
        : m_type ( Property::Section )
        , m_name ( i_name )
        , m_string ()
        , m_int ()
        , m_float ()
        , m_bool ()
        , m_section ( i_value ){}

    std::string const& Property::GetStringProperty( std::string const& i_name ) const{}
    int const& Property::GetIntProperty( std::string const& i_name ) const{}
    float const& Property::GetFloatProperty( std::string const& i_name ) const{}
    bool const& Property::GetBoolProperty( std::string const& i_name ) const{}
    std::vector<Property> const& Property::GetSection( std::string const& i_name ) const{}

    Property & Property::SetStringProperty( std::string const& i_name, std::string const& i_value ){}
    Property & Property::SetIntProperty( std::string const& i_name, int const& i_value ){}
    Property & Property::SetFloatProperty( std::string const& i_name, float const& i_value ){}
    Property & Property::SetBoolProperty( std::string const& i_name, bool const& i_value ){}
    Property & Property::SetSection( std::string const& i_name ){}
}
