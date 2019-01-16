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

template<class Node>
class BestFirstSearch : public Searcher<Node> {
private:
    int numberOfNodesEvaluated;
    double totalCost;
    class Comp { //for priorityQueue
    public:
        bool operator()(State<Node> left, State<Node> right) {
            return (left.getCost()) > (right.getCost());
        }

    };

public:
    BestFirstSearch(){
        this->numberOfNodesEvaluated =0;
        this->totalCost = 0;
    }

    priority_queue<State<Node> *, vector<State<Node> *>, Comp>
    updateQueueOpen(priority_queue<State<Node> *, vector<State<Node> *>,
            Comp> openList) {
        priority_queue<State<Node> *, vector<State<Node> *>, Comp> temp;
        while (!openList.empty()) {
            State<Node> *node = openList.top();
            temp.push(node);
            openList.pop();
        }
        return temp;
    }

    string search(Searchable<Node> *searchable) {
        priority_queue<State<Node>, vector<State<Node>>, Comp> open;

        set<State<Node>> closed;

        double tempCost = 0;
        double value;
        open.push(searchable->getInitialState());

        while (!open.empty()) {
            State<Node> n = open.top();
            open.pop();
            if (closed.count(n) != 0) { // check that n is not in closed list.
                continue;
            }
            closed.insert(n);

            this->numberOfNodesEvaluated++;

            if (n.getNode() == searchable->getGoalNode()) { // if this is the goal node.
//                searchable->getPathSolution(closed)
//            vector<State<T>*> path = this->ThePath(searchable->getGoalState());
//                string solution = searchable->WhereToGo(path);
//                return solution;
//                return to_string(n.getCost());
            }

            vector<State<Node>> neighbors = searchable->getPossibleStates(n);
            for (State<Node> neighbor : neighbors) {
                if (closed.count(neighbor) > 0) {
                    continue;
                } else {
                    open.push(neighbor);
                }
            }
        }

        return to_string(searchable->getInitialState().getCost());
    }

    bool InClosed(State<Node> *state, vector<State<Node> *> statesClosed) {
        for (State<Node> *s : statesClosed) {
            if (state->getNode() == s->getNode()) {
                return true;
            }
        }
        return false;
    }

    int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }

};


#endif //EX4_BESTFIRSTSEARCH_H