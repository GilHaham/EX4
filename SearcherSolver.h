//
// Created by gil on 15/01/19.
//

#ifndef EX4_SEARCHERSOLVER_H
#define EX4_SEARCHERSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "Searchable.h"


template<class Node, class Solution>
// we have here object adapter.
class SearcherSolver : public Solver<Searchable<Node>*, Solution>
{
    Searcher<Node, Solution>* searcher;

public:
    explicit SearcherSolver(Searcher<Node, Solution>* searcher)    {
        this->searcher = searcher;
    }


    Solution solve(Searchable<Node>* p)   {
        return searcher->search(p);
    }
};

#endif //EX4_SEARCHERSOLVER_H
