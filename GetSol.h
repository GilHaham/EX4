//
// Created by meir on 13/01/19.
//

#ifndef EX4_GETSOL_H
#define EX4_GETSOL_H

#include "Searcher.h"
#include "Solver.h"
#include "Point.h"

class GetSol : public Solver<Searchable<pair<int, int>>*, string> {
    Searcher<pair<int, int>>* searcher;
public:
    GetSol(Searcher<pair<int, int>>* searcher1) {
        this->searcher = searcher1;
    }

    virtual string solve(Searchable<pair<int, int>>* p) {
        return this->searcher->search(p);
    }
};


#endif //EX4_GETSOL_H
