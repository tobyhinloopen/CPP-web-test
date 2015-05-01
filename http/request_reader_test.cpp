#import <sstream>
#import "catch.h"
#import "request_reader.h"

TEST_CASE("http::request_reader") {
  std::istringstream basic_request_str("GET / HTTP/1.0\r\n\r\n");
  http::request_reader request_reader(basic_request_str);

  auto request = request_reader.accept_request();
  REQUIRE(request->method() == "GET");
  REQUIRE(request->request_uri() == "/");
}
