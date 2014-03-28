/*
 * File:   Property.cpp
 * Author: juan.garibotti
 *
 * Created on 18 de marzo de 2014, 17:22
 */

#include "Property.hpp"

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "ConfigParser.hpp"

namespace cfg
{
    char const k_reserved[][2] =
    {
        ";",
        "[",
        "]",
        "{",
        "}",
        "=",
        ":",
        "\"",
        "\n",
        "\\"
    };

    char const k_reservedValue[][6] =
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
        Scope,
        Quote,
        Newline,
        Escape
    };

    enum ReservedValue
    {
        True,
        False
    };

    typedef std::vector< std::string > TokenList;

    bool LineIsAssignment( TokenList const& i_line );
    bool LineIsAssignment( TokenList const& i_line )
    {
        for ( auto const& token : i_line )
        {
            if ( token.find( k_reserved[ Assignment ] ) != std::string::npos )
            {
                return true;
            }
        }
        return false;
    }

    bool IsInteger( std::string const& i_string );
    bool IsInteger( std::string const& i_string )
    {
        if ( !i_string.empty() )
        {
            auto iter ( i_string.begin() );
            if ( *iter == '-' || ( *iter > '0' && *iter < '9' ) )
            {
                auto const end ( i_string.end() );
                ++iter;
                while ( iter != end )
                {
                    if ( *iter < '0' || *iter > '9' )
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }

    bool IsFloat( std::string const& i_string );
    /*
     * Function will detect floating point numbers of the form [-]1.234
     * There has to be a digit before the decimal point, and there may be a
     * minus sign.
     */
    bool IsFloat( std::string const& i_string )
    {
        if ( !i_string.empty() )
        {
            auto iter ( i_string.begin() );
            if ( *iter == '-' )
            {
                ++iter;
            }
            if ( *iter > '0' && *iter < '9' )
            {
                ++iter;
            }
            else
            {
                return false;
            }
            auto const end ( i_string.end() );
            if ( std::count( iter, end, '.' ) != 1 )
            {
                return false;
            }
            while ( iter != end )
            {
                if ( *iter < '0' && *iter > '9' )
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    Config::Type AssignmentType( TokenList const& i_line );
    Config::Type AssignmentType( TokenList const& i_line )
    {
        if ( i_line.back() == "true" || i_line.back() == "false" )
        {
            return Config::Bool;
        }
        else if ( IsInteger( i_line.back() ) )
        {
            return Config::Int;
        }
        else if ( IsFloat( i_line.back() ) )
        {
            return Config::Float;
        }
        else
        {
            return Config::String;
        }
    }

    std::string PropertyName( TokenList const& i_line );
    std::string PropertyName( TokenList const& i_line )
    {
        return i_line.front().substr( 0, i_line.front().find( k_reserved[ Assignment ] ) );
    }

    std::string PropertyValue( TokenList const& i_line );
    std::string PropertyValue( TokenList const& i_line )
    {
        std::string::size_type assignmentPos ( i_line.back().find( k_reserved[ Assignment ] ) );
        if ( assignmentPos == std::string::npos )
        {
            return i_line.back();
        }
        else
        {
            return i_line.back().substr( assignmentPos+1 );
        }
    }

    TokenList SplitPropertyName( std::string const& i_name );
    TokenList SplitPropertyName( std::string const& i_name )
    {
        TokenList propertyName;
        std::string::size_type from ( 0 );
        std::string::size_type to ( 0 );

        while ( to != std::string::npos )
        {
            to = i_name.find( k_reserved[ Scope ], from );
            propertyName.push_back( i_name.substr( from, to - from ) );
            from = to + 1;
        }

        return propertyName;
    }

    bool IsReserved( char const& i_character );
    bool IsReserved( char const& i_character )
    {
        for ( std::size_t index ( 0 ); index < sizeof( k_reserved )/2; ++index )
        {
            if ( i_character == k_reserved[index][0] )
            {
                return true;
            }
        }
        return false;
    }

    bool IsReserved( std::string const& i_token );
    bool IsReserved( std::string const& i_token )
    {
        for ( std::size_t index ( 0 ); index < sizeof( k_reserved )/2; ++index )
        {
            if ( i_token == k_reserved[index] )
            {
                return true;
            }
        }
        return false;
    }

    std::vector< std::string > TokenizeFile( std::string const& i_filename );
    std::vector< std::string > TokenizeFile( std::string const& i_filename )
    {
        std::ifstream configFile ( i_filename );

        char character;
        bool isString (false);
        bool isEscaped (false);
        std::string currentToken;
        std::vector< std::string > tokens;
        while ( configFile.get( character ) )
        {
            if ( isString )
            {
                if ( isEscaped )
                {
                    isEscaped = false;
                    currentToken += character;
                }
                else
                {
                    if ( character == k_reserved[ Escape ][0] )
                    {
                        isEscaped = true;
                    }
                    else if ( character == k_reserved[ Quote ][0] )
                    {
                        isString = false;
                        currentToken += character;
                        tokens.push_back( currentToken );
                        currentToken.clear();

                    }
                    else
                    {
                        currentToken += character;
                    }
                }
            }
            else
            {
                if ( IsReserved( character ) )
                {
                    if ( character == k_reserved[ Quote ][0] )
                    {
                        isString = true;
                        if ( !currentToken.empty() )
                        {
                            tokens.push_back( currentToken );
                            currentToken.clear();
                        }
                        currentToken += character;
                    }
                    else
                    {
                        if ( !currentToken.empty() )
                        {
                            tokens.push_back( currentToken );
                            currentToken.clear();
                        }
                        currentToken += character;
                        tokens.push_back( currentToken );
                        currentToken.clear();
                    }
                }
                else if ( std::isblank( character ) )
                {
                    if ( !currentToken.empty() )
                    {
                        tokens.push_back( currentToken );
                        currentToken.clear();
                    }
                }
                else //any other characters are not blank or reserved
                {
                    currentToken += character;
                }
            }
        }
        // in case file ends on a regular character
        if ( !currentToken.empty() )
        {
            tokens.push_back( currentToken );
        }

        return tokens;
    }

    Config::Config( std::string const& i_filename )
        : m_type ( Config::File )
        , m_name ( i_filename )
        , m_string ()
        , m_int ()
        , m_float ()
        , m_bool ()
        , m_section ()
    {
        // Lexical Analysis
        std::vector< std::string > tokens ( TokenizeFile( i_filename ) );

        // Syntactic Analysis
        ConfigAST syntaxTree ( tokens );
        syntaxTree.Print();

        // Semantic Analysis


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
        std::vector<Config*> stack;
        stack.push_back( this );
        bool withinScope ( true );
        // For each line, determine if each line is a property or section
        for ( auto const& line : lineTokens )
        {
            if ( line.front().find( k_reserved[ SectionStart ] ) == 0 )
            {
                // New section
                assert( line.front().find( k_reserved[ SectionEnd ] ) == line.front().size()-1 )  ;
                if ( !withinScope )
                {
                    stack.pop_back();
                }
                stack.back()->m_section.push_back( Config( line.front().substr( 1, line.front().size()-2 ), std::vector<Config>() ) );
                stack.push_back( &( stack.back()->m_section.back() ) );
                withinScope = false;
            }
            else if ( line.front() == k_reserved[ GroupStart ] )
            {
                withinScope = true;
            }
            else if ( line.front() == k_reserved[ GroupEnd ] )
            {
                stack.pop_back();
                withinScope = true;
            }
            else if ( LineIsAssignment( line ) )
            {
                Config::Type type ( AssignmentType( line ) );
                if ( type == Config::Int )
                {
                    stack.back()->m_section.push_back( Config( PropertyName( line ), std::stoi( PropertyValue( line ) ) ) );
                }
                else if ( type == Config::Float )
                {
                    stack.back()->m_section.push_back( Config( PropertyName( line ), std::stof( PropertyValue( line ) ) ) );
                }
                else if ( type == Config::Bool )
                {
                    stack.back()->m_section.push_back( Config( PropertyName( line ), PropertyValue( line ) == "true" ) );
                }
                else
                {
                    stack.back()->m_section.push_back( Config( PropertyName( line ), PropertyValue( line ) ) );
                }
            }
            else if ( line.front().substr( 0, 1 ) == k_reserved[ Comment ] )
            {
                continue;
            }
        }
    }

    Config::Config( std::string const& i_name, std::string const& i_value )
        : m_type ( Config::String )
        , m_name ( i_name )
        , m_string ( i_value )
        , m_int ()
        , m_float ()
        , m_bool ()
        , m_section (){}

    Config::Config( std::string const& i_name, int const& i_value )
        : m_type ( Config::Int )
        , m_name ( i_name )
        , m_string ()
        , m_int ( i_value )
        , m_float ()
        , m_bool ()
        , m_section (){}

    Config::Config( std::string const& i_name, float const& i_value )
        : m_type ( Config::Float )
        , m_name ( i_name )
        , m_string ()
        , m_int ()
        , m_float ( i_value )
        , m_bool ()
        , m_section (){}

    Config::Config( std::string const& i_name, bool const& i_value )
        : m_type ( Config::Bool )
        , m_name ( i_name )
        , m_string ()
        , m_int ()
        , m_float ()
        , m_bool ( i_value)
        , m_section (){}

    Config::Config( std::string const& i_name, std::vector<Config> const& i_value )
        : m_type ( Config::Section )
        , m_name ( i_name )
        , m_string ()
        , m_int ()
        , m_float ()
        , m_bool ()
        , m_section ( i_value ){}

    Config const& Config::GetProperty( std::string const& i_name ) const
    {
        TokenList propertyName( SplitPropertyName( i_name ) );

        Config const* currentProp ( this );
        for ( auto const& name : propertyName )
        {
            for( auto const& property : currentProp->m_section )
            {
                if ( name == property.m_name )
                {
                    currentProp = &property;
                    break;
                }
            }
        }
        return *currentProp;
    }

    std::string const& Config::GetStringProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_string;
    }

    int const& Config::GetIntProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_int;
    }

    float const& Config::GetFloatProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_float;
    }

    bool const& Config::GetBoolProperty( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_bool;
    }

    std::vector<Config> const& Config::GetSection( std::string const& i_name ) const
    {
        return GetProperty( i_name ).m_section;
    }

    Config & Config::SetStringProperty( std::string const& i_name, std::string const& i_value )
    {
        if ( i_name == i_value )
            return *this;
        else
            return *this;
    }

    Config & Config::SetIntProperty( std::string const& i_name, int const& i_value )
    {
        if ( int(i_name.size()) == i_value )
            return *this;
        else
            return *this;
    }

    Config & Config::SetFloatProperty( std::string const& i_name, float const& i_value )
    {
        if ( i_name.size() > i_value )
            return *this;
        else
            return *this;
    }

    Config & Config::SetBoolProperty( std::string const& i_name, bool const& i_value )
    {
        if ( i_name.empty() == i_value )
            return *this;
        else
            return *this;
    }

    Config & Config::SetSection( std::string const& i_name )
    {
        if ( i_name.empty() )
            return *this;
        else
            return *this;
    }

    void Config::Print( int const& i_indent ) const
    {
        std::cout << std::string( std::string::size_type( i_indent*4 ), ' ' ) << m_name;
        if ( m_type == Config::Int )
        {
            std::cout << " = " << m_int;
        }
        if ( m_type == Config::Float )
        {
            std::cout << " = " << m_float;
        }
        if ( m_type == Config::Bool )
        {
            std::cout << " = " << m_bool;
        }
        if ( m_type == Config::String )
        {
            std::cout << " = " << m_string;
        }
        std::cout << std::endl;
        for ( auto const& property : m_section )
        {
            property.Print( i_indent+1 );
        }
    }
}
