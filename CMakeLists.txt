cmake_minimum_required(VERSION 3.8)
project(EX4)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)
set(SOURCE_FILES main.cpp Server.h MySerialServer.h ClientHandler.h
        State.h SearcherAlgo/BestFirstSearch.h Searcher.h
        Searchable.h CacheManager.h
        MatrixProblem.h Point.h StringReverser.cpp StringReverser.h Solver.h FileCacheManager.cpp FileCacheManager.h
        MyTestClientHandler.cpp MyTestClientHandler.h DataBase.cpp DataBase.h Main.cpp Main.h
        MyClientHandler.cpp MyClientHandler.h GetSol.h MatrixProblem.cpp MyParallelServer.h TCP_sockets.cpp TCP_sockets.h SearcherSolver.h BFS.h)
add_executable(EX4 ${SOURCE_FILES})