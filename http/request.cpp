#import "request.h"

http::request::request(std::string method, std::string request_uri):
method_(method),
request_uri_(request_uri) {
}

std::string http::request::method() const {
  return method_;
}

std::string http::request::request_uri() const {
  return request_uri_;
}
