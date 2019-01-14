//
// Created by meir on 07/01/19.
//

#include "Searchable.h"
#include "Point.h"

class MatrixProblem : public Searchable<class Point> {

public:
    // inserting the matrix the vector of vector of states.
    /**
     *  the constructor.
     *
     * @param search point
     * @param initialState point
     * @param goalState point
     */
    MatrixProblem(vector<State<Point>*> search, State<Point>* initialState, State<Point>* goalState)
    : Searchable(search, initialState,goalState){
    }


    double getTotalcost() override {
        return this->totalCost;
    }

    void setTotalCost(double num) override {
        this->totalCost = num;
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
    vector<State<Point>*> getPossibleStates(State<Point> *state){
        int matrixSize = this->searchable.size();
        vector<State<Point>*> successors;
        int row = state->getState().getRow();
        int col = state->getState().getCol();
        // checking if we are not in the last or first row and col.
        for (int i = 0; i < matrixSize; i++) {
            int k1 = this->searchable[i]->getState().getRow();
            int k2 = this->searchable[i]->getState().getCol();
            if (((k1 == (row - 1)) && (k2 == col)) || ((k1 == (row + 1)) && (k2 == col))
            ||((k1 == row) && (k2 == (col - 1))) || ((k1 == row) && (k2 == (col + 1)))){
                if (this->searchable[i]->getCost()!=(-1)){
                    successors.push_back(this->searchable[i]);
                }
            }
        }
        return successors;
    }

    // getting the path solutions.
    string getPathSolution(vector<State<Point>*> pathPoints){
        string thePath = "{";
        State<Point>* state;
        State<Point>* next;
        for(int j=0; j<pathPoints.size()-1; j++) {
            state = pathPoints[j];
            next=pathPoints[j+1];
            int rowNext=next->getState().getRow();
            int colNext=next->getState().getCol();
            int row = state->getState().getRow();
            int col = state->getState().getCol();


            if ((colNext == col)&&(rowNext==row-1)){
                thePath+="Up, ";
            }
            else if((colNext == col)&&(rowNext==row+1)){
                thePath+="Down, ";
            }
            else if ((rowNext == row)&&(colNext==col+1)){
                thePath+="Right, ";
            }
            else if ((rowNext == row)&&(colNext==col-1)){
                thePath+="Left, ";
            }
        }

        thePath.erase(thePath.size()-2);
        thePath += "}";
        return thePath;
    }


};
