#import <ostream>
#import <sstream>

namespace http {
  class response {
  public:
    response();
    response(std::string body);
    response(unsigned short status);
    response(unsigned short status, std::string body);
    unsigned short status() const;
    const std::string content_type() const;
    size_t content_length() const;
    const std::string body() const;

    template<class T> response & operator<<(const T & fragment) {
      body_ << fragment;
      return *this;
    }
  private:
    unsigned short status_;
    std::ostringstream body_;
  };
}
