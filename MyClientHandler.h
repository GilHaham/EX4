//
// Created by meir on 13/01/19.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


#include "CacheManager.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include "Solver.h"
#include "Point.h"
#include "ClientHandler.h"
#include <iostream>
#include <cstdlib>

using namespace std;

template<class Node>
class MyClientHandler : public ClientHandler {
    CacheManager *cacheManager;
    Solver<Searchable<Node> *, State<Node>> *solver;
public:
    void handleClient(int sock) override;

    MyClientHandler(CacheManager *cacheManager, Solver<Searchable<Node> *, State<Node>> *solver);

};


template<class Node>
void MyClientHandler<Node>::handleClient(int sock) {

    cout << "Handler!" << endl;
    bool isSocketClose = false;
    char buffer[1024];
    int n;
    char delimiter = ',';

    while (!isSocketClose) {


        memset(buffer, 0, 1024);
        n = read(sock, buffer, 1023); //read line from simulator to sock.
        if (n < 0) {
            perror("ERROR reading from sock");
            exit(1);
        }

        buffer[n] = 0;
        write(sock, buffer, n);

//        serverIsConnected = true;

        /* now we take the buffer, saperate to tokens and insert them to vector*/
        vector<double> matrixArgs;
        char *copyString;
        copyString = strtok(buffer, ","); //from the net whole while loop
        while (copyString != NULL) {
            matrixArgs.push_back(stod(copyString)); //insert current token to vector
            copyString = strtok(NULL, ","); //Yaani i++ next token
        }


    }

}

template<class Node>
MyClientHandler<Node>::MyClientHandler(CacheManager *cacheManager, Solver<Searchable<Node> *, State<Node>> *solver)
        : cacheManager(cacheManager), solver(solver) {}


#endif //EX4_MYCLIENTHANDLER_H
