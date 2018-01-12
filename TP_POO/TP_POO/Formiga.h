#pragma once
#ifndef FORMIGA_H
#define FORMIGA_H

#include <vector>

using namespace std;
#include "Regra.h"

class Mundo;
class Regra;
class Ninho;

class Formiga
{
protected:
	int identificador, comunidade, energia, visao, movimento, linha, coluna;
		char tipo;
	vector<Regra *> regras;
public:
	Formiga();
	~Formiga();
	int getIdentificador();
	int getEnergia();
	int getComunidade();
	int getLinha();
	int getColuna();
	int getVisao();
	int getMovimento();
	char getTipo();
	void addEnergia(int energia);
	void fazRegras(Mundo *m);
	void mover(int linha, int coluna);
};

class Cuidadora : public Formiga
{
public:
	Cuidadora(int identificador, int comunidade, int linha, int coluna);
	~Cuidadora();
};

class Vigilante : public Formiga
{
public:
	Vigilante(int identificador, int comunidade, int linha, int coluna);
	~Vigilante();
};

class Assaltante : public Formiga
{
public:
	Assaltante(int identificador, int comunidade, int linha, int coluna);
	~Assaltante();
};

class Exploradora : public Formiga
{
public:
	Exploradora(int identificador, int comunidade, int linha, int coluna);
	~Exploradora();
};

#endif