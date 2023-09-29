

cmake_minimum_required(VERSION 3.10)

project(grpc_server)

# Настройка CMake для поиска gRPC.
find_package(Protobuf REQUIRED)
find_package(gRPC REQUIRED)

message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
# Пути к файлам .proto и сгенерированным файлам.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/proto/service.proto)
set(GENERATED_PROTO_FILES ${CMAKE_CURRENT_SOURCE_DIR}/proto/service.grpc.pb.cc)
set(GENERATED_PROTO_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/proto/service.grpc.pb.h)

# Генерация C++ кода из .proto файлов.
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

# Добавление сгенерированных файлов к вашему проекту.
add_executable(${PROJECT_NAME} ${PROTO_SRCS} ${GENERATED_PROTO_FILES} ${GENERATED_PROTO_HEADERS} main.cpp)

# Настройка включаемых директорий.
target_include_directories(${PROJECT_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} # Для доступа к сгенерированным .grpc.pb.h файлам.
)

# Линковка с gRPC и protobuf.
target_link_libraries(${PROJECT_NAME}
    #PRIVATE gRPC::gRPC
    #PRIVATE protobuf::libprotobuf
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
)