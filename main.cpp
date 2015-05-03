#import "http/server.h"
#import <iostream>
#import <algorithm>

http::response handle_request(const http::request & request) {
  auto response = http::response(200);

  response["Content-Type"] = "text/html; charset=utf-8";

  response << "<title>Web CPP test</title>\r\n";
  response << "<style>body { font-family: monospace; }</style>\r\n";
  response << "<dl>\r\n";

  response << "  <dt>Request method</dt>\r\n";
  response << "  <dd>" << request.method() << "</dd>\r\n";

  response << "  <dt>URI</dt>\r\n";
  response << "  <dd>" << request.request_uri() << "</dd>\r\n";

  response << "  <dt>Remote address</dt>\r\n";
  response << "  <dd>" << request.remote_address() << "</dd>\r\n";

  response << "  <dt>Request headers</dt>\r\n";
  response << "  <dd><pre>";

  auto headers = request.headers();
  std::for_each(headers.begin(), headers.end(), [&] (const std::pair<const std::string, const std::string> & header) {
    response << "  <b>" << header.first << "</b>: " << header.second << "\r\n";
  });

  response << "</pre></dd>\r\n";
  response << "</dl>\r\n";

  return response;
}

int main() {
  http::server server(handle_request);
  std::cout << "HTTP listening at 0.0.0.0:8080" << std::endl;
  server.listen(8080);
  return 0;
}
