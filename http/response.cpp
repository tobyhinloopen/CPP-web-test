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

void write_response_status_line(std::ostream &, const http::response &);
void write_response_headers(std::ostream &, const http::response &);
void write_response_body(std::ostream &, const http::response &);

std::ostream & http::operator<<(std::ostream & out, const http::response & response) {
  write_response_status_line(out, response);
  write_response_headers(out, response);
  out << "\r\n";
  write_response_body(out, response);
  return out;
}

void write_response_status_line(std::ostream & out, const http::response & response) {
  out << "HTTP/1.0 " << response.status() << " \r\n";
}

void write_response_headers(std::ostream & out, const http::response & response) {
  out << "Content-Length: " << response.content_length() << "\r\n";
  out << "Content-Type: " << response.content_type() << "\r\n";
}

void write_response_body(std::ostream & out, const http::response & response) {
  out << response.body();
}
