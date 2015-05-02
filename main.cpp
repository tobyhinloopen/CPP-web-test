#import "http/server.h"
#import <iostream>

int main() {
  http::server server([] (auto request) {
    auto response = http::response(200);
    response << "Request method: " << request.method() << "\r\n";
    response << "URI: " << request.request_uri() << "\r\n";
    return response;
  });
  std::cout << "HTTP listening at 0.0.0.0:8080" << std::endl;
  server.listen(8080);
  return 0;
}
