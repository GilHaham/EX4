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
#include "Point.h"

//TODO- initialize cameFrom

template <class T>
class State {

private:
    T state;
    double cost; //
    State<T>* cameFrom; //aba

public:

    bool operator == (const State<T>* &b) const{
        return this->cost == b->cost;
    }
    bool operator == (const State<Point>* &b){
        return this->cost == b->cost;
    }


    bool operator < (const State<T>* &b) const{
        return this->cost < b->cost;
    }
    bool operator >(const State<T>* &b) const{
        return this->cost > b->cost;
    }


    bool operator()(const State<T>* left , const State<T>* right){
        return left->getCost() >right->getCost();
    }


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

    void setCameFrom(State<T> *cameFrom) {
        State::cameFrom = cameFrom;
    }

    void setState(T state) {
        State::state = state;
    }

    void setCost(double cost) {
        State::cost = cost;
    }






};
#endif //EX4_STATE_H


