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
CC=clang
CCC=clang++
CXX=clang++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=CLang-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/FontCharacterSet.o \
	${OBJECTDIR}/FontRenderer.o \
	${OBJECTDIR}/Renderer.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/pugixml-1.2/src/pugixml.o


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
LDLIBSOPTIONS=/usr/lib/x86_64-linux-gnu/libSDL2.so /usr/lib/x86_64-linux-gnu/libSDL2-2.0.so /usr/lib/x86_64-linux-gnu/libSDL2_image.so /usr/lib/x86_64-linux-gnu/libSDL2_image-2.0.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure: /usr/lib/x86_64-linux-gnu/libSDL2.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure: /usr/lib/x86_64-linux-gnu/libSDL2-2.0.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure: /usr/lib/x86_64-linux-gnu/libSDL2_image.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure: /usr/lib/x86_64-linux-gnu/libSDL2_image-2.0.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/FontCharacterSet.o: FontCharacterSet.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FontCharacterSet.o FontCharacterSet.cpp

${OBJECTDIR}/FontRenderer.o: FontRenderer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FontRenderer.o FontRenderer.cpp

${OBJECTDIR}/Renderer.o: Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Renderer.o Renderer.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/pugixml-1.2/src/pugixml.o: pugixml-1.2/src/pugixml.cpp 
	${MKDIR} -p ${OBJECTDIR}/pugixml-1.2/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/pugixml-1.2/src/pugixml.o pugixml-1.2/src/pugixml.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/text_adventure

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
