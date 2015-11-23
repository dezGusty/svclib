#------------------------------------------------------------------------------
# This file is part of the CMake build system for the svclib library
#------------------------------------------------------------------------------
# The MIT License
# Copyright (C) 2015  Augustin Preda (thegusty999@gmail.com)
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
#------------------------------------------------------------------------------

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

# Stores the name of the project, to allow a single place to rename it.  
SET (SVCLIB_PROJECT_NAME svclib)
PROJECT (${SVCLIB_PROJECT_NAME})

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake/;${CMAKE_MODULE_PATH}")
SET(SVCLIB_LIB_TYPE SHARED)

# Write some messages to the log.
MESSAGE (STATUS "... building ${SVCLIB_PROJECT_NAME} ...")
MESSAGE (STATUS "")

# Specify the preferred build type to be unicode.
# Specify that the SVCLIB_EXP symbol is defined. Also define the _USRDLL symbol, needed for regular DLLs.
ADD_DEFINITIONS(-DUNICODE -D_UNICODE -DSVCLIB_EXP -D_USRDLL)

# 
# Specify some user configurable options
# 

# (None)

# 
# -------------------------------------------------- File section ------------------------------------------------------
#

# Just keep this for future references
SET (SOURCE_FILES_SVCLIB_FOLDER
  ./include/svclib/build_options.h
  ./include/svclib/platform.h
  ./include/svclib/version.hpp
)



SET (SOURCE_FILES
  ${SOURCE_FILES_SVCLIB_FOLDER}
)

# If building for windows based systems, the resource file (containing 
# the manifest, icon and other resources) should also be included
IF (WIN32)
  SET (SOURCE_FILES_RESOURCE_FOLDER
    ./guslib/resource/guslib.rc
  )
  
  SET (SOURCE_FILES
    ${SOURCE_FILES}
    ${SOURCE_FILES_RESOURCE_FOLDER}
  )
ENDIF()
  

# 
# Group the files into file tabs (specific to Visual Studio)
# The files must be already defined in the header or source list.
#

# The common group
SOURCE_GROUP("guslib\\common" FILES
  ${SOURCE_FILES_COMMON}
)

SOURCE_GROUP("guslib\\system" FILES
  ${SOURCE_FILES_SYSTEM}
)

SOURCE_GROUP("guslib\\thirdparty" FILES
  ${SOURCE_FILES_THIRDPARTY}
)

SOURCE_GROUP("guslib\\trace" FILES
  ${SOURCE_FILES_TRACE}
)

SOURCE_GROUP("guslib\\util" FILES
  ${SOURCE_FILES_UTIL}
)

SOURCE_GROUP("guslib\\util\\config" FILES
  ${SOURCE_FILES_UTIL_CFG}
)

IF (WIN32)
  SOURCE_GROUP("guslib\\resource" FILES
    ${SOURCE_FILES_RESOURCE_FOLDER}
  )
ENDIF()

# The parent folder 
SOURCE_GROUP("guslib" FILES
  ${SOURCE_FILES_BASE_FOLDER}
)


#
# Additional include directories.
# Add the current folder (CMAKE_CURRENT_SOURCE_DIR)
# If you don't build into the same directory, also add CMAKE_CURRENT_BINARY_DIR.
#
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR})

#
# Specify the library to be built from the source files.
#
add_library(${SVCLIB_PROJECT_NAME}
    ${GUSLIB_LIB_TYPE}
    ${SOURCE_FILES})

# TODO: define link options (static/non-static) and dll-export symbols (GUSLIB_EXP)/GUSLIB_IMP definitions.
# set_target_properties(${GUSLIB_PROJECT_NAME}
#     PROPERTIES
#     COMPILE_DEFINITIONS _LIB
#     COMPILE_DEFINITIONS GUSLIB_LIB_BUILD
# )

  
#
# Link to dependencies
#
IF (Boost_FOUND)
  TARGET_LINK_LIBRARIES(${GUSLIB_PROJECT_NAME} ${list_of_boost_libs_to_link})
ENDIF ()
 

# if (APPLE AND NOT OGRE_BUILD_PLATFORM_APPLE_IOS)
#     # Set the INSTALL_PATH so that Components can be installed in the application package
#     set_target_properties(guslib
#        PROPERTIES BUILD_WITH_INSTALL_RPATH 1
#        INSTALL_NAME_DIR "@executable_path/../Components"
#     )
# 
# 	# Copy headers into the main Ogre framework
# 	add_custom_command(TARGET OgreRTShaderSystem POST_BUILD
# 	  COMMAND ditto ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h ${OGRE_BINARY_DIR}/lib/$(CONFIGURATION)/Ogre.framework/Headers/
# 	)
# endif()


install(FILES ${SOURCE_FILES}
  DESTINATION include/guslib
)

#
# Set the default location of the output executable file.
#
IF (WIN32)
    IF (CMAKE_BUILD_TYPE STREQUAL "Release")
      SET (GUSLIB_DLL_OUTPUT_DIR "../bin/Release")
    ELSE ()
      IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
        SET (GUSLIB_DLL_OUTPUT_DIR "../bin/Debug")
      ELSE ()
        MESSAGE (STATUS "CMAKE_BUILD_TYPE is [${CMAKE_BUILD_TYPE}]")
        SET (GUSLIB_DLL_OUTPUT_DIR "../bin")
      ENDIF ()
    ENDIF ()
    SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${GUSLIB_DLL_OUTPUT_DIR})
ELSE()
    SET (GUSLIB_DLL_OUTPUT_DIR "bin")
ENDIF()

#
# Set the default location of the output .lib file.
#
IF (WIN32)
    IF (CMAKE_BUILD_TYPE STREQUAL "Release")
      SET (GUSLIB_LIB_OUTPUT_DIR "../lib/Release")
    ELSE ()
      IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
        SET (GUSLIB_LIB_OUTPUT_DIR "../lib/Debug")
      ELSE ()
        SET (GUSLIB_LIB_OUTPUT_DIR "../lib")
      ENDIF ()
    ENDIF ()
    SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${GUSLIB_LIB_OUTPUT_DIR})
ELSE()
    SET (GUSLIB_LIB_OUTPUT_DIR "lib")
ENDIF()

SET_TARGET_PROPERTIES (${GUSLIB_PROJECT_NAME}
    PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${GUSLIB_DLL_OUTPUT_DIR}
        ARCHIVE_OUTPUT_DIRECTORY ${GUSLIB_LIB_OUTPUT_DIR}

)

# install the build binary
install(TARGETS ${GUSLIB_PROJECT_NAME}
  RUNTIME DESTINATION "${GUSLIB_DLL_OUTPUT_DIR}")

install(TARGETS ${GUSLIB_PROJECT_NAME}
  RUNTIME DESTINATION "${GUSLIB_LIB_OUTPUT_DIR}")

MESSAGE (STATUS "Set runtime dest of ${GUSLIB_PROJECT_NAME} to : ${GUSLIB_DLL_OUTPUT_DIR}")
MESSAGE (STATUS "Set lib dest of ${GUSLIB_PROJECT_NAME} to : ${GUSLIB_LIB_OUTPUT_DIR}")
