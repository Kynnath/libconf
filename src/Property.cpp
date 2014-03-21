/*
 * File:   Property.cpp
 * Author: juan.garibotti
 *
 * Created on 18 de marzo de 2014, 17:22
 */

#include "Property.hpp"

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace cfg
{
    char const k_reservedCharacter[][2] =
    {
        ";",
        "[",
        "]",
        "{",
        "}",
        "=",
        ":"
    };

    char const k_reservedValues[][6] =
    {
        "true",
        "false"
    };

    enum ReservedCharacter
    {
        Comment,
        SectionStart,
        SectionEnd,
        GroupStart,
        GroupEnd,
        Assignment,
        Scope
    };

    typedef std::vector< std::string > TokenList;

    bool LineIsAssignment( TokenList const& i_line )
    {
        for ( auto const& token : i_line )
        {
            if ( token.find( k_reservedCharacter[ Assignment ] ) != std::string::npos )
            {
                return true;
            }
        }
    }

    std::string PropertyName( TokenList const& i_line )
    {
        if ( i_line.size() > 1 )
        {
            return i_line.front();
        }
        else
        {
            return i_line.front().substr( 0, i_line.front().find( k_reservedCharacter[ Assignment ] ) );
        }
    }

    std::string PropertyValue( TokenList const& i_line )
    {
        int assignmentPos ( i_line.back().find( k_reservedCharacter[ Assignment ] ) );
        if ( assignmentPos == std::string::npos )
        {
            return i_line.back();
        }
        else
        {
            return i_line.back().substr( assignmentPos+1 );
        }
    }

    Property::Property( std::string const& i_filename )
        : m_type ( Property::File )
        , m_name ( i_filename )
        , m_string ()
        , m_int ()
        , m_float ()
        , m_bool ()
        , m_section ()
    {
        // Break file into tokens, separated by line
        std::vector< TokenList > lineTokens;
        {
            std::ifstream objFile ( i_filename );
            std::string line;

            while ( std::getline( objFile, line ) )
            {
                lineTokens.push_back( TokenList() );
                std::stringstream lineStream ( line );
                std::string token;
                while ( lineStream >> token )
                {
                    lineTokens.back().push_back( token );
                }
                if ( lineTokens.back().empty() )
                {
                    lineTokens.pop_back(); // Remove empty lines
                }
            }
        }

        // Keep track of our depth when adding properties
        std::vector<Property*> stack;
        stack.push_back( this );
        bool withinScope ( true );
        // For each line, determine if each line is a property or section
        for ( auto const& line : lineTokens )
        {
            if ( line.front().find( k_reservedCharacter[ SectionStart ] ) == 0 )
            {
                // New section
                assert( line.front().find( k_reservedCharacter[ SectionEnd ] ) == line.front().size()-1 )  ;
                if ( !withinScope )
                {
                    stack.pop_back();
                }
                stack.back()->m_section.push_back( Property( line.front().substr( 1, line.front().size()-2 ), std::vector<Property>() ) );
                stack.push_back( &( stack.back()->m_section.back() ) );
                withinScope = false;
            }
            else if ( line.front() == k_reservedCharacter[ GroupStart ] )
            {
                withinScope = true;
            }
            else if ( line.front() == k_reservedCharacter[ GroupEnd ] )
            {
                stack.pop_back();
                withinScope = true;
            }
            else if ( LineIsAssignment( line ) )
            {
                stack.back()->m_section.push_back( Property( PropertyName( line ), PropertyValue( line ) ) );
            }
            else if ( line.front().substr( 0, 1 ) == k_reservedCharacter[ Comment ] )
            {
                continue;
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

    Property const& Property::GetProperty( std::string const& i_name ) const
    {
        int first ( 0 );
        int index ( int( i_name.find( k_reservedCharacter[ Scope ] ) ) );
        Property const* currentProp ( this );
        while( index != int( std::string::npos ) )
        {
            for ( auto iter ( currentProp->m_section.begin() ), end( currentProp->m_section.end() ); iter != end; ++iter )
            {
                if ( iter->m_name == i_name.substr( (long long unsigned int)first, (long long unsigned int)index ) )
                {
                    currentProp = &(*iter);
                    first = index+1;
                    index = int( i_name.find( k_reservedCharacter[ Scope ], (long long unsigned int)first ) );
                    break;
                }
            }
        }
        if ( currentProp->m_name != i_name.substr( (long long unsigned int)first ) )
        {
            throw std::out_of_range( "Missing Property" );
        }
        return *currentProp;
    }
    std::string const& Property::GetStringProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_string;
    }

    int const& Property::GetIntProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_int;
    }

    float const& Property::GetFloatProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_float;
    }

    bool const& Property::GetBoolProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_bool;
    }

    std::vector<Property> const& Property::GetSection( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_section;
    }

    Property & Property::SetStringProperty( std::string const& i_name, std::string const& i_value )
    {
        return *this;
    }

    Property & Property::SetIntProperty( std::string const& i_name, int const& i_value )
    {
        return *this;
    }

    Property & Property::SetFloatProperty( std::string const& i_name, float const& i_value )
    {
        return *this;
    }

    Property & Property::SetBoolProperty( std::string const& i_name, bool const& i_value )
    {
        return *this;
    }

    Property & Property::SetSection( std::string const& i_name )
    {
        return *this;
    }

    void Property::Print( int const& i_indent ) const
    {
        std::cout << std::string( i_indent*4, ' ' ) << m_name << std::endl;
        for ( auto const& property : m_section )
        {
            property.Print( i_indent+1 );
        }
    }
}
