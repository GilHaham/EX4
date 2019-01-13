//
// Created by meir on 13/01/19.
//

#include <memory.h>
#include <zconf.h>
#include <iostream>
#include "MyClientHandler.h"
#include "MatrixProblem.h"

void MyClientHandler::handleClient(int socket) {

    bool isSocketClose = false;
    char buffer[1024];
    int n;
    char delimiter = ',';

    while (!isSocketClose){

        bzero(buffer, 1024);
        cout<<buffer<<endl;
        n = read(socket, buffer, 1023); //read line from simulator to socket.
        cout<<buffer<<endl;
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if (buffer=="end"){
            return ;
        }


//        serverIsConnected = true;

        /* now we take the buffer, saperate to tokens and insert them to vector*/
        vector<double> matrixArgs;
        char* copyString;
        copyString=strtok(buffer, ","); //from the net whole while loop
        while (copyString != NULL) {
            matrixArgs.push_back(stod(copyString)); //insert current token to vector
            copyString = strtok(NULL, ","); //Yaani i++ next token
        }
        cout<<"buffer" << buffer<<endl;
        cout<<"copyString" << copyString<<endl;


    }

}

MyClientHandler::MyClientHandler(CacheManager *cacheManager, Solver<Searchable<Point> *, string> *solver)
        : cacheManager(cacheManager), solver(solver) {}
