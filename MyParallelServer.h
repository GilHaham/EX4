//
// Created by gil on 15/01/19.
//

#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include "TCP_sockets.h"
#include "ClientHandler.h"
#include <stack>
#include <thread>
#include "Server.h"

#define MAX_LISTEN 5
using namespace posix_sockets;


struct Args {
    int newsockfd;
};

namespace server_side {
    class MyParallelServer : public Server {

        bool first_run = true;
    public:
        void openServer(int port, ClientHandler *clientHandler) override {
            TCP_server server(port); //open server
            server.listen(MAX_LISTEN);

            std::stack<std::thread> threads;
            while (true) {

                try {

                    TCP_client client = server.accept();
                    std::thread t([](ClientHandler * handler, int sock){handler->handleClient(sock);}, clientHandler, client.get_socket());
                    t.detach();
//                    clientHandler->handleClient(client.get_socket());
                }   catch(timeout_exception& e) {
                    cout << e.what();
                    server.close();
                    break;
                }   catch (std::exception& e)   {
                    cout << e.what();
                    perror("error on accept");
                }

                if (first_run)  {
                    server.settimeout(1000);
                    first_run = false;

                }
            }
        }


        void stopServer() override {

        }

        bool isOpen() override {
            return false;
        }
    };

}
#endif //EX4_MYPARALLELSERVER_H
