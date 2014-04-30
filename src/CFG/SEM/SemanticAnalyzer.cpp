/*
 * File:   SemanticAnalyzer.cpp
 * Author: juan.garibotti
 *
 * Created on 28 de abril de 2014, 16:48
 */

#include "SemanticAnalyzer.hpp"

#include <exception>
#include <utility>
#include "CFG/SYN/Expression.hpp"
#include "CFG/SYN/Value.hpp"

namespace cfg
{
    namespace sem
    {
        struct SemanticData;
        void ReadScope( SemanticData & io_data, std::vector<syn::Expression>::const_iterator c_current, std::vector<syn::Expression>::const_iterator const& i_end );
        std::string QualifyPropertyName( std::vector<std::string> const& i_scopeStack, std::string const& i_propertyName );

        struct SemanticData
        {
            std::map< std::string, syn::Value > m_symbolTable;
            std::vector< std::string > m_scopeStack;
        };

        std::map< std::string, syn::Value > BuildSymbolTable( std::vector< syn::Expression > const& i_syntaxTree )
        {
            SemanticData semanticData;

            ReadScope( semanticData, i_syntaxTree.begin(), i_syntaxTree.end() );

            return semanticData.m_symbolTable;
        }

        void ReadScope( SemanticData & io_data, std::vector<syn::Expression>::const_iterator c_current, std::vector<syn::Expression>::const_iterator const& i_end )
        {
            while ( c_current != i_end )
            {
                if ( c_current->GetType() == syn::Expression::e_Property )
                {
                    bool success ( io_data.m_symbolTable.insert( std::make_pair( QualifyPropertyName( io_data.m_scopeStack, c_current->GetProperty().GetName() ),
                                                                                 c_current->GetProperty().GetValue() ) ).second );
                    if ( !success )
                    {
                        throw std::exception(); // SemanticError: symbol already defined
                    }
                }
                else
                {
                    io_data.m_scopeStack.push_back( c_current->GetScope().GetName() );
                    ReadScope( io_data, c_current->GetScope().GetExpressions().begin(), c_current->GetScope().GetExpressions().end());
                }
                ++c_current;
            }
            if ( !io_data.m_scopeStack.empty() )
            {
                io_data.m_scopeStack.pop_back();
            }
        }

        std::string QualifyPropertyName( std::vector<std::string> const& i_scopeStack, std::string const& i_propertyName )
        {
            std::string qualifiedName;

            for ( auto const& scope : i_scopeStack )
            {
                qualifiedName += scope;
                qualifiedName += "::";
            }

            qualifiedName += i_propertyName;

            return qualifiedName;
        }
    }
}