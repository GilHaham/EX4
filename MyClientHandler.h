//
// Created by meir on 15/01/19.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H


#include "ClientHandler.h"
#include "Solver.h"
#include "Searchable.h"
#include "CacheManager.h"
#include "MatrixProblem.h"

class MyClientHandler: public ClientHandler {



public:

    using Point = std::pair<int, int>;


    Solver<Searchable<pair<int, int>>*, string>* searcher;
    CacheManager  *cacheManager;

    /**
     * the constructor
     *
     * @param searcher search
     * @param cacheManager  cache
     */
    MyClientHandler(CacheManager *cacheManager, Solver<Searchable<pair<int, int>> *, string> *searcher);

    MyClientHandler();

    void handleClient(int socketFd);

    void writeTheSolution(int id,const char* problem);


};


#endif //EX4_MYCLIENTHANDLER_H
