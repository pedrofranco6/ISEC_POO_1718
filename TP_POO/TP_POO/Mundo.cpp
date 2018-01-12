#include "Mundo.h"

Mundo::Mundo()
{
}

Mundo::~Mundo()
{
	for (auto c : ninhos) {
		c->~Ninho();
		delete c;
	}
	ninhos.clear();
}

void Mundo::setTam(int tam){
	this->tamanho = tam;
}

int Mundo::getTam(){
	return tamanho;
}

int Mundo::getSizeNinhos() { return ninhos.size(); }

int Mundo::getSizeOfNinhoX(int ninho) { return ninhos[ninho]->getSizeFormigas(); }

int Mundo::getSizeMigalhas() { return migalhas.size(); }

int Mundo::getLinhaMigalha(int migalha) { return migalhas[migalha]->getLinha(); }
int Mundo::getColunaMigalha(int migalha) { return migalhas[migalha]->getColuna(); }

/*void Mundo::getDadosFormiga(int ninho, int formiga, int *identificador, int *linha, int *coluna) {
	ninhos[formiga]->getDadosFormiga(formiga, identificador, linha, coluna);
}*/

int Mundo::getIdentificadorFormiga(int ninho, int formiga) { return ninhos[ninho]->getIdentificadorFormiga(formiga); }
int Mundo::getLinhaFormiga(int ninho, int formiga) { return ninhos[ninho]->getLinhaFormiga(formiga); }
int Mundo::getColunaFormiga(int ninho, int formiga) { return ninhos[ninho]->getColunaFormiga(formiga); }

int Mundo::getIdentificadorNinho(int ninho) { return ninhos[ninho]->getIdentificador(); }
int Mundo::getLinhaNinho(int ninho) { return ninhos[ninho]->getLinha(); }
int Mundo::getColunaNinho(int ninho) { return ninhos[ninho]->getColuna(); }

Migalha * Mundo::getMigalha(int migalha) { return migalhas[migalha]; }
Ninho * Mundo::getNinho(int ninho) { return ninhos[ninho]; }

void Mundo::novoNinho(int energia, int linha, int coluna) {
	Ninho * newNinho = new Ninho(ninhos.size()+1, energia, linha, coluna);
	ninhos.push_back(newNinho);
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
	ninhos.erase(ninhos.begin() + ninho);
	ninhos[ninho]->~Ninho();}

bool Mundo::posicaoLivre(int linha, int coluna) {
	if (migalhas.size() > 0) {
		for (int i = 0; i < migalhas.size(); i++) {
			if (migalhas[i]->getLinha() == linha && migalhas[i]->getColuna() == coluna)
				return false;
		}
	}

	if (ninhos.size() > 0) {
		for (int i = 0; i < ninhos.size(); i++) {
			if (ninhos[i]->getLinha() == linha && ninhos[i]->getColuna() == coluna)
				return false;
			if (ninhos[i]->getSizeFormigas() > 0) {
				for (int j = 0; j < ninhos[i]->getSizeFormigas(); j++) {
					if (ninhos[i]->getLinhaFormiga(j) == linha && ninhos[i]->getColunaFormiga(j) == coluna)
						return false;
				}
			}

		}
	}

	return true;
}

void Mundo::agirFormigas() {
	if (ninhos.size() > 0) {
		for (int i = 0; i < ninhos.size(); i++) {
			if (ninhos[i]->getSizeFormigas() > 0) {
				for (int j = 0; j < ninhos[i]->getSizeFormigas(); j++) {
					ninhos[i]->getFormiga(j)->fazRegras(this);
				}
			}
		}
	}
}
void Mundo::agirNinhos(int en, int pc) {
	for (int i = 0; i < ninhos.size(); i++) {
		if(ninhos[i]->getEnergia() > en*pc/100)
			novaFormiga("c", i+1, ninhos[i]->getLinha(), ninhos[i]->getColuna());
	}
}
void Mundo::agirMigalhas() {
	for (int i = 0; i < migalhas.size(); i++)
		migalhas[i]->setEnergia(migalhas[i]->getEnergia() - 1);
}


void Mundo::mataNinhos() {
	for (int i = 0; i < ninhos.size(); i++) {
		if (ninhos[i]->getEnergia() <= 0)
			ninhos.erase(ninhos.begin() + i);
	}
}
void Mundo::mataFormigas() {
	for (int i = 0; i < ninhos.size(); i++) {
		for (int j = 0; j < ninhos[i]->getSizeFormigas(); j++) {
			if (ninhos[i]->getFormiga(j)->getEnergia() <= 0)
				ninhos[i]->apagaFormiga(j);
		}
	}
}
void Mundo::mataMigalhas() {
	for (int i = 0; i < migalhas.size(); i++) {
		if (migalhas[i]->getEnergia() <= 0)
			migalhas.erase(migalhas.begin() + i);
	}
}