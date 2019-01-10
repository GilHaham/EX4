//
// Created by meir on 07/01/19.
//

#ifndef EX4_SERVER_H
#define EX4_SERVER_H


#include "ClientHandler.h"

namespace server_side {
    class Server {
        virtual void openServer (int port, ClientHandler* clientHandler) =0;
        virtual void stopServer ()=0;
        virtual bool isOpen()= 0;
    };
}

#endif //EX4_SERVER_H
