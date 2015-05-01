#import <sstream>
#import "catch.h"
#import "response.h"

TEST_CASE("http::response") {
  http::response response;

  REQUIRE(response.status() == 200);
  REQUIRE(response.http_major_version() == 1);
  REQUIRE(response.http_minor_version() == 0);
  REQUIRE(response.content_type() == "text/plain");
  REQUIRE(response.content_length() == 0);

  std::ostringstream response_str;
  response_str << response;
  REQUIRE(response_str.str() == "HTTP/1.0 200 \r\nContent-Length: 0\r\nContent-Type: text/plain\r\n\r\n");
}
