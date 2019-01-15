//
// Created by gil on 15/01/19.
//

#ifndef EX4_SEARCHERSOLVER_H
#define EX4_SEARCHERSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "Searchable.h"


//template<class Node>
// we have here object adapter.
class SearcherSolver : public Solver<Searchable <pair<int, int>>*, string>
{
    Searcher<pair<int, int>>* searcher;

public:
    explicit SearcherSolver(Searcher<pair<int, int>>* searcher)    {
        this->searcher = searcher;
    }


    string solve(Searchable<pair<int, int>>* p)   {
        return searcher->search(p);
    }

    virtual ~SearcherSolver() {

    }
};

#endif //EX4_SEARCHERSOLVER_H
