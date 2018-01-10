#include "Formiga.h"

//é mesmo preciso construtores para a Formiga? ela nunca vai ser cirada...
Formiga::Formiga()
{
}

Formiga::~Formiga()
{
}

int Formiga::getLinha() { return linha; }

int Formiga::getColuna() { return coluna; }

void Formiga::addEnergia(int energia) {
	this->energia += energia;
}

Cuidadora::Cuidadora(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 100;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	//vector de regras
}

Cuidadora::~Cuidadora()
{
}


Vigilante::Vigilante(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 150;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	//vector de regras
}

Vigilante::~Vigilante()
{
}


Assaltante::Assaltante(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 80;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	//vector de regras
	//so 1 regra acontece
}

Assaltante::~Assaltante()
{
}


Exploradora::Exploradora(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 200;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	//vector de regras
}

Exploradora::~Exploradora()
{
}