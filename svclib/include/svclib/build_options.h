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
//   Build options.
//


//
// Includes
//

//
// This project's headers
//

// Add platform specific definitions.
#include "svclib/platform.h"
// Version info
#include "svclib/version.hpp"

//
// Macro definitions for import / export.
//
#ifdef SVCLIB_EXP
# define SVCLIB_EXPORT_SYMBOL __declspec (dllexport)
# define SVCLIB_EXPIMP_TEMPLATE
#elif SVCLIB_STATIC
# define SVCLIB_EXPORT_SYMBOL
# define SVCLIB_EXPIMP_TEMPLATE
#else
# define SVCLIB_EXPORT_SYMBOL __declspec (dllimport)
# define SVCLIB_EXPIMP_TEMPLATE extern
#endif  //  SVCLIB_EXP



