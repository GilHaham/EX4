//
// Created by meir on 09/01/19.
//

#include "MatrixProblem.h"

using namespace std;

template<class T>
MatrixProblem<T>::MatrixProblem( vector<vector<int>> &matrix, int matrixSize,  State<T> &initState, State<T> &goalState):
matrix(matrix), matrixSize(matrixSize), initState(initState), goalState(goalState) {}


template<class T>
State<vector<int>> MatrixProblem<T>::getInitialState() {
    return this->initState;
}

template<class T>
State<vector<int>> MatrixProblem<T>::getGoalState() {
    return this->goalState;

}

template<class T>
std::vector<State<T>> MatrixProblem<T>::getAllPossibleStates(State<T> state) {
    //#>~?>@?~!>$>@#$>#%?$^%>$&>&^>%
//    return std::vector<State<T>>();
}

template<class T>
bool MatrixProblem<T>::isGoal(State<T> state) {
    return false;
}

