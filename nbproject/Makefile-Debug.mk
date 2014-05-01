#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/CFG/Config.o \
	${OBJECTDIR}/src/CFG/LEX/Lexer.o \
	${OBJECTDIR}/src/CFG/LEX/LexerError.o \
	${OBJECTDIR}/src/CFG/LEX/Token.o \
	${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o \
	${OBJECTDIR}/src/CFG/SYN/Expression.o \
	${OBJECTDIR}/src/CFG/SYN/Parser.o \
	${OBJECTDIR}/src/CFG/SYN/Property.o \
	${OBJECTDIR}/src/CFG/SYN/Scope.o \
	${OBJECTDIR}/src/CFG/SYN/SyntaxError.o \
	${OBJECTDIR}/src/CFG/Value.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector
CXXFLAGS=-Wfatal-errors -Wall -Wextra -pedantic -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wfloat-equal -Wshadow -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Wsign-conversion -Wlogical-op -Wmissing-declarations -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wvolatile-register-var -Wdisabled-optimization -Wstack-protector

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibconf.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibconf.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibconf.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibconf.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibconf.a

${OBJECTDIR}/src/CFG/Config.o: src/CFG/Config.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/Config.o src/CFG/Config.cpp

${OBJECTDIR}/src/CFG/LEX/Lexer.o: src/CFG/LEX/Lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/Lexer.o src/CFG/LEX/Lexer.cpp

${OBJECTDIR}/src/CFG/LEX/LexerError.o: src/CFG/LEX/LexerError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/LexerError.o src/CFG/LEX/LexerError.cpp

${OBJECTDIR}/src/CFG/LEX/Token.o: src/CFG/LEX/Token.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/Token.o src/CFG/LEX/Token.cpp

${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o: src/CFG/SEM/SemanticAnalyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SEM
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o src/CFG/SEM/SemanticAnalyzer.cpp

${OBJECTDIR}/src/CFG/SYN/Expression.o: src/CFG/SYN/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Expression.o src/CFG/SYN/Expression.cpp

${OBJECTDIR}/src/CFG/SYN/Parser.o: src/CFG/SYN/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Parser.o src/CFG/SYN/Parser.cpp

${OBJECTDIR}/src/CFG/SYN/Property.o: src/CFG/SYN/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Property.o src/CFG/SYN/Property.cpp

${OBJECTDIR}/src/CFG/SYN/Scope.o: src/CFG/SYN/Scope.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Scope.o src/CFG/SYN/Scope.cpp

${OBJECTDIR}/src/CFG/SYN/SyntaxError.o: src/CFG/SYN/SyntaxError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/SyntaxError.o src/CFG/SYN/SyntaxError.cpp

${OBJECTDIR}/src/CFG/Value.o: src/CFG/Value.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	${RM} "$@.d"
	$(COMPILE.cc) -g -Wall -Isrc -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/Value.o src/CFG/Value.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibconf.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
