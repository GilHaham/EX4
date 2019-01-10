//
// Created by meir on 07/01/19.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer: public server_side::Server {


    void openServer(int port, ClientHandler* clientHandler) override {

    }

    void stopServer() override {

    }

    bool isOpen() override {
        return false;
    }
};


#endif //EX4_MYSERIALSERVER_H
