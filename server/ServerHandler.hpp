
//
//  ServerHandler.hpp
//  tcp_ip_cpp
//
//  Created by Eskil André Skotvold on 08/09/2016.
//
//

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <thread>
#include "tcpAcceptor.hpp"
#include "packet.h"
#include "cmd.h"

namespace SARB{

class ServerHandler
{
public:
	ServerHandler();
    void startServer();
    void stopServer();
    void detachServer();
    bool getThreadRunning();
    ~ServerHandler();

private:
    bool m_threadRunning;
    std::thread m_thread;
    void runServer(int port);
    tcp_stream* stream 	;
    TCPAcceptor* acceptor;
    std::string receivedCommand;
    bool readData(tcp_stream* stream, void* buf, int buflen);
    bool readSize(tcp_stream* stream, long* value);
    bool readPackages(tcp_stream* stream, int totalSizeOfPackage);
    bool sendSize(tcp_stream* stream, long value);
    bool sendPackage(std::string command);
    bool sendData(tcp_stream* stream, void* buf, int buflen);
    bool sendFile(std::string path);
    bool execPackage(tcp_stream* stream,long receivePackageSize);

};
}
