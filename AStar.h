//
// Created by meir on 16/01/19.
//

#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H




#include "Searcher.h"
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

double distance(pair<int,int> currentNode, pair<int,int> nextNode){
    return abs(currentNode.first - nextNode.first) + abs(currentNode.second - nextNode.second);
}

template<class Node>
class AStar : public Searcher<Node> {
private:
    int numberOfNodesEvaluated;
    double totalCost;
    double heuristic;

    class Comp { //for priorityQueue
    public:
        bool operator()(State<Node> left, State<Node> right) {
            return (left.getCost()) > (right.getCost());
        }

    };

public:
    AStar() {
        this->numberOfNodesEvaluated = 0;
        this->totalCost = 0;
        this->heuristic = 0;
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
            State<Node> nAmp = open.top();
            State<Node> *n = &nAmp;
            open.pop();
            if (closed.count(*n) != 0) { // check that n is not in closed list.
                continue;
            }
            closed.insert(*n);

            this->numberOfNodesEvaluated++;

            if (n->getNode() == searchable->getGoalNode()) { // if this is the goal node.

                vector<Node> path;
                path.push_back(n->getNode());
                while (n->getNode() != searchable->getInitialNode()) {
                    path.push_back(n->getCameFrom()->getNode());
                    this->totalCost += n->getCost();
                    n = n->getCameFrom();
                }
                //last iteration
                this->totalCost += n->getCost();
                vector<Node> back;
                for (long i = path.size() - 1; i >= 0; i--) {
                    back.push_back(path[i]);
                }

                string finalPath;
                finalPath += searchable->getPathSolution(back);
                return finalPath;
            }

            vector<State<Node>> neighbors = searchable->getPossibleStates(*n);
            for (State<Node> neighbor : neighbors) {
                if (closed.count(neighbor) > 0) {
                    heuristic =  distance(neighbor.getNode(), searchable->getGoalNode());
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








#endif //EX4_ASTAR_H
