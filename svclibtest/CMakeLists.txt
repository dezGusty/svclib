#-------------------------------------------------------------------
# This file is part of the CMake build system for the svclib library
#-------------------------------------------------------------------
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
#-------------------------------------------------------------------


CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

SET (svclibtest_project_name svclib_test)
PROJECT (${svclibtest_project_name})

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../cmake/;${CMAKE_MODULE_PATH}")
SET(svclibtest_project_type SHARED)

MESSAGE(STATUS "Building ${svclibtest_project_name}")
MESSAGE(STATUS "")

SET(svclibtest_project_DEPENDENCIES "svclib")

# Preprocessor definitions
ADD_DEFINITIONS(-DUNICODE -D_UNICODE )

# 
# -------------------------------------------------- File section ------------------------------------------------------
#

SET(SRCS
  ./svclib_test_main.cpp
)

# More include directories.
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/../svclib/include)


ADD_EXECUTABLE(${svclibtest_project_name} 
    ${SRCS})

#
# Link to dependencies
#
TARGET_LINK_LIBRARIES(${svclibtest_project_name} 
      ${svclibtest_project_DEPENDENCIES} )

#
# Set the default location of the output executable file.
#
IF (WIN32)
    IF (CMAKE_BUILD_TYPE STREQUAL "Release")
      SET (svclibtest_project_out_dir "../bin/Release")
    ELSE ()
      IF (CMAKE_BUILD_TYPE STREQUAL "Debug")
        SET (svclibtest_project_out_dir "../bin/Debug")
      ELSE ()
        SET (svclibtest_project_out_dir "../bin")
      ENDIF ()
    ENDIF ()
ELSE()
    SET (svclibtest_project_out_dir "bin")
ENDIF()

SET_TARGET_PROPERTIES (${svclibtest_project_name} 
    PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${svclibtest_project_out_dir}
)

