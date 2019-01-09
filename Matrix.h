//
// Created by meir on 09/01/19.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H


#include "ISearchable.h"

using namespace std;

template <class T>
class Matrix: public ISearchable<T> {

private:
    vector<vector<int>> matrix;
    int row;
    int col;
    int matrixSize;


public:
    State<T> getInitialState() override;

    State<T> getGoalState() override;

    std::vector<State<T>> getAllPossibleStates(State<T> state) override;

    bool isGoal(State<T> state) override;

};


#endif //EX4_MATRIX_H
