#import "response_writer.h"

http::response_writer::response_writer(std::ostream & output_stream):
output_stream(output_stream) {
}

void http::response_writer::write_response(const http::response & response) {
  write_response_status_line(response);
  write_response_headers(response);
  output_stream << "\r\n";
  write_response_body(response);
}

void http::response_writer::write_response_status_line(const http::response & response) {
  output_stream << "HTTP/1.0 " << response.status() << " \r\n";
}

void http::response_writer::write_response_headers(const http::response & response) {
  output_stream << "Content-Length: " << response.content_length() << "\r\n";
  output_stream << "Content-Type: " << response.content_type() << "\r\n";
}

void http::response_writer::write_response_body(const http::response & response) {
  output_stream << response.body();
}
