#pragma once

#include <exception>

namespace ast {

class BadCastException : public std::exception
{
  public:
    BadCastException(const char* msg)
        : message(msg)
    { }

    BadCastException()
        : message("")
    { }

    const char* what() const noexcept override
    {
        return message;
    }

  private:
    const char* message;
};

} // namespace ast
