#import "request.h"

http::request::request(std::string method, std::string request_uri):
request("", method, request_uri) {
}

http::request::request(std::string remote_address, std::string method, std::string request_uri):
remote_address_(remote_address),
method_(method),
request_uri_(request_uri) {
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
