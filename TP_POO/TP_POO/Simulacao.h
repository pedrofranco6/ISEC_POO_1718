#pragma once
#ifndef SIMULACAO_H
#define SIMULACAO_H

#include <string>
#include <fstream>

#include <iostream>
using namespace std;

#include "Interface.h"
#include "Mundo.h"

class Simulacao
{
	int mundo = 10, en = 100, pc = 50, vt = 1, mi = 10, me = 50, nm = 2;
	int focol = 0, fococ = 0;
	Interface f;
	Mundo * m;	
public:
	Simulacao();
	~Simulacao();
	void setUp();
	void simulacao();
	void finalizacao();
};

#endif