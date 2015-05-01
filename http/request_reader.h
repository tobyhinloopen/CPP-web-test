#import "request.h"
#import <istream>
#import <memory>

namespace http {
  class request_reader {
  public:
    request_reader(std::istream & input_stream);
    ~request_reader();
    std::unique_ptr<request> accept_request();
  private:
    std::istream & input_stream;
  };
}
