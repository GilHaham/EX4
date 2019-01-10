//
// Created by meir on 07/01/19.
//

#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include "Server.h"
#include <stdlib.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <thread>

using namespace std;

struct Args{
    int newsockfd;
};

void listenToClients(ClientHandler* clientHandler1, int sockfd) {
    while (true) {
        /*Start listen to clients*/
        int new_sockfd;
        listen(sockfd, 1);
        struct sockaddr_in client;
        socklen_t clilen = sizeof(client);

        /*If no clients communicate for 1 second - then timeout*/
        timeval timeout;
        timeout.tv_sec = 10;
        timeout.tv_usec = 0;
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeout, sizeof(timeout));

        /*Accept actual connection from the client*/
        new_sockfd = accept(sockfd, (struct sockaddr *) &client, &clilen);
        if (new_sockfd < 0) {
            if (errno == EWOULDBLOCK) { //connection failed beacuse no slient came and we had timeout
                cout << "timeout!" << endl;
                exit(2);
            } else {
                perror("other error");
                exit(3);
            }
        }

        clientHandler1->handleClient(new_sockfd);

        cout << new_sockfd << endl;
        close(new_sockfd);
    }
}

class MySerialServer: public server_side::Server {

    void openServer(int port, ClientHandler* clientHandler) override {

        cout << port << endl;

        /*first call to socket*/
        int socketfd = socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd < 0) {
            perror("Error opening socket");
            exit(1);
        }

        /*Initilize socket structure*/
        struct sockaddr_in serv;
        serv.sin_addr.s_addr = INADDR_ANY;
        serv.sin_port = htons(port);
        serv.sin_family = AF_INET;

        /*check binding*/
        if (bind(socketfd, (sockaddr *) &serv, sizeof(serv)) < 0) {
            cerr << "Bad!" << endl;
        }

        /*Open thread for listening to a client [maybe to soon] */

        thread clientThred(listenToClients, clientHandler, socketfd);

        cout << socketfd << endl;
        close(socketfd);
    }

    void stopServer() override {

    }

    bool isOpen() override {
        return false;
    }
};


#endif //EX4_MYSERIALSERVER_H
