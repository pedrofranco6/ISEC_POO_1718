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

int Ninho::getIdentificador() { return identificador; }
int Ninho::getLinha() { return linha; }
int Ninho::getColuna() { return coluna; }

int Ninho::getSizeFormigas() { return formigas.size(); }

int Ninho::getIdentificadorFormiga(int formiga) { return formigas[formiga]->getIdentificador(); }
int Ninho::getLinhaFormiga(int formiga) { return formigas[formiga]->getLinha(); }
int Ninho::getColunaFormiga(int formiga) { return formigas[formiga]->getColuna(); }
int Ninho::getEnergia() { return energia; }

void Ninho::novaCuidadora(int comunidade, int linha, int coluna){
	Cuidadora * newCuidadora = new Cuidadora(formigas.size() + 1, comunidade, linha, coluna);
	formigas.push_back(newCuidadora);
}

void Ninho::novaVigilante(int comunidade, int linha, int coluna){
	Vigilante * newVigilante = new Vigilante(formigas.size() + 1, comunidade, linha, coluna);
	formigas.push_back(newVigilante);
}

void Ninho::novaAssaltante(int comunidade, int linha, int coluna){
	Assaltante * newAssaltante = new Assaltante(formigas.size() + 1, comunidade, linha, coluna);
	formigas.push_back(newAssaltante);
}

void Ninho::novaExploradora(int comunidade, int linha, int coluna){
	Exploradora * newExploradora = new Exploradora(formigas.size() + 1, comunidade, linha, coluna);
	formigas.push_back(newExploradora);
}

void Ninho::addEnergia(int energia) {
	this->energia += energia;
}

void Ninho::addEnergiaFormiga(int formiga, int energia) {
	formigas[formiga]->addEnergia(energia);
}

Formiga * Ninho::getFormiga(int formiga) { return formigas[formiga]; }

void Ninho::apagaFormiga(int formiga) {
	formigas.erase(formigas.begin() + formiga);
}