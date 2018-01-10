#include "Simulacao.h"

Simulacao::Simulacao()
{
}


Simulacao::~Simulacao()
{
}

void Simulacao::setUp(){
	string linha;
	string cmd, aux1;
	
	do {
		linha = f.setUp();
		stringstream is(linha);
		is >> cmd >> aux1;
		
		if (cmd.compare("defmundo") == 0)
			this->mundo = stoi(aux1);
		else if (cmd.compare("defen") == 0)
			this->en = stoi(aux1);
		else if (cmd.compare("defpc") == 0)
			this->pc = stoi(aux1);
		else if (cmd.compare("defvt") == 0)
			this->vt = stoi(aux1);
		else if (cmd.compare("defmi") == 0)
			this->mi = stoi(aux1);
		else if (cmd.compare("defme") == 0)
			this->me = stoi(aux1);
		else if (cmd.compare("defnm") == 0)
			this->nm = stoi(aux1);
		else if (cmd.compare("executa") == 0) {
			//carrega ficheiro
		}
	} while (linha.compare("inicio") != 0);
}

void Simulacao::simulacao() {
	string linha, cmd, aux1, aux2, aux3;

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
			
		}
		else if (cmd.compare("migalha") == 0) {
			
		}
		else if (cmd.compare("foca") == 0) {
			
		}
		else if (cmd.compare("energninho") == 0) {
			
		}
		else if (cmd.compare("energformiga") == 0) {
			
		}
		else if (cmd.compare("mata") == 0) {
			
		}
		else if (cmd.compare("inseticida") == 0) {
			
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
			//if tiver um valor a frente do cmd passar varias iteraçoes com um int decrescente
		}
	} while (linha.compare("sair") != 0);

	system("pause");
}

void Simulacao::finalizacao() {
	f.finalizacao();
}