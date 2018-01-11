#include "Mundo.h"

Mundo::Mundo()
{
}

Mundo::~Mundo()
{
}

void Mundo::setTam(int tam){
	this->tamanho = tam;
}

int Mundo::getTam(){
	return tamanho;
}

int Mundo::getSizeNinhos() { return ninhos.size(); }

int Mundo::getSizeOfNinhoX(int ninho) { return ninhos[ninho]->getSizeFormigas(); }

/*void Mundo::getDadosFormiga(int ninho, int formiga, int *identificador, int *linha, int *coluna) {
	ninhos[formiga]->getDadosFormiga(formiga, identificador, linha, coluna);
}*/

int Mundo::getIdentificadorFormiga(int ninho, int formiga) { return ninhos[ninho]->getIdentificadorFormiga(formiga); }
int Mundo::getLinhaFormiga(int ninho, int formiga) { return ninhos[ninho]->getLinhaFormiga(formiga); }
int Mundo::getColunaFormiga(int ninho, int formiga) { return ninhos[ninho]->getColunaFormiga(formiga); }

int Mundo::getIdentificadorNinho(int ninho) { return ninhos[ninho]->getIdentificador(); }
int Mundo::getLinhaNinho(int ninho) { return ninhos[ninho]->getLinha(); }
int Mundo::getColunaNinho(int ninho) { return ninhos[ninho]->getColuna(); }

void Mundo::novoNinho(int energia, int linha, int coluna) {
	Ninho * newNinho = new Ninho(ninhos.size()+1, energia, linha, coluna);
	ninhos.push_back(newNinho);
}

void Mundo::novaFormiga(string tipo, int ninho) {
	int linha = 2, coluna = 2;

	//gera e verifica a posicao aleatoria para a formiga

	if (tipo.compare("c") == 0)
		ninhos[ninho - 1]->novaCuidadora(ninho, linha, coluna);
	else if (tipo.compare("v") == 0)
		ninhos[ninho - 1]->novaVigilante(ninho, linha, coluna);
	else if (tipo.compare("a") == 0)
		ninhos[ninho - 1]->novaAssaltante(ninho, linha, coluna);
	else if (tipo.compare("e") == 0)
		ninhos[ninho - 1]->novaExploradora(ninho, linha, coluna);
}

void Mundo::novaFormiga(string tipo, int ninho, int linha, int coluna) {
	if (tipo.compare("c") == 0)
		ninhos[ninho - 1]->novaCuidadora(ninho, linha, coluna);
	else if (tipo.compare("v") == 0)
		ninhos[ninho - 1]->novaVigilante(ninho, linha, coluna);
	else if (tipo.compare("a") == 0)
		ninhos[ninho - 1]->novaAssaltante(ninho, linha, coluna);
	else if (tipo.compare("e") == 0)
		ninhos[ninho - 1]->novaExploradora(ninho, linha, coluna);
}

void Mundo::novaMigalha(int energia, int linha, int coluna) {
	Migalha * newMigalha = new Migalha(energia, linha, coluna);
	migalhas.push_back(newMigalha);
}

void Mundo::addEnergiaNinho(int ninho, int energia){
	ninhos[ninho - 1]->addEnergia(energia);
}

void Mundo::addEnergiaFormiga(int linha, int coluna, int energia) {
	for (int i = 0; i < ninhos.size(); i++) {
		for (int j = 0; j < ninhos[i]->getSizeFormigas(); j++) {
			if (ninhos[i]->getLinhaFormiga(j) == linha && ninhos[i]->getColunaFormiga(j) == coluna)
				ninhos[i]->addEnergiaFormiga(j, energia);
		}
	}
}

void Mundo::apagaNinho(int ninho) {
	ninhos[ninho]->~Ninho();
}