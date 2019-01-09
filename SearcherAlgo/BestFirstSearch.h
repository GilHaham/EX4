//
// Created by meir on 08/01/19.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "../ISearcher.h"
#include <queue>

using namespace std;

template <class T>
class BestFirstSearch: public ISearcher  {
private:
    queue <State<T>> openList;
    set <State<T>> closeList;

public:

    queue<State<T>> &getOpenList();
    void &setOpenList(queue<State<T>> openListQueue) ;

    set<State<T>> &getCloseList() ;
    void setCloseList(set<State<T>> &closeList);

    virtual Solution search(ISearchable<T> searchable);
    virtual int getNumberOfNodesEvaluated();

};


#endif //EX4_BESTFIRSTSEARCH_H
