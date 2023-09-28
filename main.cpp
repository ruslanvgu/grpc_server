#include <iostream>
#include <json/json.h>
#include <grpcpp/grpcpp.h>

#include "my_service.grpc.pb.h"

/*using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using my_package::MyService;
using my_package::RequestMessage;
using my_package::ResponseMessage;

class MyServiceImpl final : public MyService::Service {
  Status MyMethod(ServerContext* context, const RequestMessage* request, ResponseMessage* response) override {
    std::string request_field = request->request_field();
    std::string response_field = "Hello, " + request_field;
    response->set_response_field(response_field);
    return Status::OK;
  }
};

}*/
void readConfig(){
  std::ifstream jsonFile("config.json");
  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(jsonFile, root);
  if (parsingSuccessful) {
    std::string serverAddress = root["grpc"]["server_address"].asString();
    int port = root["grpc"]["port"].asInt();
    
  } else {
    // Ошибка парсинга JSON
  }
}


class KeepAliveServiceImpl final : public KeepAliveService::Service {
public:
  grpc::Status KeepAlive(grpc::ServerContext* context, const Empty* request, Empty* response) override {
    std::cout << "Method called: keep_alive" << std::endl;
    //  логика здесь, например:
    // doSomething();
    return grpc::Status::OK;
  }
};


int main(int argc, char** argv) {

  


  std::string server_address("0.0.0.0:50051");

  KeepAliveServiceImpl service;
  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();

  return 0;
}

//protoc -I <путь_к_файлу_proto> --grpc_out=<путь_для_генерации_кода> --plugin=protoc-gen-grpc=<путь_к_grpc_cpp_plugin> <путь_к_файлу_proto>
//
//g++ -std=c++11 service.pb.cc service.grpc.pb.cc main.cpp -o server `pkg-config --cflags --libs grpc++ grpc`
