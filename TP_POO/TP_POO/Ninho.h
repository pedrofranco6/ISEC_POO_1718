#pragma once
#ifndef NINHO_H
#define NINHO_H

#include <vector>

using namespace std;
#include "Formiga.h"

class Ninho
{
	vector<Formiga *> formigas;
public:
	Ninho();
	~Ninho();
};

#endif