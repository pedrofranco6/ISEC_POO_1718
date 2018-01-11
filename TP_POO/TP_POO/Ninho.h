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
	int getIdentificador();
	int getLinha();
	int getColuna();
	int getSizeFormigas();
	int getIdentificadorFormiga(int formiga);
	int getLinhaFormiga(int formiga);
	int getColunaFormiga(int formiga);
	//void getDadosFormiga(int formiga, int *identificador, int *linha, int *coluna);
	void novaCuidadora(int comunidade, int linha, int coluna);
	void novaVigilante(int comunidade, int linha, int coluna);
	void novaAssaltante(int comunidade, int linha, int coluna);
	void novaExploradora(int comunidade, int linha, int coluna);
	void addEnergia(int energia);
	void addEnergiaFormiga(int formiga, int energia);
};

#endif