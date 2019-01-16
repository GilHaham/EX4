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

using namespace std;


template<class Node>
class State {
private:
    Node node;
    double cost{};          // total cost
    State<Node> *cameFrom;  // father

public:

    bool operator<(const State<Node> other) const  {
        if (node.first == other.node.first)  {
            return node.second < other.node.second;
        }
        return node.first < other.node.first;
    }
    State(Node state, double cost, State<Node> *cameFrom = nullptr) {
        this->cost = cost;
        this->node = state;
        this->cameFrom = cameFrom;
    }

    State() {}

    Node getNode() const {
        return this->node;
    }

    State *getCameFrom() const {
        return this->cameFrom;
    }

    double getCost() const {
        return this->cost;
    }

    void setNode(Node node) {
        State::node = node;
    }

};

#endif //EX4_STATE_H


