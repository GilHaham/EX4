cmake_minimum_required(VERSION 3.8)
project(EX4)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Server.h MySerialServer.h ClientHandler.h MyClientHandler.cpp
        MyClientHandler.h State.h SearcherAlgo/BestFirstSearch.cpp SearcherAlgo/BestFirstSearch.h ISearcher.h
        ISearchable.h Searcher.cpp Searcher.h CacheManager.h
        MatrixProblem.h Point.h StringReverser.cpp StringReverser.h Solver.h FileCacheManager.cpp FileCacheManager.h MyTestClientHandler.cpp MyTestClientHandler.h)
add_executable(EX4 ${SOURCE_FILES})