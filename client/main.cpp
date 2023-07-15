#include <rpc/client.h>

#include <iostream>
#include <string>

int main(void) {
  rpc::client client("0.0.0.0", 50005);
  std::cout << "Enter UserName: ";
  std::string input;
  std::getline(std::cin, input);
  auto id = client.call("connect_user", input).as<uint32_t>();
  client.call("connected");
  return 0;
}
