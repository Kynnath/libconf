/*
 * File:   SyntaxError.hpp
 * Author: JoPe
 *
 * Created on 6 de abril de 2014, 01:05
 */

#ifndef SYNTAXERROR_HPP
#define	SYNTAXERROR_HPP

#include <stdexcept>

namespace cfg
{
    namespace syn
    {
        class SyntaxError
            : public std::runtime_error
        {
            public:
                enum Type
                {
                    e_UnknownExpression,
                    e_ExpectedLineDelimiter,
                    e_ExpectedValue,
                    e_ExpectedAssignment,
                    e_IllformedScope,
                    e_ExpectedScopeRightDelimiter,
                    e_ExpectedName,
                    e_MismatchedBracers,
                    e_IllformedProperty
                };
            private:
                Type m_type;
                int m_row;
                int m_column;
            public:
                SyntaxError( Type const& i_errorType, int const& i_row, int const& i_column );
                int const& GetRow() const;
                int const& GetColumn() const;
        };
    }
}

#endif	/* SYNTAXERROR_HPP */

