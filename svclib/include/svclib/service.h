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
// Includes
//

// Build macros
#include "svclib/build_options.h"

// C/C++ system headers
// none

// This project's headers
// none

namespace svclib
{

  /**
    A service (or Daemon) class.
    @author Augustin Preda.
  */
  class SVCLIB_EXPORT_SYMBOL Service
  {
  public:
    //
    // Constructor.
    //
    Service();

    //
    // Constructor.
    //
    Service(int argc, char* argv[]);

    //
    // Copy constructor.
    //
    Service(const Service& rhs);

    //
    // Move constructor.
    //
    Service(const Service&& rhs);

    //
    // Destructor.
    //
    virtual ~Service();

    //
    // Executes the service.
    // This performs the needed action for the service, based on the arguments with which the
    // service has been created.
    //
    virtual int Execute();

  private:
    class Impl;
    Impl* impl_;
  };
}