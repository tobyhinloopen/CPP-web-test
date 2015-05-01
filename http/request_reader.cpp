#import "request_reader.h"
#import <string>
#import <iostream>

http::request_reader::request_reader(std::istream & input_stream):
input_stream(input_stream) {
}

http::request_reader::~request_reader() {
}

void strip_newline(std::string &);

std::unique_ptr<http::request> http::request_reader::accept_request() {
  std::string method;
  input_stream >> method;
  std::string request_uri;
  input_stream >> request_uri;
  std::string remainer_of_line;
  std::getline(input_stream, remainer_of_line);

  for(std::string line; std::getline(input_stream, line);) {
    strip_newline(line);
    if(line.length() == 0)
      break;
  }

  return std::unique_ptr<http::request>(new http::request(method, request_uri));
}

void strip_newline(std::string & line) {
  if(*line.rbegin() == '\r')
    line.erase(line.length() - 1);
}
