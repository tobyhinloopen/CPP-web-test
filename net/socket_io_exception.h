#pragma once

#include <exception>

namespace net {
  class socket_io_exception : public std::exception {
  };
}
