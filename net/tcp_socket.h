#import "socket_stream_buffer.h"
#import <iostream>
#import <arpa/inet.h>

namespace net {
  class tcp_socket {
  public:
    tcp_socket(int socket_id, struct sockaddr_in socket_address);
    ~tcp_socket();
    std::string remote_address() const;
  private:
    const int socket_id;
    const struct sockaddr_in socket_address;
    net::socket_stream_buffer socket_stream_buffer;
  public:
    std::istream cin;
    std::ostream cout;
  };
}
