#import "catch.h"
#import "request.h"

TEST_CASE("http::request") {
  SECTION("simple request") {
    http::request request("GET", "/");

    REQUIRE(request.method() == "GET");
    REQUIRE(request.request_uri() == "/");
    REQUIRE(request["X-Foo"] == "");
    REQUIRE(request.headers().empty());
  }

  SECTION("request with headers") {
    http::header_set header_set;
    header_set["X-Foo"] = "Bar";
    http::request request("GET", "/", header_set);

    REQUIRE(request.method() == "GET");
    REQUIRE(request.request_uri() == "/");
    REQUIRE(request["X-Foo"] == "Bar");
    REQUIRE(request.headers().size() == 1);
  }
}
