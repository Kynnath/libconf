/*
 * File:   ConfigParser.hpp
 * Author: juan.garibotti
 *
 * Created on 27 de marzo de 2014, 17:11
 */

#ifndef CONFIGPARSER_HPP
#define	CONFIGPARSER_HPP

#include <string>
#include <vector>

namespace cfg
{
    struct Property
    {
        enum Type
        {
            Assignment,
            Group
        };

        Type const m_type;

        Property( Type const& i_type );
        virtual void Print( int const& i_indent ) const = 0;
    };

    struct Assignment
        :public Property
    {
        std::string const m_name;
        std::string const m_value;

        Assignment( std::string const& i_name, std::string const& i_value );
        virtual void Print( int const& i_indent ) const;
    };

    struct Group
        :public Property
    {
        std::string const m_name;
        std::vector< Property* > m_lines;

        Group( std::string const& i_name );
        virtual void Print( int const& i_indent ) const;
    };

    struct ConfigAST
    {
        Group m_root;

        ConfigAST( std::vector<std::string> const& i_tokens );
        void Print() const;
    };
}
#endif	/* CONFIGPARSER_HPP */

