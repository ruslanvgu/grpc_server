cmake_minimum_required(VERSION 3.8)

project(grpc_server C CXX)

include(common/common.cmake)

find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)

include_directories(
  "/home/ruslanvgu/.local/include"
 # "/usr/include"
)
#link_directories(
# "/home/ruslanvgu/.local/lib"
# "/usr/lib/x86_64-linux-gnu"
#)

# Proto file
get_filename_component(hw_proto "proto/service.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)


# Установка переменных
#set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
#set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
#set(_REFLECTION grpc++_reflection)
#set(_GRPC_GRPCPP grpc++)
#set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)

message("${_PROTOBUF_PROTOC}")
message("${_GRPC_CPP_PLUGIN_EXECUTABLE}")
message("${_REFLECTION}")
message("${_GRPC_GRPCPP}")
message("${_PROTOBUF_LIBPROTOBUF}")

# Generated sources
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/service.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/service.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/service.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/service.grpc.pb.h")

add_custom_command(
      OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND ${_PROTOBUF_PROTOC}
      ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}"
        --cpp_out "${CMAKE_CURRENT_BINARY_DIR}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
        "${hw_proto}"
      DEPENDS "${hw_proto}")

# Include generated *.pb.h files
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# hw_grpc_proto
add_library(hw_grpc_proto
  ${hw_grpc_srcs}
  ${hw_grpc_hdrs}
  ${hw_proto_srcs}
  ${hw_proto_hdrs})
  
#add_executable(grpc_server "grpc_server.cpp")
#target_link_libraries(hw_grpc_proto
  #  absl::flags
 #   absl::flags_parse
 # ${_REFLECTION}
 # ${_GRPC_GRPCPP}
 # ${_PROTOBUF_LIBPROTOBUF}
 # )

# Targets greeter_[async_](client|server)
foreach(_target grpc_server)
  add_executable(${_target} "${_target}.cpp")
  target_link_libraries(${_target}
    hw_grpc_proto
    absl::flags
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
    jsoncpp_lib
    )
endforeach()


