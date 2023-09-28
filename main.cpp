#include <iostream>
#include <grpcpp/grpcpp.h>

#include "my_service.grpc.pb.h"

using grpc::Server;
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

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  MyServiceImpl service;

  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  server->Wait();
}

int main(int argc, char** argv)
{
    
}