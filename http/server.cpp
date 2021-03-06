#import "server.h"
#import "../net/tcp_server.h"
#import "request_reader.h"
#import "response_writer.h"

http::server::server(http::request_handler request_handler_):
request_handler_(request_handler_) {
}

void http::server::listen(unsigned short port) {
  net::tcp_server server(port);
  while(true) {
    auto client = server.accept();
    http::request_reader request_reader(client->cin);
    http::response_writer response_writer(client->cout);
    auto http_request = request_reader.accept_request();
    http_request->remote_address(client->remote_address());
    const http::request & request = *http_request;
    auto http_response = request_handler_(request);
    response_writer.write_response(http_response);
  }
}
