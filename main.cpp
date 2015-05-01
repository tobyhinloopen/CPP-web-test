#import "http/response.h"
#import "net/tcp_server.h"

int main() {
  std::cout << "Starting server @8080" << std::endl;
  net::tcp_server server(8080);
  while(true) {
    auto client = server.accept();
    std::string line;
    std::getline(client->cin, line);
    client->cout << line << "\r\n";
  }
  return 0;
}
