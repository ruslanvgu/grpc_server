/*#include <iostream>
#include <fstream>
#include <grpcpp/grpcpp.h>
#include <jsoncpp/json/json.h>
#include "proto/service.grpc.pb.h"  
 

void readConfig(){
  std::ifstream jsonFile("config/config.json");
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
}*/


#include <iostream>
#include <fstream>
#include <grpcpp/grpcpp.h>
#include <memory>
//#include <jsoncpp/json/json.h>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"

//ABSL_FLAG(uint16_t, port, 50051, "Server port for the service");

#include "proto/service.grpc.pb.h" 

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
//using package::KeepAliveRequest;
//using package::KeepAliveResponse;
using package::KeepAliveService;

class KeepAliveServiceImpl final : public KeepAliveService::Service {
public:

  Status KeepAlive(ServerContext* context, const package::Empty* request, package::Empty* response) override {
    std::cout << "Method called: keep_alive" << std::endl;
        
    return grpc::Status::OK;
  }

};
/*
void readConfig(){
  std::ifstream jsonFile("config/config.json");
  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(jsonFile, root);
  if (parsingSuccessful) {
    std::string serverAddress = root["grpc"]["server_address"].asString();
    int port = root["grpc"]["port"].asInt();
    std::cout << "Configuration read: server_address = " << serverAddress << ", port = " << port << std::endl;
    
  } else {
    std::cerr << "Error parsing JSON" << std::endl;
  }
}*/


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
