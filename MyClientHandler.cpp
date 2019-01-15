//
// Created by meir on 15/01/19.
//

#include <string.h>
#include <iostream>
#include <mutex>
#include <unistd.h>
#include "MyClientHandler.h"

using namespace std;


MyClientHandler::MyClientHandler(CacheManager *cacheManager, Solver<Searchable<pair<int,int>> *, string> *searcher)
        : searcher(searcher), cacheManager(cacheManager) {}

MyClientHandler::MyClientHandler() {}




void MyClientHandler::handleClient(int socketFd) {

    char buffer[1000];
    bool isNotEnd = true;
    ssize_t n;
    string matrixString;
    string tempStr;
    vector <string> clearStrVector;
    size_t strIndex = 0;
    int k = 0;
    vector <vector<string>> tmpMatrix;
    vector < vector < State < vector < int >> * >> matrix;
    vector<int> stateVector;
    State <vector<int>> startState;
    State <vector<int>> exitState;


    while (isNotEnd) {
        // If connection is established then startState communicating
        bzero(buffer, 1000);
        n = read(socketFd, buffer, 1000);
        cout << "the buffer: " << buffer << endl;
        if (n < 0) {
            perror("ERROR reading from socketFd");

            // exitState(1);
        }

        if (strcmp(buffer, "end") != 0) {
            matrixString += buffer;
            tempStr = matrixString;


            while ((strIndex = matrixString.find(",")) != string::npos) { // working on one line.
                clearStrVector.push_back(tempStr.substr(0, strIndex));
                tempStr.erase(0, strIndex + 1); // erasing the number and the "," after it.
                k++;
            }
            clearStrVector.push_back(tempStr.substr(0, strIndex));

            tmpMatrix.push_back(clearStrVector);

            clearStrVector.clear();
        } else { // when we finish to get the matrix and we need to startState to create it.
            isNotEnd = false;

            int temp;
            vector<int> pos;
            vector < State < vector < int >> * > vecLine;
            for (int i = 0; i < tmpMatrix.size() - 2; i++) {
                for (int j = 0; j < tmpMatrix[i].size(); j++) { // one line.
                    if (strcmp(tmpMatrix[i][j].c_str(), "-1") == 0) {
                        temp = -1;
                    } else {
                        int temp1 = stoi(tmpMatrix[i][j]);
                        temp = temp1;
                    }
                    pos.push_back(i);
                    pos.push_back(j);
                    State <vector<int>> *myState = new State <vector<int>>(pos, temp, nullptr);
                    vecLine.push_back(myState);
                    pos.clear();
                }
                matrix.push_back(vecLine); // we create matrix.
                vecLine.clear();
            }
            for (int l = tmpMatrix.size() - 2; l < tmpMatrix.size(); l++) {
                clearStrVector = tmpMatrix[l];
                stateVector.push_back(stoi(clearStrVector[0]));
                stateVector.push_back(stoi(clearStrVector[1]));
                if (stateVector[0] < 0 || stateVector[1] < 0 || stateVector[0] > matrix.size() ||
                    stateVector[1] > matrix[stateVector[0]].size()) {
                    throw "invalid state";
                }
                if (l == tmpMatrix.size() - 2) {
                    startState.setNode(stateVector);
                } else {
                    exitState.setNode(stateVector);
                }
                if (stateVector.size() > 0) {
                    stateVector.clear();
                }
            }
        }
        mutex mutex1;
        mutex1.lock();
        cout << "mutex exist" << endl;

        pair<int, int>initialState;
        pair<int, int>goalState;
        initialState.first = startState.getNode()[0];
        initialState.second = startState.getNode()[1];
        goalState.first = exitState.getNode()[0];
        goalState.second = exitState.getNode()[1];

        vector<vector<double >> newMatrix;



//        vector < vector < State < vector < int >> * >> :: iterator outerIterator;
//        vector<State<vector<int>>*> :: iterator innerIterator;
//        for (outerIterator = matrix.begin(); outerIterator!= matrix.end(); outerIterator++){
//            for (innerIterator=outerIterator->begin(); innerIterator!=outerIterator->end(); innerIterator++){
//                newMatrix[outerIterator][innerIterator]
//            }
//        }


//        if (!cacheManager->isSolutionExist(matrixString)) {
//            string solution = searcher->solve(new MatrixProblem(newMatrix, initialState, goalState));
//            cacheManager->saveSolutionToMap(matrixString, solution);
//            cout << "my solution: " << solution << endl;
        }
//        writeTheSolution(clientId, matrixString.c_str());
//        mutex1.unlock();
    }

//}
