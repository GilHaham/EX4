#include "MyClientHandler.h"
#include "SearcherAlgo/BestFirstSearch.h"
#include "MatrixProblem.h"
#include "Searcher.h"
#include "FileCacheManager.h"
#include "SearcherSolver.h"
#include "MyParallelServer.h"

int main() {

    CacheManager *cacheManager = new FileCacheManager();
    auto solver = new SearcherSolver<pair<int, int>, string>(new BestFirstSearch<pair<int, int>, string>);
    ClientHandler *handler = new MyClientHandler(cacheManager, solver);


    MyParallelServer server;
    try {
        server.openServer(5402, handler);
    } catch (std::exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}



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
//    string x = b->matrix(m);
//    cout << x << endl;


//    MySerialServer* d = new MySerialServer();
//    Solver<Searchable<Point>*, string>* solver = new GetSol(new BestFirstSearch<Point>());
//    CacheManager* cacheManager = new FileCacheManager();
//    ClientHandler* cacheManager = new MyClientHandler(cacheManager, solver);
//    d->openServer(5400,cacheManager);
//    while (true) {}