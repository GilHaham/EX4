//
// Created by gil on 15/01/19.
//

#ifndef EX4_BFS_H
#define EX4_BFS_H

#include <iostream>
#include <algorithm>
#include "Searcher.h"
#include <list>
#include <queue>
#define CANT_GO_THROGHT "-1";

using namespace std;


template<class Node>
class BFS : public Searcher<Node> {

    int counter=0;
    int cost=0;

public:
    string search(Searchable<Node> *searchable) {
        vector<State<Node> *> visit;
        string thePath;
        queue<State<Node>*> qu;
        vector<State<Node> *> neighbors;
        State<Node> *current;
        vector<State<Node>*> totalPoints;
        qu.push(searchable->getInitialState());
        visit.push_back(searchable->getInitialState());
        while (!qu.empty()) {
            current = qu.front();
            counter++;
            if(current->Equal(searchable->getGoalState())){
                while (current != NULL) {
                    cost+=current->getCost();
                    totalPoints.push_back(current);
                    current = current->getCameFrom();
                }
                //return the path to the client
                std::reverse(totalPoints.begin(),totalPoints.end());
                thePath= searchable->getPathSolution(totalPoints);
                return thePath;
            }
            neighbors = searchable->getAllPossibleStates(current);
            qu.pop();
            for (State<Node> *neighbor : neighbors) {
                if (!wasVisited(visit,neighbor)) {
                    neighbor->setCameFrom(current);
                    visit.push_back(neighbor);
                    qu.push(neighbor);
                }
            }
        }
        //dead end -  which means we run into "walls" so there is no path
        return CANT_GO_THROGHT;
    }


    bool wasVisited(vector<State<Node> *> visited,State<Node> *current ){
        for (auto state:visited) {
            if (current->Equal(state)) {
                return true;
            }
        }
        return false;
    }

    int getNumberOfNodesEvaluated() {
        return counter;
    }

    virtual double getPathCost() {
        return cost;
    }
};

#endif //EX4_BFS_H
