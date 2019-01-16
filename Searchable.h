//
// Created by gil on 08/01/19.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "string"
#include "State.h"
#include <vector>

using namespace std;


template<class Node>

class Searchable {
public:
    virtual State<Node> getInitialState() = 0;

    virtual Node getInitialNode() = 0;

    virtual Node getGoalNode() = 0;

    virtual vector<State<Node>> getPossibleStates(State<Node> s) = 0;

    virtual bool isIndexInMatrixBounds(pair<int, int> point) const = 0;

    virtual string getPathSolution(vector<State<Node> *> pathPoints)=0;

};

#endif //EX4_SEARCHABLE_H
