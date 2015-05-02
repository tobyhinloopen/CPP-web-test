#import "response.h"

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
status_(status), body_(body) {
}

unsigned short http::response::status() const {
  return status_;
}

const std::string http::response::content_type() const {
  return "text/plain";
}

size_t http::response::content_length() const {
  return body().length();
}

const std::string http::response::body() const {
  return body_.str();
}
