// Cudp2Socket.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplicationGUI.h"
#include "Cudp2Socket.h"
using namespace std;


// Cudp2Socket

Cudp2Socket::Cudp2Socket()
{
	cout << "Cudp2Socket() - It works!" << endl;
}

Cudp2Socket::~Cudp2Socket()
{
}


// функции-члены Cudp2Socket


void Cudp2Socket::OnReceive(int nErrorCode)
{
	// TODO: добавьте специализированный код или вызов базового класса
	 
	CSocket::OnReceive(nErrorCode);
}
