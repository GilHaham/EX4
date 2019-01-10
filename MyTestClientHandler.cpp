//
// Created by meir on 10/01/19.
//


#include <unistd.h>
#include <strings.h>
#include <cstring>
#include "MyTestClientHandler.h"

string MyTestClientHandler::handleClient(int clientId) {
    ssize_t n;
    bool keepReading = true;


    while(keepReading) {
        char buffer[1000];
        // If connection is established then start communicating
        bzero(buffer, 1000);
        n = read(clientId, buffer, 1000);

        //finish the conversetion.
        if(strcmp(buffer,"end") == 0){
//            return nu;
        }
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        if(!this->cacheManager->isSolutionExist(buffer)){
            string solution = this->solver->solve(buffer);
            this->cacheManager->saveSolution(solution, buffer);
        }

        this->writeSolution(clientId,buffer);
    }


}

void MyTestClientHandler::writeSolution(int id, char *buffer) {
//    string solution = this->cacheManager->getSolution(buffer);
//    ssize_t n = write(id, solution.c_str(), 1000);
//
//    if (n < 0) {
//        perror("ERROR writing to socket");
//        exit(1);
//    }
}
