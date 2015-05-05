#include "catch.h"
#include "tag.h"
#include <sstream>

TEST_CASE("html::tag") {
  SECTION("simple open tag") {
    html::tag title_tag("title");

    REQUIRE(title_tag.str() == "<title>");

    SECTION("with simple attribute") {
      title_tag["id"] = "foo";

      REQUIRE(title_tag.str() == "<title id=foo>");
    }

    SECTION("with boolean attribute") {
      title_tag["required"] = "";

      REQUIRE(title_tag.str() == "<title required>");
    }

    SECTION("with undone boolean attribute") {
      title_tag["required"] = "foo";
      title_tag.remove_attribute("required");

      REQUIRE(title_tag.str() == "<title>");
    }
  }

  SECTION("initialized tag with attributes") {
    html::tag tag_with_attrs("input", {
      { "type", "text" },
      { "disabled", "" }
    });

    REQUIRE(tag_with_attrs.str() == "<input disabled type=text>");
  }

  SECTION("end tag") {
    html::tag end_tag("/title");
    REQUIRE(end_tag.str() == "</title>");
  }

  SECTION("append tag to stream") {
    std::ostringstream response_stream;
    response_stream << html::tag("b");
    REQUIRE(response_stream.str() == "<b>");
  }
}
