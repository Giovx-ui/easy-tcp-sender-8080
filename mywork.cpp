#pragma comment(lib,"Ws2_32.lib")

#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

int main(){

WSADATA wsadata;
int iresult = 0;



int ifamily = AF_INET;
int itype = SOCK_STREAM;
int iprotocol = IPPROTO_TCP;
iresult = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (iresult != 0) {
        wprintf(L"WSAStartup failed: %d\n", iresult);
        return 1;
    }


SOCKET sock = socket(ifamily,itype,iprotocol);

if (sock == INVALID_SOCKET){
 wprintf(L"Socket creation failed: %ld\n", WSAGetLastError());
 WSACleanup();
 return 1;

}

sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");

connect(sock , (struct sockaddr*)&serverAddress,sizeof(serverAddress));

const char* msg = "ciao server!";
send(sock,msg,strlen(msg),0);

closesocket(sock);
WSACleanup();
return 0;

}