#include "catch.h"
#include "element.h"
#include <sstream>

TEST_CASE("html::element") {
  SECTION("simple content element") {
    html::element title_element("title", "Hello, world!");

    REQUIRE(title_element.str() == "<title>Hello, world!</title>");
  }

  SECTION("append tag to stream") {
    std::ostringstream response_stream;
    response_stream << html::element("b");

    REQUIRE(response_stream.str() == "<b></b>");
  }

  SECTION("append content to element") {
    html::element title_element("title");
    title_element << "Hello, world!";

    REQUIRE(title_element.str() == "<title>Hello, world!</title>");
  }

  SECTION("set streamable content") {
    html::element number_element("div", 1);

    REQUIRE(number_element.str() == "<div>1</div>");
  }

  SECTION("set nested element") {
    html::element container_element("div", html::element("div"));

    REQUIRE(container_element.str() == "<div><div></div></div>");
  }

  SECTION("initialize with block") {
    const std::function<void(html::element &)> content_handler = [] (html::element & element) {
      element << html::tag("img", { { "src", "sample-image.jpg" } }) << "\r\n";
      element << html::tag("br");
    };

    html::element complex_element("div", content_handler);

    REQUIRE(complex_element.str() == "<div><img src=sample-image.jpg>\r\n<br></div>");
  }
}
