//
// Created by meir on 07/01/19.
//

#include "Searchable.h"
#include "Point.h"

class MatrixProblem : public Searchable<class Point> {

public:
    // inserting the matrix the vector of vector of states.
    MatrixProblem(vector<State<Point>*> search, State<Point>* initialState, State<Point>* goalState)
    : Searchable(search, initialState,goalState){
    }

    State<Point>* getGoalState(){
        return this->goalState;
    }

    State<Point>* getInitialState() {
        return this->initialState;
    }

    void setInitialState(State<Point>* point) {
        this->initialState=point;
    }

    // getting all possible states.
    vector<State<Point>*> getAllPossibleStates(State<Point>* state){
        int matrixSize = this->searchable.size();
        vector<State<Point>*> successors;
        int row = state->getState().getRow();
        int col = state->getState().getCol();
        // checking if we are not in the last or first row and col.
        for (int n = 0; n < matrixSize; ++n) {
            int n1 = this->searchable[n]->getState().getRow();
            int n2 = this->searchable[n]->getState().getCol();
            if (((n1 == (row - 1)) && (n2 == col)) || ((n1 == (row + 1)) && (n2 == col))
            ||((n1 == row) && (n2 == (col - 1))) || ((n1 == row) && (n2 == (col + 1)))){
                if (this->searchable[n]->getCost()!=(-1)){
                    successors.push_back(this->searchable[n]);
                }
            }
        }
        return successors;
    }

    // getting the path solutions.
    string getPathSolution(vector<State<Point>*> pathPoints){
        State<Point>* state;
        State<Point>* next;
        string finalPath = "{";
        for(int i=0; i<pathPoints.size()-1; i++) {
            state = pathPoints[i];
            next=pathPoints[i+1];
            int rowNext=next->getState().getRow();
            int colNext=next->getState().getCol();
            int row = state->getState().getRow();
            int col = state->getState().getCol();


            if (rowNext==row-1){
                finalPath+="Up, ";
            }
            else if(rowNext==row+1){
                finalPath+="Down, ";
            }
            else if (colNext==col+1){
                finalPath+="Right, ";
            }
            else if (colNext==col-1){
                finalPath+="Left, ";
            }
        }

        finalPath.erase(finalPath.size()-2);
        finalPath += "}";
        return finalPath;
    }


};
