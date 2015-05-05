#include "request_reader.h"
#include <string>
#include <iostream>

http::request_reader::request_reader(std::istream & input_stream):
input_stream(input_stream) {
}

http::request_reader::~request_reader() {
}

void strip_newline(std::string &);

std::unique_ptr<http::request> http::request_reader::accept_request() {
  std::string method;
  std::string request_uri;
  std::tie(method, request_uri) = read_request_line();
  auto headers = read_request_headers();
  return std::unique_ptr<http::request>(new http::request(method, request_uri, headers));
}


std::tuple<std::string,std::string> http::request_reader::read_request_line() {
  std::string method;
  input_stream >> method;
  std::string request_uri;
  input_stream >> request_uri;
  read_line();
  return std::make_tuple(method, request_uri);
}

http::header_set http::request_reader::read_request_headers() {
  http::header_set headers;

  while(true) {
    auto line = read_line();

    // end of headers
    if(line.length() == 0)
      break;

    const auto double_colon_index = line.find_first_of(':');

    // if ':' not found: invalid header line, continue to next line...
    if(double_colon_index == std::string::npos)
      continue;

    const auto key = line.substr(0, double_colon_index);

    // strip leading spaces (by moving the start-index-pointer right)
    auto value_start_index = double_colon_index+1;
    while(line[value_start_index] == ' ')
      ++value_start_index;

    const auto value = line.substr(value_start_index, std::string::npos);

    headers[key] = value;
  }

  return headers;
}

std::string http::request_reader::read_line() {
  std::string line;
  std::getline(input_stream, line);
  if(*line.rbegin() == '\r')
    line.erase(line.length() - 1);
  return line;
}
