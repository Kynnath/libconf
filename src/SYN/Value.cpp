/*
 * File:   Value.cpp
 * Author: JoPe
 *
 * Created on 5 de abril de 2014, 02:05
 */

#include "Value.hpp"

#include <cassert>

namespace cfg
{
    namespace syn
    {
        Value::Value( bool const& i_bool )
        : m_bool ( i_bool )
        , m_type ( e_Bool )
        {}

        Value::Value( int const& i_int )
        : m_int ( i_int )
        , m_type ( e_Int )
        {}

        Value::Value( float const& i_float )
        : m_float ( i_float )
        , m_type ( e_Float )
        {}

        Value::Value( std::string const& i_string )
        : m_string ( i_string )
        , m_type ( e_String )
        {}

        bool const& Value::GetBool() const
        {
            assert( m_type == e_Bool );
            return m_bool;
        }

        int const& Value::GetInt() const
        {
            assert( m_type == e_Int );
            return m_int;
        }

        float const& Value::GetFloat() const
        {
            assert( m_type == e_Float );
            return m_float;
        }

        std::string const& Value::GetString() const
        {
            assert( m_type == e_String );
            return m_string;
        }

        Value::Type const& Value::GetType() const
        {
            return m_type;
        }
    }
}