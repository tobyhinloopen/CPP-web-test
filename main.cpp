#import "http/server.h"
#import "html/tag.h"
#import <iostream>
#import <algorithm>
#include <chrono>

http::response create_response(const http::request & request) {
  http::response response(200);

  response["Content-Type"] = "text/html; charset=utf-8";

  response << html::element("title", "Web CPP test") << "\r\n";
  response << html::element("style", "body { font-family: monospace; }") << "\r\n";
  response << html::tag("dl") << "\r\n";

  response << html::element("dt", "Request method") << "\r\n";
  response << html::element("dd", request.method()) << "\r\n";

  response << html::element("dt", "URI") << "\r\n";
  response << html::element("dd", request.request_uri()) <<  << "\r\n";

  response << html::element("dt", "Remote address") << "\r\n";
  response << html::element("dd", request.remote_address()) << "\r\n";

  response << html::element("dt", "Request headers") << "\r\n";
  response << html::tag("dd") << html::tag("pre");

  auto headers = request.headers();
  typedef std::pair<const std::string, const std::string> header_pair;
  std::for_each(headers.begin(), headers.end(), [&] (const header_pair & header) {
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
