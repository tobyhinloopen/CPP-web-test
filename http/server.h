#pragma once

#include "request_handler.h"

namespace http {
  class server {
  public:
    server(const request_handler request_handler);
    void listen(unsigned short port);
  private:
    const request_handler request_handler;
  };
}
