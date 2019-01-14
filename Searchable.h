//
// Created by gil on 08/01/19.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

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
    double totalCost;

public:
    Searchable(vector<State<T>*> search, State<T>* initial, State<T>* goal){
        this->searchable=search;
        this->initialState=initial;
        this->goalState=goal;
    }


    virtual State<T>* getInitialState() = 0;

    virtual State<T>* getGoalState()=0;

    virtual string getPathSolution(vector<State<T>*> s)=0;

    virtual double getTotalcost() = 0;

    virtual vector<State<T>*> getPossibleStates(State<T> *s)=0;

    virtual void setTotalCost(double num) = 0;

};

#endif //EX4_SEARCHABLE_H
