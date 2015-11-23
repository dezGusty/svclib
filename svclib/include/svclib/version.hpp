#pragma once

//   This file is part of the svclib library, licensed under the terms of the MIT License.
//
//   The MIT License
//   Copyright (C) 2015  Augustin Preda (thegusty999@gmail.com)
//
//   Permission is hereby granted, free of charge, to any person obtaining a copy
//   of this software and associated documentation files (the "Software"), to deal
//   in the Software without restriction, including without limitation the rights
//   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//   copies of the Software, and to permit persons to whom the Software is
//   furnished to do so, subject to the following conditions:
//
//   The above copyright notice and this permission notice shall be included in
//   all copies or substantial portions of the Software.
//
//   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//   THE SOFTWARE.
//
//   This header will change between different releases of svclib. 
//   Including the header will result in a recompile
//   when a new version of svclib is released.

//
// This file provides version information for the svclib project.
// The information must be updated manually.
//

// --------------------------------------------- utility macros ----------------------------------------------------

//
// Utility macro:
// Concatenate preprocessor tokens A and B without expanding macro definitions
// (however, if invoked from a macro, macro arguments are expanded).
//
#define PPCAT_NX(A, B) A ## B

//
// Utility macro:
// Concatenate preprocessor tokens A and B after macro-expanding them.
//
#define PPCAT(A, B) PPCAT_NX(A, B)

//
// Utility macro:
// Turn A into a string literal without expanding macro definitions
// (however, if invoked from a macro, macro arguments are expanded).
//
#define STRINGIZE_NX(A) #A

//
// Utility macro:
// Turn A into a string literal after macro-expanding it.
//
#define STRINGIZE(A) STRINGIZE_NX(A)

// ------------------------------------------- version specifications --------------------------------------------------

//
// Define the major, minor and patch version numbers for separate use.
// These should be used in the generation of the resource file version information.
// Some macros also contain definitions for multiple amount of digits, used for alignment.
//

// Major versiom
#define SVCLIB_NUM_MAJOR_VER_SIMPLE 0

// Minor versions. Please keep in sync!
#define SVCLIB_NUM_MINOR_VER_SIMPLE 1
#define SVCLIB_NUM_MINOR_VER_2DIGITS 00
#define SVCLIB_NUM_MINOR_VER_3DIGITS 000

// Patch versions. Please keep in sync!
#define SVCLIB_NUM_PATCH_VER_SIMPLE 0.0
#define SVCLIB_NUM_PATCH_VER_2DIGITS 00.00

//
// Also define string adaptations
//

//  SVCLIB_NUM_VERSION % 100 is the patch level
//  SVCLIB_NUM_VERSION / 100 % 1000 is the minor version
//  SVCLIB_NUM_VERSION / 100000 is the major version

// E.g: SVCLIB_NUM_VERSION 100000
//                         ____XX = patch
//                         _XXX__ = minor version
//                         X_____ = major version

#define SVCLIB_NUM_VERSION PPCAT(SVCLIB_NUM_MAJOR_VER_SIMPLE,PPCAT(SVCLIB_NUM_MINOR_VER_3DIGITS,SVCLIB_NUM_PATCH_VER_2DIGITS))

//  SVCLIB_STRING_VERSION should be defined by the user to have the same value as SVCLIB_NUM_VERSION, but as a string, in the form
//  "x_y[_z]", where "x" is the major version number, "y" is the minor version number, and "z" (optional) is the patch level. (if the patch level is 0,
//  you should just skip it).

#define SVCLIB_STRING_VERSION STRINGIZE(SVCLIB_NUM_MAJOR_VER_SIMPLE) "." STRINGIZE(SVCLIB_NUM_MINOR_VER_SIMPLE) "." STRINGIZE (SVCLIB_NUM_PATCH_VER_SIMPLE)

//
// File version
//
#define SVCLIB_STR_FILE_VERSION STRINGIZE(SVCLIB_NUM_MAJOR_VER_SIMPLE) "." STRINGIZE(SVCLIB_NUM_MINOR_VER_SIMPLE) "." STRINGIZE (SVCLIB_NUM_PATCH_VER_SIMPLE)

//
// Product version
//
#define SVCLIB_STR_PROD_VERSION STRINGIZE(SVCLIB_NUM_MAJOR_VER_SIMPLE) "." STRINGIZE(SVCLIB_NUM_MINOR_VER_SIMPLE) "." STRINGIZE (SVCLIB_NUM_PATCH_VER_SIMPLE)



