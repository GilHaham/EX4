//
// Created by meir on 09/01/19.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H


#include "ISearchable.h"

template <class T, class Solution>
class CacheManager {

    virtual bool isSolutionExist(ISearchable<T> searchable)=0;

    virtual Solution extractSolution()=0;

    virtual void saveSolution()=0;

};


#endif //EX4_CACHEMANAGER_H
