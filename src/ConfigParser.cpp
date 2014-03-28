/*
 * File:   ConfigParser.cpp
 * Author: juan.garibotti
 *
 * Created on 27 de marzo de 2014, 17:11
 */

#include "ConfigParser.hpp"

#include <cassert>
#include <iostream>

namespace cfg
{
    extern char const k_reserved[][2];

    Property::Property( Type const& i_type )
        : m_type ( i_type )
    {}

    Assignment::Assignment( std::string const& i_name, std::string const& i_value )
        : Property ( Property::Assignment )
        , m_name ( i_name )
        , m_value ( i_value )
    {}

    void Assignment::Print( int const& i_indent ) const
    {
        std::cout << std::string( size_t( i_indent ), '\t' ) << m_name << " = " << m_value << std::endl;
    }

    Group::Group( std::string const& i_name )
        : Property ( Property::Group )
        , m_name ( i_name )
    {}

    void Group::Print( int const& i_indent ) const
    {}

    Assignment ReadAssignment( std::vector<std::string>::const_iterator & io_iter )
    {
        assert( *(io_iter+1) == "=" && *(io_iter+3) == "\n" );
        Assignment assignment ( *io_iter, *(io_iter+2) );
        io_iter += 4;
        return assignment;
    }

    Group ReadGroup( std::vector<std::string>::const_iterator & io_iter, std::vector<std::string>::const_iterator const& i_end )
    {
        assert( *(io_iter+2) == "]" && *(io_iter+3) == "\n" );

        Group group ( *(io_iter+1) );

        bool isScoped ( false );
        if ( *(io_iter+4) == "{" )
        {
            io_iter += 5;
            isScoped = true;
        }
        else
        {
            io_iter += 4;
        }

        while ( io_iter != i_end )
        {
            if ( *io_iter == "[" || *io_iter == "\n" || *io_iter == "}" )
            {
                if ( *io_iter == "\n" )
                {
                    ++io_iter;
                }
                else if ( *io_iter == "}" )
                {
                    ++io_iter;
                    break;
                }
                else if ( isScoped )
                {
                    group.m_lines.push_back( new Group( ReadGroup( io_iter, i_end ) ) );
                }
                else
                {
                    break;
                }
            }
            else
            {
                group.m_lines.push_back( new Assignment( ReadAssignment( io_iter ) ) );
            }
        }
        return group;
    }

    ConfigAST::ConfigAST( std::vector<std::string> const& i_tokens )
        : m_root ( "root" )
    {
        auto iter ( i_tokens.begin() );
        auto const end ( i_tokens.end() );
        while ( iter != end )
        {
            if ( *iter == "[" || *iter == "\n" )
            {
                if ( *iter == "\n" )
                {
                    ++iter;
                }
                else
                {
                    m_root.m_lines.push_back( new Group( ReadGroup( iter, end ) ) );
                }
            }
            else
            {
                m_root.m_lines.push_back( new Assignment( ReadAssignment( iter ) ) );
            }
        }
    }
}

