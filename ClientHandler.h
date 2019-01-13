//
// Created by gil on 08/01/19.
//

#include <string>

#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H



class ClientHandler {
public:
    virtual void handleClient(int socket)=0;
};

#endif //EX4_CLIENTHANDLER_H

