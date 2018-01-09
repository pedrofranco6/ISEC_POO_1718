#pragma once
#ifndef MUNDO_H
#define MUNDO_H

#include <vector>

using namespace std;
#include "Ninho.h"
#include "Migalha.h"

class Mundo
{
	int tamanho;
	vector<Ninho *> ninhos;
	vector<Migalha *> migalhas;
public:
	Mundo();
	~Mundo();
	void setTam(int tam);
	int getTam();
};

#endif