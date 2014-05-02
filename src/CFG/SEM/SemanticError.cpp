/*
 * File:   SemanticError.cpp
 * Author: JoPe
 *
 * Created on 1 de mayo de 2014, 20:25
 */

#include "SemanticError.hpp"

namespace cfg
{
    namespace sem
    {
        SemanticError::SemanticError( std::string const& i_name )
            : std::runtime_error ( "Name already defined in this scope" )
            , m_name ( i_name )
        {}
    }
}