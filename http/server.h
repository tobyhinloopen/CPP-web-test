#import "request.h"
#import "response.h"

namespace http {
  class server {
  public:
    server(std::function<http::response(http::request &)> request_handler);
    void listen(unsigned short port);
  private:
    std::function<http::response(http::request &)> request_handler;
  };
}
