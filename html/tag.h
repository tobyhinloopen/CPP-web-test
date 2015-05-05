#pragma once

#include <string>
#include <map>
#include <ostream>
#include "attribute_set.h"

namespace html {
  class tag {
  public:
    tag(std::string tagname);
    tag(std::string tagname, attribute_set attributes);
    virtual ~tag();
    virtual const std::string str() const;
    std::string & operator[](const std::string key);
    void remove_attribute(const std::string key);
    friend std::ostream & operator<<(std::ostream &, const tag &);
  private:
    void write_attribute_value(std::ostream & out, const std::string value) const;
  protected:
    const std::string tagname;
  private:
    attribute_set attributes;
  };
  std::ostream & operator<<(std::ostream &, const tag &);
}
