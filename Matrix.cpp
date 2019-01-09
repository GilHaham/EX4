//
// Created by meir on 09/01/19.
//

#include "Matrix.h"

using namespace std;

template<class T>
State<T> Matrix<T>::getInitialState() {

    return State<T>(T());
}

template<class T>
State<T> Matrix<T>::getGoalState() {
    return State<T>(T());
}

template<class T>
std::vector<State<T>> Matrix<T>::getAllPossibleStates(State<T> state) {
    return std::vector<State<T>>();
}

template<class T>
bool Matrix<T>::isGoal(State<T> state) {
    return false;
}
