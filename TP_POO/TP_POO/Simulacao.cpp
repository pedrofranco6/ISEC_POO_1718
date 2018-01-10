#include "Simulacao.h"

Simulacao::Simulacao()
{
}


Simulacao::~Simulacao()
{
}

void Simulacao::setUp(){
	string linha, cmd;
	
	do {
		linha = f.setUp();
		stringstream is(linha);
		is >> cmd;
		
		if (cmd.compare("defmundo") == 0) {
			int aux1;
			is >> aux1;
			this->mundo = aux1;
		}
		else if (cmd.compare("defen") == 0) {
			int aux1;
			is >> aux1;
			this->en = aux1;
		}
		else if (cmd.compare("defpc") == 0) {
			int aux1;
			is >> aux1;
			this->pc = aux1;
		}
		else if (cmd.compare("defvt") == 0) {
			int aux1;
			is >> aux1;
			this->vt = aux1;
		}
		else if (cmd.compare("defmi") == 0) {
			int aux1;
			is >> aux1;
			this->mi = aux1;
		}
		else if (cmd.compare("defme") == 0) {
			int aux1;
			is >> aux1;
			this->me = aux1;
		}
		else if (cmd.compare("defnm") == 0) {
			int aux1;
			is >> aux1;
			this->nm = aux1;
		}
		else if (cmd.compare("executa") == 0) {
			string aux1;
			is >> aux1;
			ifstream infile;
			infile.open(aux1);
			infile >> linha;
			stringstream iss(linha);
			iss >> mundo >> en >> pc >> vt >> mi >> me >> nm;
		}
	} while (linha.compare("inicio") != 0);
}

void Simulacao::simulacao() {
	string linha, cmd;

	do {
		linha = f.printInterface(m, mundo, focol, fococ);
		stringstream is(linha);
		is >> cmd;

		if (cmd.compare("ninho") == 0) {
			int linha, coluna;
			is >> linha >> coluna;
			m->novoNinho(en, linha, coluna);
		}
		else if (cmd.compare("criaf") == 0) {
			int num, ninho;
			string tipo;
			is >> num >> tipo >> ninho;

			for (int i = 0; i < num; i++)
				m->novaFormiga(tipo, ninho);
		}
		else if (cmd.compare("cria1") == 0) {
			int ninho, linha, coluna;
			string tipo;
			is >> tipo >> ninho >> linha >> coluna;
			m->novaFormiga(tipo, ninho, linha, coluna);
		}
		else if (cmd.compare("migalha") == 0) {
			int linha, coluna;
			is >> linha >> coluna;
			m->novaMigalha(me, linha, coluna);
		}
		else if (cmd.compare("foca") == 0) {
			//ainda nao implementado
		}
		else if (cmd.compare("energninho") == 0) {
			int ninho, energia;
			is >> ninho >> energia;
			m->addEnergiaNinho(ninho, energia);
		}
		else if (cmd.compare("energformiga") == 0) {
			int linha, coluna, energia;
			is >> linha >> coluna >> energia;
			m->addEnergiaFormiga(linha, coluna, energia);
		}
		else if (cmd.compare("mata") == 0) {
			//perguntar pelos destrutores
		}
		else if (cmd.compare("inseticida") == 0) {
			//perguntar pelos destrutores
		}
		else if (cmd.compare("listamundo") == 0) {
			
		}
		else if (cmd.compare("listaninho") == 0) {
			
		}
		else if (cmd.compare("listaposicao") == 0) {
			
		}
		else if (cmd.compare("guarda") == 0) {

		}
		else if (cmd.compare("muda") == 0) {

		}
		else if (cmd.compare("apaga") == 0) {

		}
		else if (cmd.compare("tempo") == 0){
			/*iteração*/
			//m->agir();
			/*void agir(){
				for(int i=0; i<ninhos[].size(); i++){
					asd
				}
			}*/
			//if tiver um valor a frente do cmd passar varias iteraçoes com um int decrescente
		}
	} while (linha.compare("sair") != 0);

	system("pause");
}

void Simulacao::finalizacao() {
	f.finalizacao();
}