#include "Formiga.h"

//é mesmo preciso construtores para a Formiga? ela nunca vai ser cirada...
Formiga::Formiga()
{
}

Formiga::~Formiga()
{
}

int Formiga::getIdentificador() { return identificador; }

int Formiga::getLinha() { return linha; }

int Formiga::getColuna() { return coluna; }

int Formiga::getVisao() { return visao; }

int Formiga::getMovimento() { return movimento; }

void Formiga::addEnergia(int energia) {
	this->energia += energia;
}

void Formiga::fazRegras(Mundo *m) {
	for (int i = 0; i < regras.size(); i++) {
		if (regras[i]->condicao(m, this)) {
			regras[i]->acao(m, this);
			break;
		}
	}
}

void Formiga::mover(int linha, int coluna) {
	this->linha = linha;
	this->coluna = coluna;
}

Cuidadora::Cuidadora(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 100;
	this->visao = 5;
	this->movimento = 3;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	regras.push_back(new RegraFoge);
	regras.push_back(new RegraComeMigalha);
	regras.push_back(new RegraProcuraMigalha);
	regras.push_back(new RegraVaiParaNinho);
	regras.push_back(new RegraPasseia);
}

Cuidadora::~Cuidadora()
{
}


Vigilante::Vigilante(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 150;
	this->visao = 7;
	this->movimento = 5;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	regras.push_back(new RegraProtege);
	regras.push_back(new RegraComeMigalha);
	regras.push_back(new RegraProcuraMigalha);
	regras.push_back(new RegraPasseia);
}

Vigilante::~Vigilante()
{
}


Assaltante::Assaltante(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 80;
	this->visao = 8;
	this->movimento = 4;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	regras.push_back(new RegraAssalta);
	regras.push_back(new RegraPersegue);
	regras.push_back(new RegraComeMigalha);
	regras.push_back(new RegraProcuraMigalha);
	regras.push_back(new RegraPasseia);
}

Assaltante::~Assaltante()
{
}


Exploradora::Exploradora(int identificador, int comunidade, int linha, int coluna)
{
	this->energia = 200;
	this->visao = 10;
	this->movimento = 8;
	this->identificador = identificador;
	this->comunidade = comunidade;
	this->linha = linha;
	this->coluna = coluna;
	regras.push_back(new RegraComeMigalha);
	regras.push_back(new RegraPasseia);
}

Exploradora::~Exploradora()
{
}