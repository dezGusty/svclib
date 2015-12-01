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

// Own header
#include "svclib/service.h"

//
// C++ system headers.
//
#include <string>
#include <vector>

namespace svclib
{
  class Service::Impl
  {
  public:
    std::vector<std::string> arguments_;

    Impl(int argc, char* argv[])
    {
      for (int index = 0; index < argc; ++index)
      {
        arguments_.push_back(argv[index]);
      }
    }

    Impl(const Impl& rhs)
      : arguments_(rhs.arguments_)
    {
    }

    Impl(const Impl&& rhs)
      : arguments_(std::move(rhs.arguments_))
    {
    }
  };

  Service::Service()
  {
  }

  Service::Service(int argc, char* argv[])
  {
  }

  //
  // Copy constructor.
  //
  Service::Service(const Service& rhs)
    : impl_(rhs.impl_)
  {
  }

  //
  // Move constructor.
  //
  Service::Service(const Service&& rhs)
    : impl_(std::move(rhs.impl_))
  {
  }

  Service::~Service()
  {
  }

  int Service::Execute()
  {
    return 0;
  }
}