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

void ReadBoolPropertyNoNewLine();
void ReadBoolPropertyNewLine();
void ReadIntPropertyNoNewLine();
void ReadIntPropertyNewLine();
void ReadFloatPropertyNoNewLine();
void ReadFloatPropertyNewLine();
void ReadStringPropertyNoNewLine();
void ReadStringPropertyNewLine();
void ReadSectionNoNewLine();
void ReadSectionNewLine();
void ReadGroupNoNewLine();
void ReadGroupNewLine();

void ReadBoolPropertyNoNewLine()
{
    cfg::Config const config ( "tests/BoolPropertyNN.conf" );
    if ( config.GetBoolProperty( "boolProperty" ) != false )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadBoolPropertyNoNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadBoolPropertyNewLine()
{
    cfg::Config const config ( "tests/BoolProperty.conf" );
    if ( config.GetBoolProperty( "boolProperty" ) != false )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadBoolPropertyNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadIntPropertyNoNewLine()
{
    cfg::Config const config ( "tests/IntPropertyNN.conf" );
    if ( config.GetIntProperty( "intProperty" ) != 1 )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadIntPropertyNoNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadIntPropertyNewLine()
{
    cfg::Config const config ( "tests/IntProperty.conf" );
    if ( config.GetIntProperty( "intProperty" ) != 1 )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadIntPropertyNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadFloatPropertyNoNewLine()
{
    cfg::Config const config ( "tests/FloatPropertyNN.conf" );
    if ( config.GetFloatProperty( "floatProperty" ) != 0.123f )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadFloatPropertyNoNewLine (ConfigTests) message=Float value read: " << config.GetFloatProperty( "floatProperty" ) << std::endl;
    }
}

void ReadFloatPropertyNewLine()
{
    cfg::Config const config ( "tests/FloatProperty.conf" );
    if ( config.GetFloatProperty( "floatProperty" ) != 0.123f )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadFloatPropertyNewLine (ConfigTests) message=Float value read: " << config.GetFloatProperty( "floatProperty" ) << std::endl;
    }
}

void ReadStringPropertyNoNewLine()
{
    cfg::Config const config ( "tests/StringPropertyNN.conf" );
    if ( config.GetStringProperty( "stringProperty" ) != "I am a string" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadStringPropertyNoNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadStringPropertyNewLine()
{
    cfg::Config const config ( "tests/StringProperty.conf" );
    if ( config.GetStringProperty( "stringProperty" ) != "I am a string" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadStringPropertyNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadSectionNoNewLine()
{
    cfg::Config const config ( "tests/SectionNN.conf" );

    if ( config.GetStringProperty( "Window::title" ) != "Pong" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadSectionNoNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadSectionNewLine()
{
    cfg::Config const config ( "tests/Section.conf" );

    if ( config.GetStringProperty( "Window::title" ) != "Pong" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadSectionNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadGroupNoNewLine()
{
    cfg::Config const config ( "tests/GroupNN.conf" );

    if ( config.GetStringProperty( "Config::Window::title" ) != "Pong" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadGroupNoNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

void ReadGroupNewLine()
{
    cfg::Config const config ( "tests/Group.conf" );

    if ( config.GetStringProperty( "Config::Window::title" ) != "Pong" )
    {
        std::cout << "%TEST_FAILED% time=0 testname=ReadGroupNewLine (ConfigTests) message=Could not read property." << std::endl;
    }
}

int main()
{
    std::cout << "%SUITE_STARTING% ConfigTests" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% ReadBoolPropertyNewLine (ConfigTests)" << std::endl;
    ReadBoolPropertyNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadBoolPropertyNewLine (ConfigTests)" << std::endl;
    std::cout << "%TEST_STARTED% ReadBoolPropertyNoNewLine (ConfigTests)" << std::endl;
    ReadBoolPropertyNoNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadBoolProperty (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadIntPropertyNewLine (ConfigTests)" << std::endl;
    ReadIntPropertyNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadIntPropertyNewLine (ConfigTests)" << std::endl;
    std::cout << "%TEST_STARTED% ReadIntPropertyNoNewLine (ConfigTests)" << std::endl;
    ReadIntPropertyNoNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadIntPropertyNoNewLine (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadFloatPropertyNewLine (ConfigTests)" << std::endl;
    ReadFloatPropertyNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadFloatPropertyNewLine (ConfigTests)" << std::endl;
    std::cout << "%TEST_STARTED% ReadFloatPropertyNoNewLine (ConfigTests)" << std::endl;
    ReadFloatPropertyNoNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadFloatPropertyNoNewLine (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadStringPropertyNewLine (ConfigTests)" << std::endl;
    ReadStringPropertyNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadStringPropertyNewLine (ConfigTests)" << std::endl;
    std::cout << "%TEST_STARTED% ReadStringPropertyNoNewLine (ConfigTests)" << std::endl;
    ReadStringPropertyNoNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadStringPropertyNoNewLine (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadSectionNewLine (ConfigTests)" << std::endl;
    ReadSectionNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadSectionNoNewLine (ConfigTests)" << std::endl;
    std::cout << "%TEST_STARTED% ReadSectionNoNewLine (ConfigTests)" << std::endl;
    ReadSectionNoNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadSectionNoNewLine (ConfigTests)" << std::endl;

    std::cout << "%TEST_STARTED% ReadGroupNewLine (ConfigTests)" << std::endl;
    ReadGroupNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadGroupNewLine (ConfigTests)" << std::endl;
    std::cout << "%TEST_STARTED% ReadGroupNoNewLine (ConfigTests)" << std::endl;
    ReadGroupNoNewLine();
    std::cout << "%TEST_FINISHED% time=0 ReadGroupNoNewLine (ConfigTests)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return 0;
}

