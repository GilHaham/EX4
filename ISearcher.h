//
// Created by gil on 08/01/19.
//

#ifndef EX4_SERARCHER_H
#define EX4_SERARCHER_H


#include "Solution.h"
#include "ISearchable.h"

class ISearcher {

public:
    virtual Solution search(ISearchable searchable)=0;
    virtual int getNumberOfNodesEvaluated()=0;

};


#endif //EX4_SERARCHER_H
