#include <rpc/server.h>

#include <iostream>

int main(void) {
    rpc::server server(50005);
    server.bind("hello", [] () {
        std::cout << "Hello world!" << std::endl;
    });
    server.run();

    return 0;
}