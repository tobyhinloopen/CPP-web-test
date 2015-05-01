#import "http/response.h"
#import "net/tcp_server.h"
#import "http/request_reader.h"
#import <iostream>

int main() {
  std::cout << "HTTP listening at 0.0.0.0:8080" << std::endl;
  net::tcp_server server(8080);
  while(true) {
    auto client = server.accept();
    http::request_reader request_reader(client->cin);
    auto http_request = request_reader.accept_request();
    client->cout << http::response();
  }
  return 0;
}
