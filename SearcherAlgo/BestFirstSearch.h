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

template<class T>
class BestFirstSearch : public Searcher<T> {
    class Comp { //for priorityQueue
    public:
        bool operator()(State<T> left, State<T> right) {
            return (left.getCost()) > (right.getCost());
        }

    };

public:
//    bool isSolExist(priority_queue<State<T>, vector<State<T>>, Comp> open, State<T> state) {
//        while (!open.empty()) {
//            if (state->Equal(open.top())) {
//                return true;
//            }
//            open.pop();
//        }
//        return false;
//    }

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

    State<T> search(Searchable<T> *searchable) {
        priority_queue<State<T>, vector<State<T>>, Comp> open;

        set<State<T>> closed;

        double tempCost = 0;
        double value;
        open.push(searchable->getInitialState());

        while (!open.empty()) {
            State<T> n = open.top();
            open.pop();
            if (closed.count(n) != 0) {
                continue;
            }
            closed.insert(n);

            if (n.getNode() == searchable->getGoalNode()) {
                return n;
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

    return searchable->getInitialState();
}

bool InClosed(State<T> *state, vector<State<T> *> statesClosed) {
    for (State<T> *s : statesClosed) {
        if (state->getNode() == s->getNode()) {
            return true;
        }
    }
    return false;
}

int getNumberOfNodesEvaluated() {
    return 5;
}

};


#endif //EX4_BESTFIRSTSEARCH_H


//                    if (!isSolExist(open, neighbor) && !InClosed(neighbor, closed)) {
//                        neighbor->setCameFrom(n);
//                        tempCost=neighbor->getCost();
//                        neighbor->setCost(neighbor->getCost()+neighbor->getCameFrom()->getCost());
//                        open.insert(neighbor);
//                    }
//                    else if (neighbor->getCameFrom()==NULL) {
//                    }
//                    else if (neighbor->getCost() > tempCost + neighbor->getCameFrom()->getCost() ) {
//                        if (!isSolExist(open, neighbor)) {
//                            open.push(neighbor);
//                            closed.erase(std::remove(closed.begin(), closed.end(), neighbor), closed.end());
//                        }
//                        else {
//                            neighbor->setCameFrom(n);
//                            neighbor->setCost(neighbor->getCost() - neighbor->getCameFrom()->getCost() + n->getCost());
//                            open = updateQueueOpen(open);
//                        }
//                    }
//n is the goal node
//            else {
//                int counter = 0;
//                bool first = true;
//                while (n != NULL) {
//                    if (first) {
//                        searchable->setTotalCost(n->getCost());
//                        cout << searchable->getTotalcost() << endl;
//                        first = false;
//                    }
//                    counter++;
//                    path += to_string((int) n->getCost()) + " ";
//                    totalPoints.push_back(n);
//                    n = n->getCameFrom();
//                }
//                cout << counter << endl;
//                reverse(totalPoints.begin(), totalPoints.end());
//                finalPath = searchable->getPathSolution(totalPoints);
//                return finalPath;
//            }