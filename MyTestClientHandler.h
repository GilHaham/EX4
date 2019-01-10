//
// Created by meir on 10/01/19.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <iostream>

using namespace std;

class MyTestClientHandler: public ClientHandler {

private:
    Solver<string, string>* solver;
    CacheManager<string, string>* cacheManager;

public:
    /* constructor*/
    MyTestClientHandler(Solver<string, string> *solver1, CacheManager<string, string> *cacheManager1) {
        this->solver = solver1;
        this->cacheManager = cacheManager1;
    }

    string handleClient(string str);
};


#endif //EX4_MYTESTCLIENTHANDLER_H
