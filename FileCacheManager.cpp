//
// Created by meir on 10/01/19.
//

#include "FileCacheManager.h"

// find if their is a solution in the map.
template<class Problem, class Solution>
bool FileCacheManager<Problem, Solution>::isExist(Problem problem) {
    return this->solutionsMap.count(problem) > 0;

}

// extract the solution.
template<class Problem, class Solution>
Solution FileCacheManager<Problem, Solution>::popSolution(Problem problem) {
    return this->solutionsMap.at(problem);
}

// insert the key(problem) and the value(solution)
template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::saveSolution(Problem problem, Solution solution) {
    solutionsMap.insert(make_pair(problem, solution));
}

//
template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::loadFileToMap() {
    ifstream solutionsFile;
    string line;
    vector<string> parsingVector;
    solutionsFile.open("Solutions.txt");
    if (solutionsFile.is_open()) {
        while (getline(solutionsFile, line)) {
            parsingVector = DataBase::fileToVector(line, '$');
            solutionsMap.insert(make_pair(parsingVector.at(0), parsingVector.at(1)));
        }
        solutionsFile.close();
    } else {
        cout << "Unable to open file" << endl;
        return;
    }
}

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::saveToFile(unordered_map<Problem, Solution> solutions) {
    ofstream myFile;
    myFile.open("Solutions.txt");
    if (myFile.is_open()) {
        std::unordered_map<string, string>::iterator it;
        for (it = solutions.begin(); it != solutions.end(); it++) {
            myFile << it->first << '$' << it->second << endl;
        }
        myFile.close();
    } else {
        cout << "Unable to open file" << endl;
        return;
    }
}