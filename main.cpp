#include <iostream>
#include "State.h"
#include "Point.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "Main.h"
//#include "SearcherAlgo"

using namespace std;
int main(int argc, char *argv[]) {
//    Solver<string, string> *solver = new StringReverser();
//    CacheManager *cacheManager = new FileCacheManager();
//    cacheManager->loadFileToMap();
//    Server *server = new MySerialServer();
//    ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
//    server->openServer(stoi(argv[0]), clientHandler);

    char* port1 = argv[1];
    int port = atoi(port1);
    boot::Main* m;

    m->main(port);
    while (true){}


//    State<std::string>* a = new State<std::string>("A");
//    State<std::string>* b = new State<std::string>("B");
//    State<std::string>* goal = new State<std::string>("B");

//    double input;
//    vector<vector<State<vector<int>>*>> matrix;
//
//    for (int i = 0; i < 3; i++) {
//        vector<State<vector<int>>*> myvector;
//        for (int j = 0; j < 3; j++) {
//            vector<int> point;
//            point.push_back(i);
//            point.push_back(j);
//            State<vector<int>>* state = new State<vector<int>>(point,6);
//            cin >> input;
//            state->setCost(input);
//            myvector.push_back(state);
//        }
//        matrix.push_back(myvector);
//    }
//    vector<int> p;
//    p.push_back(0);
//    p.push_back(0);
//    State<vector<int>>* root = new State<vector<int>>(p,7);
//    p.clear();
//    p.push_back(2);
//    p.push_back(2);
//    State<vector<int>>* goal = new State<vector<int>>(p,8);
//
//    Searchable<vector<int>>* ma = new MatrixProblem(matrix,root,goal);
//
//    ISearcher<vector<int>>* one = new BestFirstSearch<vector<int>>();
//    one->search(ma);



//    vector<State<vector<int>>> gad

    cout<<"hello"<<endl;


//    State<vector<int,int>>* root;
//    State<T>* goal;

    return 0;
}