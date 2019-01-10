#include <iostream>
#include "State.h"
#include "Point.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
//#include "SearcherAlgo"

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    server_side::Server* mySerialServer = new MySerialServer;
    ClientHandler* myClientHandler = new MyTestClientHandler;
    mySerialServer->openServer(5400, )



    return 0;
}