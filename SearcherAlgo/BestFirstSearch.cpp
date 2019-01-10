//
// Created by meir on 08/01/19.
//

#include "BestFirstSearch.h"

template <class T>
queue<State<T>> &BestFirstSearch<T>::getOpenList(){
    return this->openList;
}

template <class T>
void BestFirstSearch<T>::setOpenList(queue<State<T>> openListQueue){
    this->openList=openListQueue;
}

template <class T>
queue<State<T>> &BestFirstSearch<T>::getCloseList() {
    return closeList;
}

//template <class T>
//void BestFirstSearch<T>::setCloseList(set<State<T>> &closeList) {
//    BestFirstSearch::closeList = closeList;
//}

template <class T>
string BestFirstSearch<T>::search(Searchable<T> searchable) {
    State<T> *currentState = new State<T>("A");

    this->openList.push(searchable.getInitialState());
    while (!this->getOpenList().empty()){
        currentState = this->getOpenList().front();


    }

}

