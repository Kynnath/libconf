/*
 * File:   ConfigError.hpp
 * Author: JoPe
 *
 * Created on 2 de mayo de 2014, 12:38
 */

#ifndef CONFIGERROR_HPP
#define	CONFIGERROR_HPP

#include <stdexcept>

namespace cfg
{
    class ConfigError
        : public std::runtime_error
    {
        public:
            enum Type
            {
                e_MissingProperty,
                e_TypeMismatch
            };

        private:
            Type m_type;
            
        public:
            ConfigError( Type const& i_type );
    };
}

#endif	/* CONFIGERROR_HPP */

