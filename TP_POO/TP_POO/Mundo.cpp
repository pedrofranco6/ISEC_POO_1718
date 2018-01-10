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

void Mundo::novoNinho(int energia, int linha, int coluna) {
	Ninho * newNinho = new Ninho(ninhos.size()+1, energia, linha, coluna);
	ninhos.push_back(newNinho);
}

void Mundo::novaFormiga(string tipo, int ninho) {
	if (tipo.compare("c") == 0) {

	}
	else if (tipo.compare("v") == 0) {

	}
	else if (tipo.compare("a") == 0) {

	}
	else if (tipo.compare("e") == 0) {

	}
	else if (tipo.compare("s") == 0) {
		//ainda nao faz nada
	}
}