/*
 * File:   SyntaxTests.cpp
 * Author: JoPe
 *
 * Created on 02/05/2014, 17:48:46
 */

//#include <cstdlib>
#include <iostream>
#include "CFG/SYN/Parser.hpp"
#include "CFG/LEX/Lexer.hpp"
/*
 * Simple C++ Test Suite
 */

/*void ParseSection()
{
    std::cout << "SyntaxTests ParseSection" << std::endl;
    std::vector< Expression > expressions ( cfg::syn::BuildSyntaxTree( cfg::lex::BuildTokenSequence( "tests/Section.conf" ) ) );
    if ( expressions.size() == 1 )
    {
        std::cout << "ParseSection passed" << std::endl;
    }
    else
    {
        std::cout << "%TEST_FAILED% time=0 testname=ParseSection (LexerTests) message=Could not parse section." <<  std::endl;
    }
}*/

/*void test2() {
    std::cout << "SyntaxTests test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (SyntaxTests) message=error message sample" << std::endl;
}*/

int main()
{
    std::cout << "%SUITE_STARTING% SyntaxTests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    /*std::cout << "%TEST_STARTED% ParseSection (SyntaxTests)" << std::endl;
    ParseSection();
    std::cout << "%TEST_FINISHED% time=0 ParseSection (SyntaxTests)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (SyntaxTests)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (SyntaxTests)" << std::endl;*/

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return 0;
}

