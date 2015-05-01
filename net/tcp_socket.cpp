#import "tcp_socket.h"
#import <iostream>

#include <sys/socket.h>

net::tcp_socket::tcp_socket(int socket_id, struct sockaddr_in socket_address):
socket_id(socket_id),
socket_address(socket_address),
socket_stream_buffer(socket_id),
cin(&socket_stream_buffer),
cout(&socket_stream_buffer) {
}

net::tcp_socket::~tcp_socket() {
  cout.flush();
  shutdown(socket_id, SHUT_RDWR);
}
