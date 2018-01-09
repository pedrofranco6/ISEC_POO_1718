#pragma once
#ifndef SIMULACAO_H
#define SIMULACAO_H

#include <string>

#include "Interface.h"
#include "Mundo.h"

class Simulacao
{
	int mundo = 20, en, pc, vt, mi, me, nm;
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