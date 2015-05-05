#include "response.h"

http::response::response():
response(200) {
}

http::response::response(std::string body):
response(200, body) {
}

http::response::response(unsigned short status):
response(status, "") {
}

http::response::response(unsigned short status, std::string body):
status_(status), body_(body), header_set_() {
}

unsigned short http::response::status() const {
  return status_;
}

const std::string http::response::content_type() const {
  auto content_type_header_value = (*this)["Content-Type"];
  if(content_type_header_value.empty())
    return "text/plain";
  else
    return content_type_header_value;
}

size_t http::response::content_length() const {
  auto content_length_header_value = (*this)["Content-Length"];
  if(content_length_header_value.empty())
    return body().length();
  else
    return std::stol(content_length_header_value);
}

const std::string http::response::body() const {
  return body_.str();
}

const std::string http::response::operator[](const std::string key) const {
  auto header = header_set_.find(key);
  return header == header_set_.end() ? "" : header->second;
}

std::string & http::response::operator[](const std::string key) {
  return header_set_[key];
}

const http::header_set http::response::headers() const {
  return header_set_;
}
