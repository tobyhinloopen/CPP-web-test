#import "http/server.h"
#import <iostream>
#import <algorithm>

http::response handle_request(const http::request & request) {
  auto response = http::response(200);
  response << "Request method: " << request.method() << "\r\n";
  response << "URI: " << request.request_uri() << "\r\n";
  response << "Remote Address: " << request.remote_address() << "\r\n";

  response << "Request headers:\r\n";
  auto headers = request.headers();

  std::for_each(headers.begin(), headers.end(), [&] (const std::pair<const std::string, const std::string> & header) {
    response << "  '" << header.first << "' = '" << header.second << "'\r\n";
  });

  return response;
}

int main() {
  http::server server(handle_request);
  std::cout << "HTTP listening at 0.0.0.0:8080" << std::endl;
  server.listen(8080);
  return 0;
}
