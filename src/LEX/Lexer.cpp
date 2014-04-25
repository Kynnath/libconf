/*
 * File:   Lexer.cpp
 * Author: JoPe
 *
 * Created on 29 de marzo de 2014, 01:23
 */

#include "Lexer.hpp"

#include <fstream>
#include <sstream>
#include "LexerError.hpp"
#include "Token.hpp"

namespace cfg
{
    namespace lex
    {
        struct LexerData;
        typedef void(*StateFunction)( LexerData& );

        // States
        void Initial( LexerData & io_lexerData );
        void FirstCharacter( LexerData & io_lexerData );
        void ReservedCharacter( LexerData & io_lexerData );
        void NegativeNumber( LexerData & io_lexerData );
        void Number( LexerData & io_lexerData );
        void Name( LexerData & io_lexerData );
        void String( LexerData & io_lexerData );
        void Comment( LexerData & io_lexerData );
        void Decimal( LexerData & io_lexerData );
        void Escaped( LexerData & io_lexerData );

        struct LexerData
        {
            std::ifstream m_configFile;
            int m_row, m_rowFirst;
            int m_column, m_columnFirst;
            std::vector<Token> m_tokenSequence;
            char m_character;
            std::string m_characterSequence;
            StateFunction m_currentState;

            LexerData( std::string const& i_configFile );
        };

        LexerData::LexerData( std::string const& i_configFile )
            : m_configFile ( i_configFile )
            , m_row ( 1 ), m_rowFirst ( 1 )
            , m_column ( 0 ), m_columnFirst ( 0 )
            , m_currentState ( Initial )
        {}

        char const k_reserved[] =
        {
            ';',
            '[',
            ']',
            '{',
            '}',
            '=',
            '\"',
            '\n'
        };

        char const k_decimal = '.';
        char const k_underscore = '_';
        char const k_minus = '-';
        char const k_escape = '\\';

        char const k_keyword[][6] =
        {
            "true",
            "false"
        };

        struct Reserved
        {
            enum
            {
                Comment = 0,
                ScopeLeftDelimiter,
                ScopeRightDelimiter,
                ScopeTopDelimiter,
                ScopeBottomDelimiter,
                Assignment,
                Quote,
                LineDelimeter
            };
        };

        struct Keyword
        {
            enum
            {
                True,
                False
            };
        };

        bool IsReserved( char const& i_character );
        bool IsReserved( char const& i_character )
        {
            for ( std::size_t index ( 0 ); index < sizeof( k_reserved ); ++index )
            {
                if ( i_character == k_reserved[ index ] )
                {
                    return true;
                }
            }
            return false;
        }

        void Initial( LexerData & io_lexerData )
        {
            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_column += 1;
                io_lexerData.m_currentState = FirstCharacter;
            }
            else
            {
                io_lexerData.m_currentState = nullptr;
            }
        }

        void FirstCharacter( LexerData & io_lexerData )
        {
            io_lexerData.m_characterSequence.clear();
            io_lexerData.m_rowFirst = io_lexerData.m_row;
            io_lexerData.m_columnFirst = io_lexerData.m_column;

            if ( std::isblank( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = Initial;
            }
            else if ( IsReserved( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = ReservedCharacter;
            }
            else if ( io_lexerData.m_character == k_minus )
            {
                io_lexerData.m_currentState = NegativeNumber;
            }
            else if ( std::isdigit( io_lexerData.m_character ) )
            {
                io_lexerData.m_currentState = Number;
            }
            else if ( std::isalpha( io_lexerData.m_character ) || io_lexerData.m_character == k_underscore )
            {
                io_lexerData.m_currentState = Name;
            }
            else
            {
                throw LexerError( LexerError::e_IllegalFirstCharacter, io_lexerData.m_row, io_lexerData.m_column );
            }
        }

        void ReservedCharacter( LexerData & io_lexerData )
        {
            if ( io_lexerData.m_character == k_reserved[ Reserved::Quote ] )
            {
                io_lexerData.m_currentState = String;
            }
            else if ( io_lexerData.m_character == k_reserved[ Reserved::Comment ] )
            {
                io_lexerData.m_currentState = Comment;
            }
            else
            {
                if ( io_lexerData.m_character == k_reserved[ Reserved::LineDelimeter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::e_LineDelimiter ) );

                    io_lexerData.m_column = 0;
                    io_lexerData.m_row += 1;
                }
                if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeLeftDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::e_ScopeLeftDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeRightDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::e_ScopeRightDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeTopDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::e_ScopeTopDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::ScopeBottomDelimiter ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::e_ScopeBottomDelimiter ) );
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::Assignment ] )
                {
                    io_lexerData.m_tokenSequence.push_back( Token( io_lexerData.m_rowFirst, io_lexerData.m_columnFirst, Token::e_Assignment ) );
                }

                io_lexerData.m_currentState = Initial;
            }
        }

        void NegativeNumber( LexerData & io_lexerData )
        {
            io_lexerData.m_characterSequence += io_lexerData.m_character;

            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_column += 1;

                if ( std::isdigit( io_lexerData.m_character ) )
                {
                    io_lexerData.m_currentState = Number;
                }
                else
                {
                    throw LexerError( LexerError::e_MisformedNumber, io_lexerData.m_row, io_lexerData.m_column );
                }
            }
            else
            {
                throw LexerError( LexerError::e_MisformedNumber, io_lexerData.m_row, io_lexerData.m_column );
            }
        }

        void AddNumberToken( int const& i_row, int const& i_column, std::string const& i_number, std::vector<Token> & io_tokens );
        void AddNumberToken( int const& i_row, int const& i_column, std::string const& i_number, std::vector<Token> & io_tokens )
        {
            std::stringstream numberStream ( i_number );
            int number;
            numberStream >> number;
            io_tokens.push_back( Token( i_row, i_column, number ) );
        }

        void Number( LexerData & io_lexerData )
        {
            io_lexerData.m_characterSequence += io_lexerData.m_character;

            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_column += 1;

                if ( !std::isdigit( io_lexerData.m_character ) )
                {
                    if ( io_lexerData.m_character == k_decimal )
                    {
                        io_lexerData.m_currentState = Decimal;
                    }
                    else if ( std::isblank( io_lexerData.m_character ) )
                    {
                        AddNumberToken( io_lexerData.m_rowFirst,
                                        io_lexerData.m_columnFirst,
                                        io_lexerData.m_characterSequence,
                                        io_lexerData.m_tokenSequence );

                        io_lexerData.m_currentState = Initial;
                    }
                    else if ( IsReserved( io_lexerData.m_character ) )
                    {
                        AddNumberToken( io_lexerData.m_rowFirst,
                                        io_lexerData.m_columnFirst,
                                        io_lexerData.m_characterSequence,
                                        io_lexerData.m_tokenSequence );

                        io_lexerData.m_currentState = FirstCharacter;
                    }
                    else
                    {
                        throw LexerError( LexerError::e_MisformedNumber, io_lexerData.m_row, io_lexerData.m_column );
                    }
                }
            }
            else
            {
                AddNumberToken( io_lexerData.m_rowFirst,
                                io_lexerData.m_columnFirst,
                                io_lexerData.m_characterSequence,
                                io_lexerData.m_tokenSequence );

                io_lexerData.m_currentState = nullptr;
            }
        }

        void AddNameToken( int const& i_row, int const& i_column, std::string const& i_name, std::vector<Token> & io_tokens );
        void AddNameToken( int const& i_row, int const& i_column, std::string const& i_name, std::vector<Token> & io_tokens )
        {
            // Check if we are storing a reserved word
            // Reserved words: true, false
            if ( i_name == k_keyword[ Keyword::True ] )
            {
                io_tokens.push_back( Token( i_row, i_column, true ) );
            }
            else if ( i_name == k_keyword[ Keyword::False ] )
            {
                io_tokens.push_back( Token( i_row, i_column, false ) );
            }
            else
            {
                io_tokens.push_back( Token( i_row, i_column, Token::e_Name, i_name ) );
            }
        }

        void Name( LexerData & io_lexerData )
        {
            io_lexerData.m_characterSequence += io_lexerData.m_character;

            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_column += 1;

                if ( std::isblank( io_lexerData.m_character ) )
                {
                    AddNameToken( io_lexerData.m_rowFirst,
                                  io_lexerData.m_columnFirst,
                                  io_lexerData.m_characterSequence,
                                  io_lexerData.m_tokenSequence );

                    io_lexerData.m_currentState = Initial;
                }
                else if ( IsReserved( io_lexerData.m_character ) )
                {
                    AddNameToken( io_lexerData.m_rowFirst,
                                  io_lexerData.m_columnFirst,
                                  io_lexerData.m_characterSequence,
                                  io_lexerData.m_tokenSequence );

                    io_lexerData.m_currentState = FirstCharacter;
                }
                else if ( !std::isalpha( io_lexerData.m_character ) &&
                          !io_lexerData.m_character == k_underscore &&
                          !std::isdigit( io_lexerData.m_character ) )
                {
                    throw LexerError( LexerError::e_IllegalName, io_lexerData.m_row, io_lexerData.m_column );
                }
            }
            else
            {
                AddNameToken( io_lexerData.m_rowFirst,
                              io_lexerData.m_columnFirst,
                              io_lexerData.m_characterSequence,
                              io_lexerData.m_tokenSequence );

                io_lexerData.m_currentState = nullptr;
            }
        }

        void AddStringToken( int const& i_row, int const& i_column, std::string const& i_string, std::vector<Token> & io_tokens );
        void AddStringToken( int const& i_row, int const& i_column, std::string const& i_string, std::vector<Token> & io_tokens )
        {
            io_tokens.push_back( Token( i_row, i_column, Token::e_String, i_string ) );
        }

        void String( LexerData & io_lexerData )
        {
            // Should eventually be a utf8 aware function
            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_column += 1;

                if ( io_lexerData.m_character == k_escape )
                {
                    io_lexerData.m_currentState = Escaped;
                }
                else if ( io_lexerData.m_character == k_reserved[ Reserved::Quote ] )
                {
                    AddStringToken( io_lexerData.m_rowFirst,
                                    io_lexerData.m_columnFirst,
                                    io_lexerData.m_characterSequence,
                                    io_lexerData.m_tokenSequence );

                    io_lexerData.m_currentState = Initial;
                }
                else
                {
                    if ( io_lexerData.m_character == k_reserved[ Reserved::LineDelimeter ] )
                    {
                        io_lexerData.m_column = 0;
                        io_lexerData.m_row += 1;
                    }

                    io_lexerData.m_characterSequence += io_lexerData.m_character; // Needs to be a utf8 aware function later
                }
            }
            else
            {
                throw LexerError( LexerError::e_MissingQuote, io_lexerData.m_row, io_lexerData.m_column );
            }
        }

        void AddCommentToken( int const& i_row, int const& i_column, std::string const& i_comment, std::vector<Token> & io_tokens );
        void AddCommentToken( int const& i_row, int const& i_column, std::string const& i_comment, std::vector<Token> & io_tokens )
        {
            io_tokens.push_back( Token( i_row, i_column, Token::e_Comment, i_comment ) );
        }

        void Comment( LexerData & io_lexerData )
        {
            // Should eventually be a utf8 aware function
            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_row += 1;

                if ( io_lexerData.m_character == k_reserved[ Reserved::LineDelimeter ] )
                {
                    AddCommentToken( io_lexerData.m_rowFirst,
                                     io_lexerData.m_columnFirst,
                                     io_lexerData.m_characterSequence,
                                     io_lexerData.m_tokenSequence );

                    io_lexerData.m_column = 0;
                    io_lexerData.m_row += 1;

                    io_lexerData.m_currentState = Initial;
                }
                else
                {
                    io_lexerData.m_characterSequence += io_lexerData.m_character; // Needs to be a utf8 aware function later
                }
            }
            else
            {
                io_lexerData.m_currentState = nullptr;
            }
        }

        void AddDecimalToken( int const& i_row, int const& i_column, std::string const& i_decimal, std::vector<Token> & io_tokens );
        void AddDecimalToken( int const& i_row, int const& i_column, std::string const& i_decimal, std::vector<Token> & io_tokens )
        {
            std::stringstream numberStream ( i_decimal );
            float decimal;
            numberStream >> decimal;
            io_tokens.push_back( Token( i_row, i_column, decimal ) );
        }

        void Decimal( LexerData & io_lexerData )
        {
            io_lexerData.m_characterSequence += io_lexerData.m_character;

            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_column += 1;

                if ( !std::isdigit( io_lexerData.m_character ) )
                {
                    if ( std::isblank( io_lexerData.m_character ) )
                    {
                        AddDecimalToken( io_lexerData.m_rowFirst,
                                         io_lexerData.m_columnFirst,
                                         io_lexerData.m_characterSequence,
                                         io_lexerData.m_tokenSequence );

                        io_lexerData.m_currentState = Initial;
                    }
                    else if ( IsReserved( io_lexerData.m_character ) )
                    {
                        AddDecimalToken( io_lexerData.m_rowFirst,
                                         io_lexerData.m_columnFirst,
                                         io_lexerData.m_characterSequence,
                                         io_lexerData.m_tokenSequence );

                        io_lexerData.m_currentState = FirstCharacter;
                    }
                    else
                    {
                        throw LexerError( LexerError::e_MisformedNumber, io_lexerData.m_row, io_lexerData.m_column );
                    }
                }
            }
            else
            {
                AddDecimalToken( io_lexerData.m_rowFirst,
                                 io_lexerData.m_columnFirst,
                                 io_lexerData.m_characterSequence,
                                 io_lexerData.m_tokenSequence );

                io_lexerData.m_currentState = nullptr;
            }
        }

        void Escaped( LexerData & io_lexerData )
        {
            if ( io_lexerData.m_configFile.get( io_lexerData.m_character ) )
            {
                io_lexerData.m_column += 1;

                if ( io_lexerData.m_character == k_reserved[ Reserved::Quote ] ||
                     io_lexerData.m_character == k_escape )
                {
                    io_lexerData.m_characterSequence += io_lexerData.m_character;

                    io_lexerData.m_currentState = String;
                }
                else
                {
                    throw LexerError( LexerError::e_IllegalEscape, io_lexerData.m_row, io_lexerData.m_column );
                }
            }
            else
            {
                throw LexerError( LexerError::e_IllegalEscape, io_lexerData.m_row, io_lexerData.m_column );
            }
        }

        std::vector<Token> BuildTokenSequence( std::string const& i_configFile )
        {
            LexerData data ( i_configFile );

            while ( data.m_currentState )
            {
                data.m_currentState( data );
            }

            return data.m_tokenSequence;
        }
    }
}

