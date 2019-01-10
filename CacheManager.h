//
// Created by meir on 09/01/19.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H


#include "Searchable.h"

#include <string>
#include <unordered_map>


using namespace std;
template<class Problem, class Solution>


class CacheManager {
public:
    virtual bool isSolutionExist(Problem problem) = 0;

    virtual string extractSolution(Problem problem) = 0;

    virtual void saveSolution(Problem problem, Solution solution) = 0;

    virtual void saveToFile(unordered_map<string, string> solutions);

    virtual void loadFileToMap();



};



#endif //EX4_CACHEMANAGER_H
