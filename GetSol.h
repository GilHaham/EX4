//
// Created by meir on 13/01/19.
//

#ifndef EX4_GETSOL_H
#define EX4_GETSOL_H

#include "Searcher.h"
#include "Solver.h"
#include "Point.h"

class GetSol : public Solver<Searchable<Point>*, string> {
    Searcher<Point>* searcher;
public:
    GetSol(Searcher<Point>* searcher1) {
        this->searcher = searcher1;
    }

    virtual string solve(Searchable<Point>* p) {
        return this->searcher->search(p);
    }
};


#endif //EX4_GETSOL_H
