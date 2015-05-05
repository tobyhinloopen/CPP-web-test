#import "catch.h"
#import "response_writer.h"

TEST_CASE("http::request_writer") {
  std::ostringstream response_stream;
  http::response_writer response_writer(response_stream);

  SECTION("empty 200 OK response") {
    http::response response;
    response_writer.write_response(response);

    REQUIRE(response_stream.str() ==
      "HTTP/1.0 200 \r\nContent-Length: 0\r\nContent-Type: text/plain\r\n\r\n");
  }

  SECTION("empty 404 error response") {
    http::response response(404);
    response_writer.write_response(response);

    REQUIRE(response_stream.str() ==
      "HTTP/1.0 404 \r\nContent-Length: 0\r\nContent-Type: text/plain\r\n\r\n");
  }

  SECTION("sample text response") {
    http::response response(200, "Sample text response\r\n");
    response_writer.write_response(response);

    REQUIRE(response_stream.str() ==
      "HTTP/1.0 200 \r\nContent-Length: 22\r\nContent-Type: text/plain\r\n\r\nSample text response\r\n");
  }
}
