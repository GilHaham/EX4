//
// Created by meir on 10/01/19.
//


#include "MyTestClientHandler.h"

string MyTestClientHandler:: handleClient(string buffer){
    string line = buffer;
    if (line != "end") {
        if (this->cacheManager->isSolutionExist(line)) {
            cout.flush();
            return this->cacheManager->extractSolution(line);
        } else {
            string solution;
            solution = this->solver->solve(line);
            this->cacheManager->saveSolution(line, solution);
            cout.flush();
            return solution;
        }
    } else {
        cout.flush();
        return nullptr;
    }
}
