//
// Created by meir on 07/01/19.
//

#include "Searchable.h"
#include "Point.h"

class MatrixProblem : public Searchable<class Point> {

public:
    MatrixProblem(vector<State<Point>*> search, State<Point>* initial, State<Point>* goal)
    : Searchable(search, initial,goal){
    }

    State<Point>* getInitialState() {
        return this->initialState;
    }

    void setInitialState(State<Point>* point) {
        this->initialState=point;
    }

    State<Point>* getGoalState(){
        return this->goalState;
    }

    vector<State<Point>*> getAllPossibleStates(State<Point>* state){
        vector<State<Point>*> neighbors;
        int row = state->getState().getRow();
        int col = state->getState().getCol();
        int matrixSize = this->searchable.size();
        for (int n = 0; n < matrixSize; ++n) {
            int n1 = this->searchable[n]->getState().getRow();
            int n2 = this->searchable[n]->getState().getCol();
            if (((n1 == (row - 1)) && (n2 == col)) || ((n1 == (row + 1)) && (n2 == col))
                || ((n1 == row) && (n2 == (col - 1))) || ((n1 == row) && (n2 == (col + 1)))) {
                if (this->searchable[n]->getCost() != (-1)) {
                    neighbors.push_back(this->searchable[n]);
                }
            }
        }
        return neighbors;
    }

    string getPathSolution(vector<State<Point>*> pathPoints){
        State<Point>* state;
        State<Point>* next;
        string finalPath="{";
        for(int i=0; i<pathPoints.size()-1; i++) {
            state = pathPoints[i];
            next=pathPoints[i+1];
            int rowNext=next->getState().getRow();
            int colNext=next->getState().getCol();
            int X = state->getState().getRow();
            int Y = state->getState().getCol();
            if (rowNext==X+1){
                finalPath+="Down, ";
            }
            else if(rowNext==X-1){
                finalPath+="Up, ";
            }
            else if (colNext==Y-1){
                finalPath+="Left, ";
            }
            else if (colNext==Y+1){
                finalPath+="Right, ";
            }
        }
        finalPath.erase(finalPath.size()-2);
        finalPath+="}";
        return finalPath;
    }


};
