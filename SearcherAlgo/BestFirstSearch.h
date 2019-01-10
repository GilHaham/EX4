//
// Created by meir on 08/01/19.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "../Searcher.h"
#include <queue>

using namespace std;

template <class T>
class BestFirstSearch: public Searcher<T>  {
private:
    queue <State<T>> openList;
    queue <State<T>> closeList;

public:

    queue<State<T>> &getOpenList();

    void setOpenList(queue<State<T>> openListQueue) ;



    queue<State<T>> &getCloseList();

    void setCloseList(queue<State<T>> &closeList);



    virtual string search(Searchable<T> searchable);

    virtual int getNumberOfNodesEvaluated();

};


#endif //EX4_BESTFIRSTSEARCH_H
