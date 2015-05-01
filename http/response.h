#import <ostream>

namespace http {
  class response {
  public:
    unsigned short status() const;
    const std::string content_type() const;
    size_t content_length() const;
    friend std::ostream & operator<<(std::ostream &, const http::response &);
  };
  std::ostream & operator<<(std::ostream &, const http::response &);
}
