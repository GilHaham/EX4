//
// Created by meir on 16/01/19.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H


#include "Searcher.h"
#define CANT_GO_THROGHT "-1";
#include <stack>
#include "string"


using namespace std;


template<class Node>
class DFS : public Searcher<Node> {



    int cost = 0;
    int counter=0;
public:
    string search(Searchable<Node> *searchable) {
        stack<State<Node> *> qu;
        vector<State<Node> *> neighbors;
        vector<State<Node>*> totalPoints;
        vector<State<Node> *> visited;
        State<Node> *current;
        string finalPath;
        qu.push(searchable->getInitialState());
        while (!qu.empty()) {
            current = qu.top();
            qu.pop();
            counter++;
            if (!wasVisited(visited, current)) {
                visited.push_back(current);
            }

            if(current->Equal(searchable->getGoalState())){

                while (current != NULL) {
                    cost+=current->getCost();
                    totalPoints.push_back(current);
                    current = current->getDad();
                }
                reverse(totalPoints.begin(),totalPoints.end());
                finalPath= searchable->getPathSolution(totalPoints);
                return finalPath;
            }
            neighbors = searchable->getAllPossibleStates(current);
            for (State<Node> *neighbor : neighbors) {
                if (!wasVisited(visited,neighbor)) {
                    neighbor->setCameFrom(current);
                    qu.push(neighbor);
                }
            }
        }
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


#endif //EX4_DFS_H
