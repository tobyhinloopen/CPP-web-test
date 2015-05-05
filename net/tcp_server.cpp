#import "tcp_server.h"
#import "accept_failed_exception.h"
#import "bind_failed_exception.h"
#import "socket_failed_exception.h"
#import <memory>
#import <stdio.h>
#import <string.h>
#import <sys/socket.h>
#import <arpa/inet.h>
#import <unistd.h>

net::tcp_server::tcp_server(unsigned short port) {
  socket_id = socket(AF_INET , SOCK_STREAM, 0);

  if(socket_id == -1)
    throw socket_failed_exception();

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(port);

  if(bind(socket_id, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    throw bind_failed_exception();

  listen(socket_id, listen_backlog_size);
}

net::tcp_server::~tcp_server() {
  shutdown(socket_id, SHUT_RDWR);
}

std::unique_ptr<net::tcp_socket> net::tcp_server::accept() {
  struct sockaddr_in client_socket_addr;

  int sizeof_socket_addr = sizeof(struct sockaddr_in);
  const int client_socket_id = ::accept(socket_id, (struct sockaddr *)&client_socket_addr, (socklen_t*)&sizeof_socket_addr);

  if(client_socket_id < 0)
    throw accept_failed_exception();

  return std::unique_ptr<tcp_socket>(new net::tcp_socket(client_socket_id, client_socket_addr));
}
