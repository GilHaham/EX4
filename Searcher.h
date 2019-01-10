//
// Created by gil on 08/01/19.
//

#ifndef EX4_SERARCHER_H
#define EX4_SERARCHER_H


#include "Searchable.h"
template <class T>
class Searcher {

public:
    virtual std::string search(Searchable<T> searchable)=0;
    virtual int getNumberOfNodesEvaluated()=0;



};


#endif //EX4_SERARCHER_H
