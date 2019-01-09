//
// Created by meir on 08/01/19.
//

#include "BestFirstSearch.h"

template <class T>
queue<State<T>> &BestFirstSearch::getOpenList(){
    return this->openList;
}

template <class T>
void &BestFirstSearch::setOpenList(queue<State<T>> openListQueue){
    this->openList=openListQueue;
}

template <class T>
set<State<T>> &BestFirstSearch::getCloseList() {
    return closeList;
}

template <class T>
void BestFirstSearch::setCloseList(set<State<T>> &closeList) {
    BestFirstSearch::closeList = closeList;
}

template <class T>
Solution BestFirstSearch::search(ISearchable<T> searchable) {
    State<T> *currentState = new State<T>("A");

    this->openList.push(searchable.getInitialState());
    while (!this->getOpenList().empty()){
        currentState = this->getOpenList().front(); // n<-


    }

}

