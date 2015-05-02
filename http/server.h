#import "request_handler.h"

namespace http {
  class server {
  public:
    server(request_handler request_handler_);
    void listen(unsigned short port);
  private:
    request_handler request_handler_;
  };
}
