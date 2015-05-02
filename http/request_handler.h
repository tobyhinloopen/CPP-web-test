#import "request.h"
#import "response.h"
#import <memory>
#import <functional>

namespace http {
  typedef std::function<response(const request &)> request_handler;
}
