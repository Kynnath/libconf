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
	${OBJECTDIR}/src/CFG/Config.o \
	${OBJECTDIR}/src/CFG/ConfigError.o \
	${OBJECTDIR}/src/CFG/LEX/Lexer.o \
	${OBJECTDIR}/src/CFG/LEX/LexerError.o \
	${OBJECTDIR}/src/CFG/LEX/Token.o \
	${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o \
	${OBJECTDIR}/src/CFG/SEM/SemanticError.o \
	${OBJECTDIR}/src/CFG/SYN/Expression.o \
	${OBJECTDIR}/src/CFG/SYN/Parser.o \
	${OBJECTDIR}/src/CFG/SYN/Property.o \
	${OBJECTDIR}/src/CFG/SYN/Scope.o \
	${OBJECTDIR}/src/CFG/SYN/SyntaxError.o \
	${OBJECTDIR}/src/CFG/Value.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f4

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

${OBJECTDIR}/src/CFG/Config.o: src/CFG/Config.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/Config.o src/CFG/Config.cpp

${OBJECTDIR}/src/CFG/ConfigError.o: src/CFG/ConfigError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/ConfigError.o src/CFG/ConfigError.cpp

${OBJECTDIR}/src/CFG/LEX/Lexer.o: src/CFG/LEX/Lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/Lexer.o src/CFG/LEX/Lexer.cpp

${OBJECTDIR}/src/CFG/LEX/LexerError.o: src/CFG/LEX/LexerError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/LexerError.o src/CFG/LEX/LexerError.cpp

${OBJECTDIR}/src/CFG/LEX/Token.o: src/CFG/LEX/Token.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/Token.o src/CFG/LEX/Token.cpp

${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o: src/CFG/SEM/SemanticAnalyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SEM
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o src/CFG/SEM/SemanticAnalyzer.cpp

${OBJECTDIR}/src/CFG/SEM/SemanticError.o: src/CFG/SEM/SemanticError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SEM
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SEM/SemanticError.o src/CFG/SEM/SemanticError.cpp

${OBJECTDIR}/src/CFG/SYN/Expression.o: src/CFG/SYN/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Expression.o src/CFG/SYN/Expression.cpp

${OBJECTDIR}/src/CFG/SYN/Parser.o: src/CFG/SYN/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Parser.o src/CFG/SYN/Parser.cpp

${OBJECTDIR}/src/CFG/SYN/Property.o: src/CFG/SYN/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Property.o src/CFG/SYN/Property.cpp

${OBJECTDIR}/src/CFG/SYN/Scope.o: src/CFG/SYN/Scope.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Scope.o src/CFG/SYN/Scope.cpp

${OBJECTDIR}/src/CFG/SYN/SyntaxError.o: src/CFG/SYN/SyntaxError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/SyntaxError.o src/CFG/SYN/SyntaxError.cpp

${OBJECTDIR}/src/CFG/Value.o: src/CFG/Value.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/Value.o src/CFG/Value.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/ConfigTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/ConfigTests.o: tests/ConfigTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I. -I. -I. -I. -I. -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/ConfigTests.o tests/ConfigTests.cpp


${OBJECTDIR}/src/CFG/Config_nomain.o: ${OBJECTDIR}/src/CFG/Config.o src/CFG/Config.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/Config.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/Config_nomain.o src/CFG/Config.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/Config.o ${OBJECTDIR}/src/CFG/Config_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/ConfigError_nomain.o: ${OBJECTDIR}/src/CFG/ConfigError.o src/CFG/ConfigError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/ConfigError.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/ConfigError_nomain.o src/CFG/ConfigError.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/ConfigError.o ${OBJECTDIR}/src/CFG/ConfigError_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/LEX/Lexer_nomain.o: ${OBJECTDIR}/src/CFG/LEX/Lexer.o src/CFG/LEX/Lexer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/LEX/Lexer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/Lexer_nomain.o src/CFG/LEX/Lexer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/LEX/Lexer.o ${OBJECTDIR}/src/CFG/LEX/Lexer_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/LEX/LexerError_nomain.o: ${OBJECTDIR}/src/CFG/LEX/LexerError.o src/CFG/LEX/LexerError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/LEX/LexerError.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/LexerError_nomain.o src/CFG/LEX/LexerError.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/LEX/LexerError.o ${OBJECTDIR}/src/CFG/LEX/LexerError_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/LEX/Token_nomain.o: ${OBJECTDIR}/src/CFG/LEX/Token.o src/CFG/LEX/Token.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/LEX
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/LEX/Token.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/LEX/Token_nomain.o src/CFG/LEX/Token.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/LEX/Token.o ${OBJECTDIR}/src/CFG/LEX/Token_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer_nomain.o: ${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o src/CFG/SEM/SemanticAnalyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer_nomain.o src/CFG/SEM/SemanticAnalyzer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer.o ${OBJECTDIR}/src/CFG/SEM/SemanticAnalyzer_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/SEM/SemanticError_nomain.o: ${OBJECTDIR}/src/CFG/SEM/SemanticError.o src/CFG/SEM/SemanticError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SEM
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/SEM/SemanticError.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SEM/SemanticError_nomain.o src/CFG/SEM/SemanticError.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/SEM/SemanticError.o ${OBJECTDIR}/src/CFG/SEM/SemanticError_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/SYN/Expression_nomain.o: ${OBJECTDIR}/src/CFG/SYN/Expression.o src/CFG/SYN/Expression.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/SYN/Expression.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Expression_nomain.o src/CFG/SYN/Expression.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/SYN/Expression.o ${OBJECTDIR}/src/CFG/SYN/Expression_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/SYN/Parser_nomain.o: ${OBJECTDIR}/src/CFG/SYN/Parser.o src/CFG/SYN/Parser.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/SYN/Parser.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Parser_nomain.o src/CFG/SYN/Parser.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/SYN/Parser.o ${OBJECTDIR}/src/CFG/SYN/Parser_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/SYN/Property_nomain.o: ${OBJECTDIR}/src/CFG/SYN/Property.o src/CFG/SYN/Property.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/SYN/Property.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Property_nomain.o src/CFG/SYN/Property.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/SYN/Property.o ${OBJECTDIR}/src/CFG/SYN/Property_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/SYN/Scope_nomain.o: ${OBJECTDIR}/src/CFG/SYN/Scope.o src/CFG/SYN/Scope.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/SYN/Scope.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/Scope_nomain.o src/CFG/SYN/Scope.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/SYN/Scope.o ${OBJECTDIR}/src/CFG/SYN/Scope_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/SYN/SyntaxError_nomain.o: ${OBJECTDIR}/src/CFG/SYN/SyntaxError.o src/CFG/SYN/SyntaxError.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG/SYN
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/SYN/SyntaxError.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/SYN/SyntaxError_nomain.o src/CFG/SYN/SyntaxError.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/SYN/SyntaxError.o ${OBJECTDIR}/src/CFG/SYN/SyntaxError_nomain.o;\
	fi

${OBJECTDIR}/src/CFG/Value_nomain.o: ${OBJECTDIR}/src/CFG/Value.o src/CFG/Value.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/CFG
	@NMOUTPUT=`${NM} ${OBJECTDIR}/src/CFG/Value.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -I. -I. -I. -I. -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CFG/Value_nomain.o src/CFG/Value.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/src/CFG/Value.o ${OBJECTDIR}/src/CFG/Value_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f4 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibconf.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
