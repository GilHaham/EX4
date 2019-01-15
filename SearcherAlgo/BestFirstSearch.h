//
// Created by meir on 08/01/19.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "../Searcher.h"
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

template<class T, class Solution>
class BestFirstSearch : public Searcher<T, Solution> {
    class Comp { //for priorityQueue
    public:
        bool operator()(State<T> left, State<T> right) {
            return (left.getCost()) > (right.getCost());
        }

    };
private:
    int numberOfNodesEvaluated = 0;
    double totalCost = 0;
public:
    priority_queue<State<T> *, vector<State<T> *>, Comp> updateQueueOpen(priority_queue<State<T> *, vector<State<T> *>,
            Comp> open) {
        priority_queue<State<T> *, vector<State<T> *>, Comp> temp;
        while (!open.empty()) {
            State<T> *node = open.top();
            temp.push(node);
            open.pop();
        }
        return temp;
    }

    Solution search(Searchable<T> *searchable) {
        priority_queue<State<T>, vector<State<T>>, Comp> open;

        set<State<T>> closed;

        double tempCost = 0;
        double value;
        open.push(searchable->getInitialState());

        while (!open.empty()) {
            /*extract node from open list -> NodesEvaluated++ */
            State<T> n = open.top();
            open.pop();
            numberOfNodesEvaluated++;

            if (closed.count(n) != 0) {
                continue;
            }

            closed.insert(n);

            if (n.getNode() == searchable->getGoalNode()) {
                vector<State<T>> pathSolution;
                pathSolution.emplace_back(n.getNode());
                this->totalCost+= n.getCost();
                while (n.getNode() != searchable->getInitialNode()){
                    pathSolution.push_back(n.getCameFrom()->getNode());

                }


                return n; //TODO - need to check if its not block from getting ahead all the possible states.
            }

            vector<State<T>> neighbors = searchable->getPossibleStates(n);
            for (State<T> neighbor : neighbors) {
                if (closed.count(neighbor) > 0) {
                    continue;
                } else {
                    open.push(neighbor);
                }
            }
    }

    return searchable->getInitialState(); //TODO - why this is what we bring back?
}

bool InClosed(State<T> *state, vector<State<T> *> statesClosed) {
    for (State<T> *s : statesClosed) {
        if (state->getNode() == s->getNode()) {
            return true;
        }
    }
    return false;
}

    //TODO
int getNumberOfNodesEvaluated() {
    return this->numberOfNodesEvaluated;
}

};


#endif //EX4_BESTFIRSTSEARCH_H