#include <rpc/client.h>

#include <iostream>
#include <string>
#include <thread>
#include <tuple>

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << "Usage: ./executable address port\n";
    std::cerr << "Example: ./reader 0.0.0.0 50005\n";
    return -1;
  }

  std::string address = argv[1];
  uint16_t port = std::atoi(argv[2]);
  rpc::client client(address, port);

  auto last_message_id = client.call("getLastId").as<int64_t>();
  while (true) {
    auto next_id = client.call("getLastId").as<int64_t>();
    for (; last_message_id < next_id; ++last_message_id) {
        auto message = client.call("getMessageById", last_message_id).as<std::string>();
        std::cout << message << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  return 0;
}
