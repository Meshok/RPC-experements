#include <rpc/client.h>

#include <iostream>
#include <string>

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "Usage: ./executable address port\n";
    std::cerr << "Example: ./writer 0.0.0.0 50005\n";
    return -1;
  }

  std::string address = argv[1];
  uint16_t port = std::atoi(argv[2]);
  rpc::client client(address, port);

  std::string name;
  std::cout << "Enter UserName: ";
  std::getline(std::cin, name);

  std::string input;
  while (true) {
    std::cout << "Enter text here: ";
    std::getline(std::cin, input);
    client.call("sendMessage", name, input);
  }

  return 0;
}
