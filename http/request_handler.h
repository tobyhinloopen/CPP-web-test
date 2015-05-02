#import "request.h"
#import "response.h"
#import <memory>

namespace http {
  typedef std::function<response(request &)> request_handler;
}
