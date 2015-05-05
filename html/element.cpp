#include "element.h"

html::element::element(const std::string tagname): tag(tagname) {
}

html::element::element(const std::string tagname, const html::element::content_handler & fn):
tag(tagname) {
  fn(*this);
};

const std::string html::element::str() const {
  return html::tag::str() + content_.str() + "</" + tagname + '>';
}
