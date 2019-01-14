#include "MyClientHandler.h"
#include "Solver.h"
#include "MatrixProblem.h"
#include "State.h"
#include "Point.h"
#include <iostream>
#include "MySerialServer.h"
#include "FileCacheManager.h"
#include "GetSol.h"
#include "SearcherAlgo/BestFirstSearch.h"

int main() {

//    State<Point> *initial = new State<Point>(Point(0, 0), 3);
//    State<Point> *goal = new State<Point>(Point(2, 2), 6);
//
//    vector<State<Point> *> searchable;
//    searchable.push_back(initial);
//    searchable.push_back(new State<Point>(Point(0, 1), 4));
//    searchable.push_back(new State<Point>(Point(0, 2), 2));
//    searchable.push_back(new State<Point>(Point(1, 0), 3));
//    searchable.push_back(new State<Point>(Point(1, 1), 7));
//    searchable.push_back(new State<Point>(Point(1, 2), 5));
//    searchable.push_back(new State<Point>(Point(2, 0), 1));
//    searchable.push_back(new State<Point>(Point(2, 1), 4));
//    searchable.push_back(goal);
//
//    Searchable<Point> *m = new Matrix(searchable, initial, goal);
//    DFS<Point> *b = new DFS<Point>;
//    string x = b->search(m);
//    cout << x << endl;


    MySerialServer* d = new MySerialServer();
    Solver<Searchable<Point>*, string>* solver = new GetSol(new BestFirstSearch<Point>());
    CacheManager* cacheManager = new FileCacheManager();
    ClientHandler* cm = new MyClientHandler(cacheManager, solver);
    d->openServer(5400,cm);
    while (true) {}
    return 0;
}