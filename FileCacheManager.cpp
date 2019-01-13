//
// Created by meir on 10/01/19.
//

#include "FileCacheManager.h"

// find if their is a solution in the map.
//template<class string, class Solution>
bool FileCacheManager::isExist(string problem) {
    return this->solutionsMap.count(problem) > 0;

}

bool FileCacheManager::isSolutionExist(string problem) { //////////
    int a = 5; // debuging variable need to erase.
    return this->solutionsMap.count(problem) > 0;
}

string FileCacheManager::extractSolution(string problem) { ///////////////
    return this->solutionsMap.at(problem);
}

// extract the solution.
//template<class Problem, class Solution>
string FileCacheManager::popSolution(string problem) {
    return this->solutionsMap.at(problem);
}

// insert the key(problem) and the value(solution)
//template<class Problem, class Solution>
void FileCacheManager::saveSolution(string problem, string solution) {
    solutionsMap.insert(make_pair(problem, solution));
}

//
//template<class Problem, class Solution>
void FileCacheManager::loadFileToMap() {
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

//template<class Problem, class Solution>
void FileCacheManager::saveToFile(unordered_map<string, string> solutions) {
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