#pragma once

#include <exception>

namespace net {
  class bind_failed_exception : public std::exception {
  };
}
