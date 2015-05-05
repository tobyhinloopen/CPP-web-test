#pragma once

#include "tag.h"
#include <sstream>
#include <functional>
#include <type_traits>

namespace html {
  class element : public tag {
  public:
    typedef std::function<void(element &)> content_handler;

    element(const std::string tagname);
    element(const std::string tagname, const content_handler & fn);

    template<class T>
    element(const std::string tagname, const T & fragment,
    typename std::enable_if<!std::is_convertible<T, content_handler>::value>::type* = 0):
    tag(tagname) {
      (*this) << fragment;
    }

    virtual const std::string str() const;

    template<class T>
    element & operator<<(const T & fragment) {
      content_ << fragment;
      return *this;
    }
  private:
    std::ostringstream content_;
  };
}
