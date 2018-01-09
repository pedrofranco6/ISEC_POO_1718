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
	
	f.printInterface(m, mundo, focol, fococ);

	system("pause");
}

void Simulacao::finalizacao() {
	f.finalizacao();
}