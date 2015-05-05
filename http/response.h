#pragma once

#include <sstream>
#include <string>
#include "header_set.h"

namespace http {
  class response {
  public:
    response();
    response(const response &) = default;
    response(std::string body);
    response(unsigned short status);
    response(unsigned short status, std::string body);
    unsigned short status() const;
    const std::string content_type() const;
    size_t content_length() const;
    const std::string body() const;
    const std::string operator[](const std::string key) const;
    std::string & operator[](const std::string key);
    const header_set headers() const;

    template<class T> response & operator<<(const T & fragment) {
      body_ << fragment;
      return *this;
    }
  private:
    unsigned short status_;
    std::ostringstream body_;
    header_set header_set_;
  };
}
