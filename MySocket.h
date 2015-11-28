#pragma once
#include <iostream>
#include <WinSock2.h>
#include <process.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

#define SERVER_PORT 55000 // DO NOT MODIFY
#define SERVER_IP "192.168.123.175"  // Place the Server's IP address (IF 127.0.0.1, means it self)
#define SE 1
#define CL 2

class MySocket
{
	public:
		MySocket(int dataLength);
		~MySocket(void);
		/*server*/
		void ServerSetting();
		void ServerRun();
		void ServerClose();
		/*client*/
		void ClientSetting();
		void ClientRun();
		void ClientClose();
		/* data send and recSendDatav*/
		UINT WINAPI SendData(void *args);
		UINT WINAPI RecvData(void *args);
	private:
		const int DATA_LENGTH;
		WSADATA wsaData;
		/* server */
		SOCKADDR_IN servAddr;
		/* client */
		SOCKADDR_IN clntAddr;
		/* socket */
		SOCKET servSock;
		SOCKET clntSock;
		int clntAddrSize;
		/* private function */
		void SocketInit();//Socket Initializing function
		void ErrorHandle(char *message);
};
