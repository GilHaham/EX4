//
// Created by gil on 15/01/19.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H

#include <iostream>
#include "Searcher.h"

using namespace std;


template<class Node>
class BFS : public Searcher {

private:
    int NumberOfNodesEvaluated = 0;
    list<State<Node>> queue;

public:

    string search(Searchable<Node> *searchable) override {

        State<Node> currentState = searchable->getInitialNode();
        State<Node> goalState = searchable->getGoalNode();  //maybe dangerous ...
        queue.emplace_back(currentState);
        //TODO visited\notVisited
        list<State<Node>>::iterator iterator1 = searchable->getInitialNode();


        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            currentState = queue.front(); //Removing that vertex from queue,whose neighbour will be visited now
            queue.pop_front();

            this->NumberOfNodesEvaluated++;

            if (currentState.getNode() == searchable->getGoalNode()) {
                return searchable.; //TODO - need to check if its not block from getting ahead all the possible states.
            }



            vector<State<Node>> neighbors = searchable->getPossibleStates(currentState);
            for (State<Node> neighbor : neighbors) {
                if (closed.count(neighbor) > 0) {
                    continue;
                } else {
                    open.push(neighbor);
                }
            }

        }

    }


    virtual int getNumberOfNodesEvaluated() override {
        return this->NumberOfNodesEvaluated;
    }

};

#endif //EX4_BFS_H
