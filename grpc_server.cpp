
#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <jsoncpp/json/json.h> 

#include "build/service.grpc.pb.h"   

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using KeepAliveNs::KeepAliveService;
using KeepAliveNs::Empty;

class KeepAliveServiceImpl final : public KeepAliveService::Service {
public:
  Status KeepAlive(ServerContext* context, const Empty *request, Empty* response) override 
  {
    std::cout << "Method called: keep_alive" << std::endl;
    return Status::OK;
  }
};

std::string readConfig(){
  std::ifstream jsonFile("config/config.json");
  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(jsonFile, root);
  if (!parsingSuccessful) {
    std::cerr << "Error parsing JSON" << std::endl;
  }
    std::string serverAddress = root["grpc"]["server_address"].asString();
    int port = root["grpc"]["port"].asInt();
    std::cout << "Configuration read: server_address = " << serverAddress << ", port = " << port << std::endl;
    
  std::string tmp= serverAddress+":"+std::to_string(port);
  std::cout << tmp <<std::endl;
  return tmp;
}

int main(int argc, char** argv) {

  std::string server_address = readConfig();

  KeepAliveServiceImpl service;
  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();

  return 0;
}
