#import <sstream>
#import "catch.h"
#import "response.h"

TEST_CASE("http::response") {
  SECTION("empty 200 OK response") {
    http::response response;

    REQUIRE(response.status() == 200);
    REQUIRE(response.content_type() == "text/plain");
    REQUIRE(response.content_length() == 0);
    REQUIRE(response.body().empty());
  }

  SECTION("empty custom status response") {
    http::response response(404);

    REQUIRE(response.status() == 404);
    REQUIRE(response.content_type() == "text/plain");
    REQUIRE(response.content_length() == 0);
    REQUIRE(response.body().empty());
  }

  SECTION("response with simple text response") {
    http::response response("Sample text response\r\n");

    REQUIRE(response.status() == 200);
    REQUIRE(response.content_type() == "text/plain");
    REQUIRE(response.content_length() == 22);
    REQUIRE(response.body() == "Sample text response\r\n");
  }

  SECTION("response added with << operator") {
    http::response response;
    response << "Sample text response\r\n";

    REQUIRE(response.status() == 200);
    REQUIRE(response.content_type() == "text/plain");
    REQUIRE(response.content_length() == 22);
    REQUIRE(response.body() == "Sample text response\r\n");
  }
}
