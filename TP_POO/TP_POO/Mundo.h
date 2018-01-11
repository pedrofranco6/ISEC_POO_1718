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
	int getSizeNinhos();
	int getSizeOfNinhoX(int ninho);
	//void getDadosFormiga(int ninho, int formiga, int *identificador, int *linha, int *coluna);
	int getIdentificadorFormiga(int ninho, int formiga);
	int getLinhaFormiga(int ninho, int formiga);
	int getColunaFormiga(int ninho, int formiga);
	int getIdentificadorNinho(int ninho);
	int getLinhaNinho(int ninho);
	int getColunaNinho(int ninho);
	void novoNinho(int energia, int linha, int coluna);
	void novaFormiga(string tipo, int ninho);
	void novaFormiga(string tipo, int ninho, int linha, int coluna);
	void novaMigalha(int energia, int linha, int coluna);
	void addEnergiaNinho(int ninho, int energia);
	void addEnergiaFormiga(int linha, int coluna, int energia);
	void apagaNinho(int ninho);
};

#endif