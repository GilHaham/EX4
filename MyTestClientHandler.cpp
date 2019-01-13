////
//// Created by meir on 10/01/19.
////
//
//
////#include <unistd.h>
////#include <strings.h>
////#include <cstring>
////#include "MyTestClientHandler.h"
//
////string MyTestClientHandler::handleClient(int clientId) {
////    ssize_t n;
////    bool keepReading = true;
////
////
////    while(keepReading) {
////        char buffer[1000];
////        // If connection is established then start communicating
////        bzero(buffer, 1000);
////        n = read(clientId, buffer, 1000);
////
////        //finish the conversetion.
////        if(strcmp(buffer,"end") == 0){
//////            return nu;
////        }
////        if (n < 0) {
////            perror("ERROR reading from socket");
////            exit(1);
////        }
////
////        if(!this->cacheManager->isSolutionExist(buffer)){
////            string solution = this->solver->solve(buffer);
////            this->cacheManager->saveSolution(solution, buffer);
////        }
////
////        this->writeSolution(clientId,buffer);
////    }
////
////
////}
////
////void MyTestClientHandler::writeSolution(int id, char *buffer) {
//////    string solution = this->cacheManager->getSolution(buffer);
//////    ssize_t n = write(id, solution.c_str(), 1000);
//////
//////    if (n < 0) {
//////        perror("ERROR writing to socket");
//////        exit(1);
//////    }
////}
//#include <unistd.h>
//#include <cstring>
//#include <iostream>
//#include <sys/socket.h>
//#include <error.h>
//#include "MyTestClientHandler.h"
//#include "FileCacheManager.h"
//
//using namespace std;
//
//string MyTestClientHandler::handleClient(int newsockfd) {
//    bool end = false;
//
//    while (end != true) {
//        char buff[256];
//        ssize_t n;
//        // This send() function sends the 13 bytes of the string to the new socket
//
//        bzero(buff, 256);
//
//        n = read(newsockfd, buff, 255);
//        if (n < 0) cout << ("ERROR reading from socket") << endl;
//
//        int size = strlen(buff);
//        string str = "";
//        for (int i = 0; i < size - 2; ++i) {
//            str.push_back(buff[i]);
//        }
//
//
//        if (str == "end") {
////            FileCacheManager* fileCacheManager = dynamic_cast<FileCacheManager*>(this->cm);
////            fileCacheManager->exit();
//            close(newsockfd);
//            end = true;
//        } else {
//            if (cm->isSolutionExist(str)) {
//                //write on socket
//                string h = cm->extractSolution(str);
//                h = h + "\n";
//                const char *charKochavitName = h.c_str(); // convert the string to char *
//                send(newsockfd, charKochavitName, h.size(), 0);
//            } else {
//                string h = solver->solve(str);
//                cm->saveSolution(h, str);
//                h = h + "\n";
//                const char *charKochavitName = h.c_str(); // convert the string to char *
//                send(newsockfd, charKochavitName, h.size(), 0);
//
//            }
//        }
//
//    }
//
//
//}
//
//
//string MyTestClientHandler::read_until(int sockfd, string sep) {
//    char buffer[256];
//    string remainder;
//    //clock open
//    while (remainder.find(sep) == string::npos) {
//        ssize_t bytes_read = (read(sockfd, buffer, 255));
//        //if 15 sec passed{end=true}
//
//        if (bytes_read < 0) {
//            perror("Invalid socket read");
//            exit(1);
//        }
//        buffer[bytes_read] = 0;
//        remainder += string(buffer);
//    }
//
//    unsigned long pos = remainder.find(sep);
//    pair<string, string> output;
//    output.first = remainder.substr(0, pos);
//    output.second = remainder.substr(pos + 1);
//
//    return output.first;
//}