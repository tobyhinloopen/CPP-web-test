#pragma once

#include <exception>

namespace net {
  class accept_failed_exception : public std::exception {
  };
}
