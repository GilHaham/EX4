//
// Created by meir on 13/01/19.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


#include "CacheManager.h"
#include "Solver.h"
#include "Point.h"
#include "ClientHandler.h"

class MyClientHandler : public ClientHandler {
public:
    MyClientHandler(CacheManager *cacheManager, Solver<Searchable<pair<int, int>>*, string> *solver);

private:
    CacheManager* cacheManager;
    Solver<Searchable<pair<int, int>>*, string>* solver;



public:
    void handleClient(int socket) ;


};


#endif //EX4_MYCLIENTHANDLER_H
