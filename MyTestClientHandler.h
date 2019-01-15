//////
////// Created by meir on 10/01/19.
//////
//
//#ifndef EX4_MYTESTCLIENTHANDLER_H
//#define EX4_MYTESTCLIENTHANDLER_H
//
//
//
//#include "ClientHandler.h"
//#include "Solver.h"
//#include "CacheManager.h"
//#include "string"
//
//using namespace std;
//
//class MyTestClientHandler : public ClientHandler {
//    Solver<string, string> *solver;
//    CacheManager *cacheManager;
//
//public:
//    MyTestClientHandler(Solver<string, string> *s, CacheManager* cm1) {
//        solver = s;
//        cacheManager = cm1;
//    }
//    MyTestClientHandler() {
//
//    }
//
//
//    virtual void handleClient(int newsockfd);
//
//    //void writeSoultion(int id,char* buffer);
//    string read_until(int sockfd, string sep);
//    CacheManager* getCacheManager(){
//        return this->cacheManager;
//    }
//
//};
//
//
//
//#endif //EX4_MYTESTCLIENTHANDLER_H
