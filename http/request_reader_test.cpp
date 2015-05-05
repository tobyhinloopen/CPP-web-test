#include <sstream>
#include "catch.h"
#include "request_reader.h"

TEST_CASE("http::request_reader") {
  SECTION("basic request") {
    std::istringstream basic_request_str("GET / HTTP/1.0\r\n\r\n");
    http::request_reader request_reader(basic_request_str);

    auto request = request_reader.accept_request();
    REQUIRE(request->method() == "GET");
    REQUIRE(request->request_uri() == "/");
  }

  SECTION("basic request with headers") {
    std::istringstream basic_request_str("GET / HTTP/1.0\r\nAccept: *\r\n\r\n");
    http::request_reader request_reader(basic_request_str);

    auto request = request_reader.accept_request();
    REQUIRE(request->method() == "GET");
    REQUIRE(request->request_uri() == "/");
    REQUIRE((*request)["Accept"] == "*");
  }
}
