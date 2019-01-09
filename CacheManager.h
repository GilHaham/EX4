//
// Created by meir on 09/01/19.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H


#include "ISearchable.h"
#include "Solution.h"

template <class T>
class CacheManager {

    bool isSolutionExist(ISearchable<T> searchable);

    Solution extractSolution();

    void saveSolution();

};


#endif //EX4_CACHEMANAGER_H
