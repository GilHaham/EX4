//
// Created by meir on 10/01/19.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "Solver.h"
#include "CacheManager.h"
#include "ClientHandler.h"
#include <iostream>

//using namespace std;
//
//class MyTestClientHandler: public ClientHandler {
//
//private:
//    Solver<string, string>* solver;
//    CacheManager* cacheManager;
//
//public:
//    /* constructor*/
//    MyTestClientHandler(Solver<string, string> *solver1, CacheManager *cacheManager1) {
//        this->solver = solver1;
//        this->cacheManager = cacheManager1;
//    }
//    string handleClient(int socket) override;
//    void writeSolution(int id, char* buffer);
//};
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "string"

using namespace std;

class MyTestClientHandler : public ClientHandler {
    Solver<string, string> *solver;
    CacheManager *cm;

public:
    MyTestClientHandler(Solver<string, string> *s, CacheManager* cm1) {
        solver = s;
        cm = cm1;
    }
    MyTestClientHandler() {

    }


    virtual string handleClient(int newsockfd);

    //void writeSoultion(int id,char* buffer);
    string read_until(int sockfd, string sep);
    CacheManager* getCacheManager(){
        return this->cm;
    }

};



#endif //EX4_MYTESTCLIENTHANDLER_H
