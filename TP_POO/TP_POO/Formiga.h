#pragma once
#ifndef FORMIGA_H
#define FORMIGA_H

#include <vector>

using namespace std;
#include "Regra.h"

class Formiga
{
	vector<Regra> regras;
public:
	Formiga();
	~Formiga();
};

class Cuidadora : public Formiga
{
public:
	Cuidadora();
	~Cuidadora();
};

class Vigilante : public Formiga
{
public:
	Vigilante();
	~Vigilante();
};

class Assaltante : public Formiga
{
public:
	Assaltante();
	~Assaltante();
};

class Exploradora : public Formiga
{
public:
	Exploradora();
	~Exploradora();
};

#endif