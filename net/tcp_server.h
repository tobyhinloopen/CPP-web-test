#import "tcp_socket.h"
#import <arpa/inet.h>
#import <memory>

namespace net {
  class tcp_server {
    static const int listen_backlog_size = 24;
  public:
    tcp_server(unsigned short port);
    ~tcp_server();
    std::unique_ptr<tcp_socket> accept();
  private:
    int socket_id;
    struct sockaddr_in server_address;
  };
}
