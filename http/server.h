#pragma once

#include "request_handler.h"

namespace http {
  class server {
  public:
    server(request_handler request_handler);
    void listen(unsigned short port);
  private:
    request_handler request_handler;
  };
}
