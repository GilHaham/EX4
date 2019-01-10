//
// Created by meir on 10/01/19.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H




template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem p) = 0;
};




#endif //EX4_SOLVER_H
