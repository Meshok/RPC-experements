#include <rpc/client.h>

#include <iostream>

int main(void) {
    rpc::client client("0.0.0.0", 50005);
    client.call("hello");
    return 0;
}