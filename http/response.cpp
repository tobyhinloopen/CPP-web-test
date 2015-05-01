#import "response.h"

unsigned short http::response::status() const {
  return 200;
}

unsigned char http::response::http_major_version() const {
  return 1;
}

unsigned char http::response::http_minor_version() const {
  return 0;
}

const std::string http::response::content_type() const {
  return "text/plain";
}

size_t http::response::content_length() const {
  return 0;
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
  out << "HTTP/" << (unsigned short)response.http_major_version();
  out << '.' << (unsigned short)response.http_minor_version();
  out << ' ' << response.status() << " \r\n";
}

void write_response_headers(std::ostream & out, const http::response & response) {
  out << "Content-Length: " << response.content_length() << "\r\n";
  out << "Content-Type: " << response.content_type() << "\r\n";
}

void write_response_body(std::ostream & out, const http::response & response) {
  if(response.content_length() == 0)
    return;
}
