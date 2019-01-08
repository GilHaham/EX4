//
// Created by gil on 08/01/19.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H

#include <cstdio>
#include <stdlib.h>
#include <string>
#include <list>
#include <map>
#include <vector>

//TODO- initialize cameFrom

template <class T>
class State {

private:
    T state;
    double cost;
    State<T>* cameFrom;

public:
    State(T state1){
      this->state = state1;
    }

    bool Equals(State<T>* state1){
        return (this->state == state1->state);
    }

    T &getState(){
        return this->state;
    }

    State *getCameFrom() {
        return this->cameFrom;
    }

    double getCost(){
        return this->cost;
    }


};
#endif //EX4_STATE_H


