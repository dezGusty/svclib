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
    // Perform the needed action, based on the arguments in use.
    if (this->impl_->arguments_.size() > 1)
    {
      // The very first argument is expected to be the name of the application itself.

      // We have some arguments, check the possible arguments out.
      std::string first_argument = this->impl_->arguments_[1];

      if (first_argument == "install")
      {
        // Install the service.
      }
      else if (first_argument == "uninstall")
      {
        // Uninstall the service.
      }
      else if (first_argument == "start")
      {
        // Start the service.
      }
      else if (first_argument == "stop")
      {
        // Stop the service.
      }
      else if (first_argument == "pause")
      {
        // Pause the service.
      }
      else if (first_argument == "resume")
      {
        // Resume the service.
      }

      // Default behavior: start the service

    }

    return 0;
  }
}