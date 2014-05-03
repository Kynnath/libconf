/*
 * File:   ConfigTests.cpp
 * Author: JoPe
 *
 * Created on 02/05/2014, 18:56:33
 */

/*
 * Simple C++ Test Suite
 */

#include <iostream>
#include "CFG/Config.hpp"

void ReadBoolProperty();
void ReadIntProperty();
void ReadFloatProperty();
void ReadStringProperty();
void ReadSection();

void ReadBoolProperty()
{
    cfg::Config const config ( "tests/BoolProperty.conf" );
    if ( config.GetBoolProperty( "boolProperty" ) != false )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadBoolProperty (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadIntProperty()
{
    cfg::Config const config ( "tests/IntProperty.conf" );
    if ( config.GetIntProperty( "intProperty" ) != 1 )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadIntProperty (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadFloatProperty()
{
    cfg::Config const config ( "tests/FloatProperty.conf" );
    if ( config.GetFloatProperty( "floatProperty" ) != 0.123f )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadFloatProperty (ConfigTests) message=Float value read: " << config.GetFloatProperty( "floatProperty" ) << std::endl;
    }
}

void ReadStringProperty()
{
    cfg::Config const config ( "tests/StringProperty.conf" );
    if ( config.GetStringProperty( "stringProperty" ) != "I am a string" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadStringProperty (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadSection()
{
    cfg::Config const config ( "tests/Section.conf" );

    if ( config.GetStringProperty( "Window::title" ) != "Pong" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadStringProperty (ConfigTests) message=Could not read property." << std::endl;
    }
}

int main()
{
    std::cout << "%SUITE_STARTING% ConfigTests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% ReadBoolProperty (ConfigTests)" << std::endl;
    ReadBoolProperty();
    std::cout << "%TEST_FINISHED% time=0 ReadBoolProperty (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadIntProperty (ConfigTests)" << std::endl;
    ReadIntProperty();
    std::cout << "%TEST_FINISHED% time=0 ReadIntProperty (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadFloatProperty (ConfigTests)" << std::endl;
    ReadFloatProperty();
    std::cout << "%TEST_FINISHED% time=0 ReadFloatProperty (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadStringProperty (ConfigTests)" << std::endl;
    ReadStringProperty();
    std::cout << "%TEST_FINISHED% time=0 ReadStringProperty (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadSection (ConfigTests)" << std::endl;
    ReadSection();
    std::cout << "%TEST_FINISHED% time=0 ReadSection (ConfigTests)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return 0;
}

