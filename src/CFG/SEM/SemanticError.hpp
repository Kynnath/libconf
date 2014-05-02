/*
 * File:   SemanticError.hpp
 * Author: JoPe
 *
 * Created on 1 de mayo de 2014, 20:25
 */

#ifndef SEMANTICERROR_HPP
#define	SEMANTICERROR_HPP

#include <string>
#include <stdexcept>

namespace cfg
{
    namespace sem
    {
        class SemanticError
            : public std::runtime_error
        {
            std::string m_name;

            public:
                SemanticError( std::string const& i_name );
        };
    }
}


#endif	/* SEMANTICERROR_HPP */

