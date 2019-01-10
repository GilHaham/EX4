//
// Created by gil on 08/01/19.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

//#include "State.h"
//#include <set>

//template <class T>
//class Searchable {
//public:
//    virtual State<T> getInitialState()=0;
//    virtual State<T> getGoalState()=0;
//    virtual std::vector<State<T>> getAllPossibleStates(State<T> state)=0;
//    virtual bool isGoal(State<T>)=0;
//
//};

#include "string"
#include "State.h"
#include <vector>

using namespace std;

template <class T>
class Searchable {
protected:
    vector<State<T>*> searchable;
    State<T>* initialState;
    State<T>* goalState;
public:
    Searchable(vector<State<T>*> search, State<T>* initial, State<T>* goal){
        this->searchable=search;
        this->initialState=initial;
        this->goalState=goal;
    }
    virtual State<T>* getInitialState() = 0;

    virtual State<T>* getGoalState()=0;

    virtual vector<State<T>*> getAllPossibleStates(State<T>* s)=0;

    virtual string getPathSolution(vector<State<T>*> s)=0;
};

#endif //EX4_SEARCHABLE_H
