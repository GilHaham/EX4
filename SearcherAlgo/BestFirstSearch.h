//
// Created by meir on 08/01/19.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "../Searcher.h"
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class BestFirstSearch: public Searcher<T> {
    class Comp {
    public:
        bool operator()(State<T>* left, State<T>* right) {
            return (left->getCost()) > (right->getCost());
        }

    };
public:
    bool isSolExist(priority_queue<State<T> *, vector<State<T> *>, Comp> open, State<T> *state) {
        while (!open.empty()) {
            if (state->Equals(open.top())) {
                return true;
            }
            open.pop();
        }
        return false;
    }

    priority_queue<State<T> *, vector<State<T> *>, Comp> updateQueueOpen(priority_queue<State<T> *, vector<State<T> *>,
            Comp> open) {
        priority_queue<State<T> *, vector<State<T> *>, Comp> temp;
        while (!open.empty()) {
            State<T>* node = open.top();
            temp.push(node);
            open.pop();
        }
        return temp;
    }

    string search(Searchable<T> *searchable) {
        priority_queue<State<T> *, vector<State<T> *>, Comp> open;
        vector<State<T>*> closed;
        vector<State<T>*> totalPoints;
        string path="";
        string finalPath="";
        double tempCost=0;
        double value;
        open.push(searchable->getInitialState());
        while (!open.empty()) {
            State<T> *n = open.top();
            closed.push_back(n);
            // TODO check Equals compare cost == cost, not state == state.
            if ((n->Equals(searchable->getInitialState())) && n->getCost() == -1) {
                path = "-1";
                return path;
            }
            open.pop();
            if (!n->Equals(searchable->getGoalState())) {
                vector<State<T> *> neighbors = searchable->getPossibleStates(n);
                for (State<T> *neighbor : neighbors) {
                    if (!isSolExist(open, neighbor) && !InClosed(neighbor, closed)) {
                        neighbor->setCameFrom(n);
                        tempCost=neighbor->getCost();
                        neighbor->setCost(neighbor->getCost()+neighbor->getCameFrom()->getCost());
                        open.push(neighbor);
                    }
                    else if (neighbor->getCameFrom()==NULL) {
                        continue;
                    }
                    else if (neighbor->getCost() > tempCost + neighbor->getCameFrom()->getCost() ) {
                        if (!isSolExist(open, neighbor)) {
                            open.push(neighbor);
                            closed.erase(std::remove(closed.begin(), closed.end(), neighbor), closed.end());
                        }
                        else {
                            neighbor->setCameFrom(n);
                            neighbor->setCost(neighbor->getCost() - neighbor->getCameFrom()->getCost() + n->getCost());
                            open = updateQueueOpen(open);
                        }
                    }
                }
            }
                //n is the goal state
            else {
                int counter=0;
                bool first = true;
                while (n != NULL) {
                    if (first) {
                        searchable->setTotalCost(n->getCost());
                        cout<< searchable->getTotalcost()<<endl;
                        first=false;
                    }
                    counter++;
                    path+=to_string((int) n->getCost())+" ";
                    totalPoints.push_back(n);
                    n = n->getCameFrom();
                }
                cout << counter<<endl;
                reverse(totalPoints.begin(),totalPoints.end());
                finalPath= searchable->getPathSolution(totalPoints);
                return finalPath;
            }
        }
        return path;
    }

    bool InClosed(State<T> *state, vector<State<T> *> statesClosed) {
        for (State<T> *s : statesClosed) {
            if (state->Equals(s)) {
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
