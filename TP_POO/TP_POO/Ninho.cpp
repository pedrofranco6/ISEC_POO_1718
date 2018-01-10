#include "Ninho.h"


Ninho::Ninho(int identificador, int energia, int linha, int coluna)
{
	this->identificador = identificador;
	this->energia = energia;
	this->linha = linha;
	this->coluna = coluna;
}

Ninho::~Ninho()
{
}

int Ninho::getLinha() { return linha; }

int Ninho::getColuna() { return coluna; }