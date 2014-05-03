/*
 * File:   Semantic Tests.cpp
 * Author: JoPe
 *
 * Created on 02/05/2014, 17:49:30
 */

#include <stdlib.h>
#include <iostream>

/*
 * Simple C++ Test Suite
 */

/*void test1() {
    std::cout << "Semantic Tests test 1" << std::endl;
}

void test2() {
    std::cout << "Semantic Tests test 2" << std::endl;
    std::cout << "%TEST_FAILED% time=0 testname=test2 (Semantic Tests) message=error message sample" << std::endl;
}*/

int main()
{
    std::cout << "%SUITE_STARTING% Semantic Tests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    /*std::cout << "%TEST_STARTED% test1 (Semantic Tests)" << std::endl;
    test1();
    std::cout << "%TEST_FINISHED% time=0 test1 (Semantic Tests)" << std::endl;

    std::cout << "%TEST_STARTED% test2 (Semantic Tests)\n" << std::endl;
    test2();
    std::cout << "%TEST_FINISHED% time=0 test2 (Semantic Tests)" << std::endl;*/

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

