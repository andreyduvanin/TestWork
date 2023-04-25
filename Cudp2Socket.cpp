// Cudp2Socket.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplicationGUI.h"
#include "Cudp2Socket.h"

using namespace std;
#define ECHOMAX 1024;

UINT ThreadFunction(LPVOID param)
{
		DWORD result = 0;
		UINT exitCode = 0;
		CSocket echoServer;

		cout << "Cudp2Socket() - It works!" << endl;
		AfxSocketInit(NULL);

		// Create socket for sending/receiving datagrams
		if (echoServer.Create(514, SOCK_DGRAM, NULL) == 0)
		{
			AfxMessageBox(L"Create() failed", MB_OK | MB_ICONSTOP);
		}
		SOCKADDR_IN echoClntAddr;
			// Set the size of the in-out parameter
		int clntAddrLen = sizeof(echoClntAddr);
			// Buffer for echo string
		char echoBuffer[1024];
			// Block until receive message from a client

		for (;;)
		{
			int recvMsgSize = echoServer.ReceiveFrom(echoBuffer,1024, (SOCKADDR*)&echoClntAddr, &clntAddrLen, 0);
			if (recvMsgSize < 0)
			{
				AfxMessageBox(L"RecvFrom() failed", MB_OK | MB_ICONSTOP);
			}
			if (recvMsgSize)
			{
				cout << recvMsgSize << endl;
				cout << echoBuffer  << endl;
				cout <<  "echoServer.ReceiveFrom - It works!" << endl;
//				AfxMessageBox(L"RecvFrom() ", MB_OK | MB_ICONSTOP);
			}
			Sleep(100);
		}
		AfxEndThread(exitCode);
		return result;
}

Cudp2Socket::Cudp2Socket()
{
	CWinThread* pThread;
	LPVOID data = 0;
	pThread = AfxBeginThread(ThreadFunction, &data);
}

Cudp2Socket::~Cudp2Socket()
{
}
// функции-члены Cudp2Socket


void Cudp2Socket::OnReceive(int nErrorCode)
{
	// TODO: добавьте специализированный код или вызов базового класса
	std::cout << "OnReceive(nErrorCode); nErrorCode = " << nErrorCode << endl;
	CSocket::OnReceive(nErrorCode);
}
