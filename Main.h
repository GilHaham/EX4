//
// Created by meir on 10/01/19.
//

#ifndef EX4_MAIN_H
#define EX4_MAIN_H


#include "MySerialServer.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

namespace boot {
    class Main;
}

class boot::Main {
public:
    void main(int port){
    Solver<string, string> *solver = new StringReverser();
    CacheManager *cacheManager = new FileCacheManager();
        auto c = new MyTestClientHandler(solver,cacheManager);
        auto mySerialServer = new MySerialServer();
        mySerialServer->openServer(port,c);
    }
};


#endif //EX4_MAIN_H
