//
// Created by meir on 15/01/19.
//

#include <string.h>
#include <iostream>
#include "TCP_sockets.h"
#include <algorithm>
#include "MyClientHandler.h"

using namespace std;


MyClientHandler::MyClientHandler(CacheManager *cacheManager, Solver<Searchable<pair<int, int>> *, string> *searcher)
        : searcher(searcher), cacheManager(cacheManager) {}

MyClientHandler::MyClientHandler() = default;



vector<string> split(string client_input, char tok)
{
    vector<string> output;
    string::iterator beg = client_input.begin();
    while (beg != client_input.end()) {
        string::iterator nxt = find(beg, client_input.end(), tok);
        output.emplace_back(beg, nxt);
        if (nxt == client_input.end())	{
            break;
        }
        beg = nxt + 1;
    }

    return output;
}


vector<string> read_from_client(posix_sockets::TCP_client client) {
    vector<string> output;

    string client_input;

    while (client_input.find("end") == string::npos) {
        try {
            client_input += client.read(256);
        } catch(std::exception& e)  {
            cout << e.what() << endl;
        }
    }

    client_input = client_input.substr(0, client_input.find("end"));
    return split(client_input, '\n');
    while (!client_input.empty()) {
        output.push_back(client_input.substr(0, client_input.find('\n')));
        client_input = client_input.substr(client_input.find('\n') + 1);
    }

    return output;
}
void MyClientHandler::handleClient(int socketFd) {
    posix_sockets::TCP_socket sock(socketFd);
    posix_sockets::TCP_client client(sock);

    vector<string> input = read_from_client(client);
    vector<vector<string>> matrix;

    vector<vector<double>> matrix_double;
    vector<vector<double>> initialAndGoal_vector;
    for (auto& inp : input) {
        matrix.push_back(split(inp, ','));
    }


    // the matrix converted to double into matrix_double.
    for (int i = 0; i < matrix.size()-2; ++i) {
        matrix_double.push_back(vector<double>());
        for (auto& val : matrix[i]) {
            matrix_double[i].push_back(stod(val));
        }
    }

    // the initial state and the goal state.
    int j = 0;
    for (int i = matrix.size()-1; i > matrix.size()-3; --i) {
        initialAndGoal_vector.push_back(vector<double>());
        for (auto& val : matrix[i]) {
            initialAndGoal_vector[j].push_back(stod(val));
        }
        j++;
    }




    // convert the matrix to string.
    string problemStr = " ";
    string solution = " ";
    vector<vector<double>>::iterator iter;
    vector<double>::iterator iter2;
    for (iter = matrix_double.begin(); iter != matrix_double.end();iter++ ) {
        for (iter2 = (*iter).begin(); iter2 != (*iter).end(); iter2++ ) {
            problemStr += to_string(*iter2);
            problemStr += " ";
        }
    }
    int i = 0;

    // צריך ליצור סירצ'בל מהמטריצה

    pair<int , int> initial;
    pair<int , int> goal;

    initial.first = initialAndGoal_vector[0][0];
    initial.second = initialAndGoal_vector[0][1];
    goal.first = initialAndGoal_vector[1][0];
    goal.second = initialAndGoal_vector[1][1];

//Check
    if(!this->cacheManager->isSolutionExist(problemStr)) {
        MatrixProblem* matrixProblem =new MatrixProblem(matrix_double,initial,goal );
        solution = this->searcher->solve(matrixProblem);
        matrixProblem->getInitialNode();
    }


}









//
//    char buffer[1000];
//    bool isNotEnd = true;
//    ssize_t n;
//    string matrixString;
//    string tempStr;
//    vector<string> clearStrVector;
//    size_t strIndex = 0;
//    int k = 0;
//    vector<vector<string>> tmpMatrix;
//    vector<vector<double >> matrix;
//    vector<int> stateVector;
//    State<vector<int>> startState;
//    State<vector<int>> exitState;
//
//
//    while (isNotEnd) {
//        // If connection is established then startState communicating
//        bzero(buffer, 1000);
//        n = read(socketFd, buffer, 1000);
//        cout << "the buffer: " << buffer << endl;
//        if (n < 0) {
//            perror("ERROR reading from socketFd");
//
//            // exitState(1);
//        }
//
//        if (strcmp(buffer, "end") != 0) {
//            matrixString += buffer;
//            tempStr = matrixString;
//
//
//            while ((strIndex = matrixString.find(",")) != string::npos) { // working on one line.
//                clearStrVector.push_back(tempStr.substr(0, strIndex));
//                tempStr.erase(0, strIndex + 1); // erasing the number and the "," after it.
//                k++;
//            }
//            clearStrVector.push_back(tempStr.substr(0, strIndex));
//
//            tmpMatrix.push_back(clearStrVector);
//
//            clearStrVector.clear();
//        } else { // when we finish to get the matrix and we need to startState to create it.
//            isNotEnd = false;
//
//            int temp;
//            vector<int> pos;
//            vector<State<vector<int >> *> vecLine;
//            for (int i = 0; i < tmpMatrix.size() - 2; i++) {
//                for (int j = 0; j < tmpMatrix[i].size(); j++) { // one line.
//                    temp = stoi(tmpMatrix[i][j]);
//                    pos.push_back(i);
//                    pos.push_back(j);
//                    State<vector<int>> *myState = new State<vector<int>>(pos, temp, nullptr);
//                    vecLine.push_back(myState);
//                    pos.clear();
//                }
//                matrix.push_back(vecLine); // we create matrix.
//                vecLine.clear();
//            }
//            for (int l = tmpMatrix.size() - 2; l < tmpMatrix.size(); l++) {
//                clearStrVector = tmpMatrix[l];
//                stateVector.push_back(stoi(clearStrVector[0]));
//                stateVector.push_back(stoi(clearStrVector[1]));
//                if (stateVector[0] < 0 || stateVector[1] < 0 || stateVector[0] > matrix.size() ||
//                    stateVector[1] > matrix[stateVector[0]].size()) {
//                    throw "invalid state";
//                }
//                if (l == tmpMatrix.size() - 2) {
//                    startState.setNode(stateVector);
//                } else {
//                    exitState.setNode(stateVector);
//                }
//                if (stateVector.size() > 0) {
//                    stateVector.clear();
//                }
//            }
//        }
//        cout << "mutex exist" << endl;
//
//        pair<int, int> initialState;
//        pair<int, int> goalState;
//        initialState.first = startState.getNode()[0];
//        initialState.second = startState.getNode()[1];
//        goalState.first = exitState.getNode()[0];
//        goalState.second = exitState.getNode()[1];
//
//        vector<vector<double >> newMatrix;
//    }






