cmake_minimum_required(VERSION 3.22)

project(chat LANGUAGES CXX)

# server part
add_executable(server
    server/main.cpp
    
    server/user.hpp
)
set_target_properties(server
    PROPERTIES
    CXX_STANDARD 20
)
target_include_directories(server
    PRIVATE rpclib/include
)
target_link_libraries(server
    PRIVATE rpc
)

# writer part
add_executable(writer
    writer/main.cpp
)
target_include_directories(writer
    PRIVATE rpclib/include
)
target_link_libraries(writer
    PRIVATE rpc
)

# reader part
add_executable(reader
    reader/main.cpp
)
target_include_directories(reader
    PRIVATE rpclib/include
)
target_link_libraries(reader
    PRIVATE rpc
)
