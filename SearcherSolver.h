//
// Created by gil on 15/01/19.
//

#ifndef EX4_SEARCHERSOLVER_H
#define EX4_SEARCHERSOLVER_H

#include "Solver.h"
#include "Searcher.h"
#include "Searchable.h"


template<class Node>
class SearcherSolver : public Solver<Searchable<Node>*, State<Node>>
{
    Searcher<Node>* searcher;
public:
    explicit SearcherSolver(Searcher<Node>* searcher)    {
        this->searcher = searcher;
    }


    State<Node> solve(Searchable<Node>* p)   {
        return searcher->search(p);
    }
};

#endif //EX4_SEARCHERSOLVER_H
