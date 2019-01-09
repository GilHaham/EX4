//
// Created by meir on 09/01/19.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H


#include "ISearchable.h"
#include "Point.h"

using namespace std;


template <class T>
class MatrixProblem: public ISearchable<T> {

private:
    vector<vector<int>> matrix;
    int matrixSize;
    State<T> initState;
    State<T> goalState;


public:

    MatrixProblem( vector<vector<int>> &matrix, int matrixSize,  State<T> &initState,
                   State<T> &goalState);

    State<vector<int>> getInitialState() override;

    State<vector<int>> getGoalState() override;

    std::vector<State<T>> getAllPossibleStates(State<T> state) override;

    bool isGoal(State<T> state) override;

};


#endif //EX4_MATRIX_H
