#import "server.h"
#import "../net/tcp_server.h"
#import "request_reader.h"

http::server::server(request_handler request_handler_):
request_handler_(request_handler_) {
}

void http::server::listen(unsigned short port) {
  net::tcp_server server(port);
  while(true) {
    auto client = server.accept();
    http::request_reader request_reader(client->cin);
    auto http_request = request_reader.accept_request();
    auto http_response = request_handler_(*http_request);
    client->cout << http_response;
  }
}
