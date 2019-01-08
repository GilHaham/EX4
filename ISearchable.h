//
// Created by gil on 08/01/19.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "State.h"
#include <set>

template <class T>
class ISearchable {
public:
    virtual State<T> getInitialState()=0;
    virtual State<T> getGoalState()=0;
//    std::set <State*> getAllPossibleStates(State* state);
    virtual std::vector<State<T>> getAllPossibleStates(State<T> state)=0;
    virtual bool isGoal(State<T>)=0;

};


#endif //EX4_SEARCHABLE_H
