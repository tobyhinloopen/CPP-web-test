#import <string>

namespace http {
  class request {
  public:
    request(std::string method, std::string request_uri);
    request(std::string remote_address, std::string method, std::string request_uri);
    void remote_address(std::string remote_address);
    const std::string remote_address() const;
    const std::string method() const;
    const std::string request_uri() const;
  private:
    std::string remote_address_;
    std::string method_;
    std::string request_uri_;
  };
}
