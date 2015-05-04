#import "http/server.h"
#import "html/tag.h"
#import <iostream>
#import <algorithm>
#include <chrono>

http::response create_response(const http::request & request) {
  http::response response(200);

  response["Content-Type"] = "text/html; charset=utf-8";

  response << html::tag("title") << "Web CPP test" << html::tag("/title") << "\r\n";
  response << html::tag("style") << "body { font-family: monospace; }" << html::tag("/style") << "\r\n";
  response << html::tag("dl") << "\r\n";

  response << html::tag("dt") << "Request method" << html::tag("/dt") << "\r\n";
  response << html::tag("dd") << request.method() << html::tag("/dd") << "\r\n";

  response << html::tag("dt") << "URI" << html::tag("/dt") << "\r\n";
  response << html::tag("dd") << request.request_uri() << html::tag("/dd") << "\r\n";

  response << html::tag("dt") << "Remote address" << html::tag("/dt") << "\r\n";
  response << html::tag("dd") << request.remote_address() << html::tag("/dd") << "\r\n";

  response << html::tag("dt") << "Request headers" << html::tag("/dt") << "\r\n";
  response << html::tag("dd") << html::tag("pre");

  auto headers = request.headers();
  std::for_each(headers.begin(), headers.end(), [&] (const std::pair<const std::string, const std::string> & header) {
    response << "  " << html::tag("b") << header.first << html::tag("/b") << ": " << header.second << "\r\n";
  });

  response << html::tag("/pre") << html::tag("/dd") << "\r\n";
  response << html::tag("/dl") << "\r\n";

  return response;
}

http::response handle_request(const http::request & request) {
  auto start_time = std::chrono::high_resolution_clock::now();
  auto response = create_response(request);

  for(int i = 0; i < 10000; ++i)
    auto other_response = create_response(request);

  auto end_time = std::chrono::high_resolution_clock::now();
  auto time_spent = end_time - start_time;

  response << html::tag("code") << "10.000 documents generated in " <<
    std::chrono::duration_cast<std::chrono::microseconds>(time_spent).count() << "μs." << html::tag("/code");

  return response;
}

int main() {
  http::server server(handle_request);
  std::cout << "HTTP listening at 0.0.0.0:8080" << std::endl;
  server.listen(8080);
  return 0;
}
