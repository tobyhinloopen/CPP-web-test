#import <streambuf>
#import <array>

namespace net {
  class socket_stream_buffer : public std::streambuf {
    const static int buffer_size = 16;
  public:
    socket_stream_buffer(int socket_id);
    ~socket_stream_buffer();
  private:
    int underflow();
    int overflow(int c);
    int sync();
    bool flush();
    std::array<char, buffer_size> input_buffer;
    std::array<char, buffer_size> output_buffer;
    int socket_id;
  };
}
