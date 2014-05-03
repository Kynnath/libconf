/*
 * File:   LexerTests.cpp
 * Author: JoPe
 *
 * Created on 02/05/2014, 17:48:05
 */

/*
 * Simple C++ Test Suite
 */

//#include <cstdlib>
#include <iostream>
#include <vector>
#include "CFG/LEX/Lexer.hpp"
#include "CFG/LEX/Token.hpp"

void LexFile();

void LexFile()
{
    std::cout << "LexerTests LexFile" << std::endl;
    std::vector<cfg::lex::Token> tokens ( cfg::lex::BuildTokenSequence( "tests/Section.conf" ) );
    if ( tokens.size() == 15 )
    {
        std::cout << "LexFile passed" << std::endl;
    }
    else
    {
        std::cout << "%TEST_FAILED% time=0 testname=LexFile (LexerTests) message=Wrong number of tokens read: " << tokens.size() <<  std::endl;
    }
}

/*void test2() {
    std::cout << "LexerTests test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (LexerTests) message=error message sample" << std::endl;
}*/

int main()
{
    std::cout << "%SUITE_STARTING% LexerTests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% LexFile (LexerTests)" << std::endl;
    LexFile();
    std::cout << "%TEST_FINISHED% time=0 LexFile (LexerTests)" << std::endl;

    /*std::cout << "%TEST_STARTED% test2 (LexerTests)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (LexerTests)" << std::endl;*/

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return 0;
}

