cmake_minimum_required(VERSION 3.22)

project(rps LANGUAGES C CXX)

set(CXX_STANDARD_REQUIRED 20)
set(CXX_STANDARD 20)

add_subdirectory(rpclib)

# client part
add_executable(client
    client/main.cpp
)
target_include_directories(client
    PRIVATE rpclib/include
)
target_link_libraries(client
    PRIVATE rpc
)

# server part
add_executable(server
    server/main.cpp
)
target_include_directories(server
    PRIVATE rpclib/include
)
target_link_libraries(server
    PRIVATE rpc
)


