#include <rpc/server.h>

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::string> chat;

void sendMessage(std::string name, std::string input) {
  chat.push_back(name + ": " + input);
  std::cout << chat.back() << std::endl;
}

uint64_t getLastId() {
  return chat.size();
}

std::string getMessageById(uint64_t message_id) {
  return chat.at(message_id);
}

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "Usage: ./executable address port\n";
    std::cerr << "Example: ./server 0.0.0.0 50005\n";
    return -1;
  }

  std::string address = argv[1];
  uint16_t port = std::atoi(argv[2]);
  rpc::server server(address, port);

  server.bind("sendMessage", sendMessage);
  server.bind("getLastId", getLastId);
  server.bind("getMessageById", getMessageById);
  server.run();

  return 0;
}
