#include "Migalha.h"


Migalha::Migalha(int energia, int linha, int coluna)
{
	this->energia = energia;
	this->linha = linha;
	this->coluna = coluna;
}

Migalha::~Migalha()
{
}

int Migalha::getLinha() { return linha; }
int Migalha::getColuna() { return coluna; }
int Migalha::getEnergia() { return energia; }
void Migalha::setEnergia(int energia) { this->energia = energia; }