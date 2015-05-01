#import "socket_stream_buffer.h"
#import <iostream>

#include <sys/socket.h>

net::socket_stream_buffer::socket_stream_buffer(int socket_id):
socket_id(socket_id) {
  setg(input_buffer.end(), input_buffer.end(), input_buffer.end());
  setp(output_buffer.begin(), output_buffer.end()-1);
}

net::socket_stream_buffer::~socket_stream_buffer() {
  flush();
}

int net::socket_stream_buffer::underflow() {
  if(gptr() < egptr()) {
    std::cout << "Buffer not exhausted? Why underflow?" << std::endl;
    return traits_type::to_int_type(*gptr());
  }

  auto number_of_bytes = recv(socket_id, input_buffer.begin(), buffer_size, 0);
  if(number_of_bytes > 0) {
    setg(input_buffer.begin(), input_buffer.begin(), input_buffer.begin() + number_of_bytes);
    return traits_type::to_int_type(*gptr());
  } else if(number_of_bytes == 0) {
    return traits_type::eof();
  } else {
    std::cout << "Something went terribly wrong receiving from socket." << std::endl;
    return traits_type::eof();
  }
}

int net::socket_stream_buffer::overflow(int character) {
  if(character == traits_type::eof())
    return traits_type::eof();

  *pptr() = character;
  pbump(1);
  if(flush())
    return character;
  else
    return traits_type::eof();
}

int net::socket_stream_buffer::sync() {
  return flush() ? 0 : -1;
}

bool net::socket_stream_buffer::flush() {
  if(pptr() == pbase())
    return true;
  int number_of_bytes = send(socket_id, pbase(), pptr()-pbase(), 0);
  setp(output_buffer.begin(), output_buffer.end()-1);
  if(number_of_bytes == -1) {
    std::cout << "Failed to write to socket!" << std::endl;
    return false;
  }
  return true;
}
