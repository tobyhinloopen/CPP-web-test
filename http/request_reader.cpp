#import "request_reader.h"
#import <string>

http::request_reader::request_reader(std::istream & input_stream):
input_stream(input_stream) {
}

http::request_reader::~request_reader() {
}

std::unique_ptr<http::request> http::request_reader::accept_request() {
  std::string method;
  input_stream >> method;
  std::string request_uri;
  input_stream >> request_uri;
  std::string http_version_str;
  input_stream >> http_version_str;

  return std::unique_ptr<http::request>(new http::request(method, request_uri));
}
