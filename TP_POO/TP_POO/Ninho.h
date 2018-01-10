#pragma once
#ifndef NINHO_H
#define NINHO_H

#include <vector>

using namespace std;
#include "Formiga.h"

class Ninho
{
	int identificador, energia, linha, coluna;
	vector<Formiga *> formigas;
public:
	Ninho(int identificador, int energia, int linha, int coluna);
	~Ninho();
	int getLinha();
	int getColuna();
};

#endif