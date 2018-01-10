#pragma once
#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
#include "Mundo.h"

class Interface
{
public:
	Interface();
	~Interface();
	string setUp();
	bool testaComandoSetUp(string linha);
	string printInterface(Mundo * m, int mundo, int focol, int fococ);
	bool testaComandoSimulacao(string linha, int mundo);
	void printMapa(int tam);
	void printFormigas(Mundo * m, int focol, int fococ);
	void printNinhos(Mundo * m, int focol, int fococ);
	void printMigalhas(Mundo * m, int focol, int fococ);
	void finalizacao();
};

#endif
