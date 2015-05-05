#pragma once

#include <string>
#include "header_set.h"

namespace http {
  class request {
  public:
    request(const std::string method, const std::string request_uri);
    request(const std::string method, const std::string request_uri, const header_set header_set);
    void remote_address(std::string remote_address);
    const std::string remote_address() const;
    const std::string method() const;
    const std::string request_uri() const;
    const std::string operator[](const std::string key) const;
    const header_set headers() const;
  private:
    std::string remote_address_;
    const std::string method_;
    const std::string request_uri_;
    const header_set header_set_;
  };
}
