#import "http/server.h"
#import <iostream>

int main() {
  http::server server([] (http::request & request) -> http::response {
    return http::response();
  });
  std::cout << "HTTP listening at 0.0.0.0:8080" << std::endl;
  server.listen(8080);
  return 0;
}
