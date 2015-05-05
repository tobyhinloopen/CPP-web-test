#pragma once

#include "request.h"
#include "header_set.h"
#include <istream>
#include <memory>
#include <tuple>

namespace http {
  class request_reader {
  public:
    request_reader(std::istream & input_stream);
    ~request_reader();
    std::unique_ptr<request> accept_request();
  private:
    std::string read_line();
    std::tuple<std::string,std::string> read_request_line();
    header_set read_request_headers();
  private:
    std::istream & input_stream;
  };
}
