#pragma once

#include <ostream>
#include "response.h"

namespace http {
  class response_writer {
  public:
    response_writer(std::ostream & output_stream);
    void write_response(const response & response);
  private:
    void write_response_status_line(const response & response);
    void write_response_headers(const response & response);
    void write_response_body(const response & response);
  private:
    std::ostream & output_stream;
  };
}
