#include "http/server.h"
#include "html/element.h"
#include <iostream>
#include <algorithm>
#include <chrono>

http::response handle_request(const http::request & request);

int main() {
  http::server server(handle_request);
  std::cout << "HTTP listening at 0.0.0.0:8080" << std::endl;
  server.listen(8080);
  return 0;
}

http::response create_response(const http::request & request);

http::response handle_request(const http::request & request) {
  auto start_time = std::chrono::high_resolution_clock::now();
  auto response = create_response(request);

  for(int i = 0; i < 1000; ++i)
    auto other_response = create_response(request);

  auto end_time = std::chrono::high_resolution_clock::now();
  auto time_spent = end_time - start_time;

  response << html::tag("code") << "1.000 documents generated in " <<
    std::chrono::duration_cast<std::chrono::microseconds>(time_spent).count() << "μs." << html::tag("/code");

  return response;
}

http::response create_response(const http::request & request) {
  http::response response(200);

  response["Content-Type"] = "text/html; charset=utf-8";

  response << html::element("title", "Web CPP test");
  response << html::element("style", "body { font-family: monospace; }");

  response << html::element("dl", [&] (html::element & dl) {
    dl << html::element("dt", "Request method") << html::element("dd", request.method());
    dl << html::element("dt", "URI") << html::element("dd", request.request_uri());
    dl << html::element("dt", "Remote address") << html::element("dd", request.remote_address());

    dl << html::element("dt", "Request headers");
    dl << html::element("dd", html::element("pre", [&] (html::element & pre) {
      auto headers = request.headers();
      typedef std::pair<const std::string, const std::string> header_pair;
      std::for_each(headers.begin(), headers.end(), [&] (const header_pair & header) {
        pre << "  " << html::element("b", header.first) << ": " << header.second << "\r\n";
      });
    }));
  }) << "\r\n";

  return response;
}
