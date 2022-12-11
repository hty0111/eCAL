cmake_minimum_required(VERSION 3.0)
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG ON)

project(Project)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

find_package(eCAL REQUIRED)
find_package(Protobuf REQUIRED)

add_executable(hello_world_snd src/hello_world/hello_world_snd.cpp)
target_link_libraries(hello_world_snd eCAL::core)

add_executable(hello_world_rec src/hello_world/hello_world_rec.cpp)
target_link_libraries(hello_world_rec eCAL::core)

include_directories(${PROTOBUF_INCLUDE_DIRS})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS src/learning_proto/Person.proto)

add_executable(proto_snd src/learning_proto/proto_snd.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(proto_snd eCAL::core protobuf::libprotobuf)

#include_directories(${CMAKE_CURRENT_BINARY_DIR})
#add_executable(proto_snd src/learning_proto/proto_snd.cpp)
#protobuf_target_cpp(proto_snd ${CMAKE_CURRENT_SOURCE_DIR}/src/learning_proto/ ${CMAKE_CURRENT_SOURCE_DIR}/src/learning_proto/Person.proto)

add_executable(proto_rec src/learning_proto/proto_rec.cpp ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(proto_rec eCAL::core protobuf::libprotobuf)
