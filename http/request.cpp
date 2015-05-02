#import "request.h"

http::request::request(const std::string method, const std::string request_uri):
request(method, request_uri, header_set()) {
}

http::request::request(const std::string method, const std::string request_uri, const header_set header_set):
method_(method),
request_uri_(request_uri),
header_set_(header_set) {
}

void http::request::remote_address(std::string remote_address) {
  remote_address_ = remote_address;
}

const std::string http::request::remote_address() const {
  return remote_address_;
}

const std::string http::request::method() const {
  return method_;
}

const std::string http::request::request_uri() const {
  return request_uri_;
}

const http::header_set http::request::headers() const {
  return header_set_;
}

const std::string http::request::operator[](const std::string key) const {
  auto header = header_set_.find(key);
  return header == header_set_.end() ? "" : header->second;
}
