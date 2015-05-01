#import <string>

namespace http {
  class request {
  public:
    request(std::string method, std::string request_uri);
    std::string method() const;
    std::string request_uri() const;
  private:
    std::string method_;
    std::string request_uri_;
  };
}
