#pragma once
#ifndef FORMIGA_H
#define FORMIGA_H

#include <vector>

using namespace std;
#include "Regra.h"

class Formiga
{
protected:
	int identificador, comunidade, energia, linha, coluna;
	vector<Regra  *> regras;
public:
	Formiga();
	~Formiga();
	int getLinha();
	int getColuna();
	void addEnergia(int energia);
};

class Cuidadora : public Formiga
{
	int visao = 5, movimento = 3;
public:
	Cuidadora(int identificador, int comunidade, int linha, int coluna);
	~Cuidadora();
};

class Vigilante : public Formiga
{
	int visao = 7, movimento = 5;
public:
	Vigilante(int identificador, int comunidade, int linha, int coluna);
	~Vigilante();
};

class Assaltante : public Formiga
{
	int visao = 8, movimento = 4;
public:
	Assaltante(int identificador, int comunidade, int linha, int coluna);
	~Assaltante();
};

class Exploradora : public Formiga
{
	int visao = 10, movimento = 8;
public:
	Exploradora(int identificador, int comunidade, int linha, int coluna);
	~Exploradora();
};

#endif