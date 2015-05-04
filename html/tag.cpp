#import "tag.h"
#import <sstream>
#import <algorithm>

html::tag::tag(std::string tagname): tag(tagname, {}) {
}

html::tag::tag(std::string tagname, html::attribute_set attributes):
tagname(tagname), attributes(attributes) {
}

html::tag::~tag() {
}

std::string & html::tag::operator[](const std::string key) {
  return attributes[key];
}

void html::tag::remove_attribute(const std::string key) {
  attributes.erase(key);
}

const std::string html::tag::str() const {
  if(attributes.empty())
    return "<" + tagname + ">";

  std::ostringstream html;
  html << '<' << tagname;
  std::for_each(attributes.begin(), attributes.end(), [&] (const html::attribute_pair & attribute_pair) {
    const std::string key = attribute_pair.first, value = attribute_pair.second;
    html << ' ' << key;
    write_attribute_value(html, value);
  });
  html << '>';
  return html.str();
}

std::ostream & html::operator<<(std::ostream & out, const html::tag & tag) {
  return out << tag.str();
}

void html::tag::write_attribute_value(std::ostream & html, const std::string value) const {
  if(!value.empty())
    html << '=' << value;
}
