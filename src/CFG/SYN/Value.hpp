/*
 * File:   Value.hpp
 * Author: JoPe
 *
 * Created on 5 de abril de 2014, 02:05
 */

#ifndef VALUE_HPP
#define	VALUE_HPP

#include <string>

namespace cfg
{
    namespace syn
    {
        class Value
        {
            public:
                enum Type
                {
                    e_Bool,
                    e_Int,
                    e_Float,
                    e_String
                };

            private:
                bool m_bool;
                int m_int;
                float m_float;
                std::string m_string;

                Type m_type;

            public:
                Value( bool const& i_bool );
                Value( int const& i_int );
                Value( float const& i_float );
                Value( std::string const& i_string );

                bool const& GetBool() const;
                int const& GetInt() const;
                float const& GetFloat() const;
                std::string const& GetString() const;
                Type const& GetType() const;
        };

    }
}

#endif	/* VALUE_HPP */

