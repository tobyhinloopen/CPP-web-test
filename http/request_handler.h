#pragma once

#include "request.h"
#include "response.h"
#include <memory>
#include <functional>

namespace http {
  typedef std::function<response(const request &)> request_handler;
}
