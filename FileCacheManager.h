//
// Created by meir on 10/01/19.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H


#include "CacheManager.h"

#include "CacheManager.h"
#include "Server.h"
#include "DataBase.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace server_side;
//template<class string, class string>

class FileCacheManager: public CacheManager{
    unordered_map<string, string> solutionsMap;
    int flag;

public:

    FileCacheManager() {
        this->flag = 0;
    }

    virtual bool isExist(string problem);
    virtual string popSolution(string problem);
    virtual void saveSolution(string problem, string solution);
    virtual void saveToFile(unordered_map<string, string> solutions);
    virtual void loadFileToMap();

    bool isSolutionExist(string problem) override;

    string extractSolution(string problem) override;



};


#endif //EX4_FILECACHEMANAGER_H
