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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/ConfigParser.o \
	${OBJECTDIR}/src/LEX/Lexer.o \
	${OBJECTDIR}/src/LEX/LexerError.o \
	${OBJECTDIR}/src/LEX/Token.o \
	${OBJECTDIR}/src/Property.o \
	${OBJECTDIR}/src/SYN/Expression.o \
	${OBJECTDIR}/src/SYN/Parser.o \
	${OBJECTDIR}/src/SYN/Property.o \
	${OBJECTDIR}/src/SYN/Scope.o \
	${OBJECTDIR}/src/SYN/SyntaxError.o \
	${OBJECTDIR}/src/SYN/Value.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

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

${OBJECTDIR}/src/ConfigParser.o: src/ConfigParser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ConfigParser.o src/ConfigParser.cpp

${OBJECTDIR}/src/LEX/Lexer.o: src/LEX/Lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LEX/Lexer.o src/LEX/Lexer.cpp

${OBJECTDIR}/src/LEX/LexerError.o: src/LEX/LexerError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LEX/LexerError.o src/LEX/LexerError.cpp

${OBJECTDIR}/src/LEX/Token.o: src/LEX/Token.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/LEX/Token.o src/LEX/Token.cpp

${OBJECTDIR}/src/Property.o: src/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Property.o src/Property.cpp

${OBJECTDIR}/src/SYN/Expression.o: src/SYN/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SYN/Expression.o src/SYN/Expression.cpp

${OBJECTDIR}/src/SYN/Parser.o: src/SYN/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SYN/Parser.o src/SYN/Parser.cpp

${OBJECTDIR}/src/SYN/Property.o: src/SYN/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SYN/Property.o src/SYN/Property.cpp

${OBJECTDIR}/src/SYN/Scope.o: src/SYN/Scope.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SYN/Scope.o src/SYN/Scope.cpp

${OBJECTDIR}/src/SYN/SyntaxError.o: src/SYN/SyntaxError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SYN/SyntaxError.o src/SYN/SyntaxError.cpp

${OBJECTDIR}/src/SYN/Value.o: src/SYN/Value.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SYN/Value.o src/SYN/Value.cpp

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
