//
// Created by meir on 09/01/19.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include "Searchable.h"
#include <string>
#include <unordered_map>


using namespace std;
//template<class Problem, class Solution>



class CacheManager {
public:
    virtual bool isSolutionExist(string problem) = 0;

    virtual string extractSolution(string problem) = 0;

    virtual void saveSolutionToMap(string problem, string solution) = 0;

    virtual void saveToFile(unordered_map<string, string> solutions) =0;

    virtual void loadFileToMap()=0;



};



#endif //EX4_CACHEMANAGER_H
