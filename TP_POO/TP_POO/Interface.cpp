#include "Interface.h"
#include "Consola.h"

Interface::Interface()
{
}


Interface::~Interface()
{
}

string Interface::setUp() {
	string linha;

	Consola::setScreenSize(30, 121);
	Consola::clrscr();
	do {
		Consola::gotoxy(40, 2);
		cout << "-----------------------------------------";
		Consola::gotoxy(40, 3);
		cout << "|                                       |";
		Consola::gotoxy(40, 4);
		cout << "|         Menu de configuracao:         |";
		Consola::gotoxy(40, 5);
		cout << "|                                       |";
		Consola::gotoxy(40, 6);
		cout << "-----------------------------------------";
		Consola::gotoxy(3, 7);
		cout << "Comandos: \n \n";
		Consola::gotoxy(6, 8);
		cout << "defmundo <limite> - Define o tamanho do mundo.\n";
		Consola::gotoxy(6, 9);
		cout << "defen <energia> - Define o valor inicial da energia dos ninhos.\n";
		Consola::gotoxy(6, 10);
		cout << "defpc <valor> - Define percentagem de energia a partir do qual o ninho faz uma formiga.\n";
		Consola::gotoxy(6, 11);
		cout << "defvt <valor> - Define o número de unidades de energia transferidas entre ninho e formiga por iteracao.\n";
		Consola::gotoxy(6, 12);
		cout << "defmi <valor 0-100> - Define a percentagem inicial de posicoes vazias que tem (inicialmente)migalhas.\n";
		Consola::gotoxy(6, 13);
		cout << "defme <energia> -  Define a energia inicial das novas migalhas.\n";
		Consola::gotoxy(6, 14);
		cout << "defnm <max> - - Define o numero maximo de migalhas a serem criadas a cada instante.\n";
		Consola::gotoxy(6, 15);
		cout << "executa <nome do mundo.txt>- Le comandos de um ficheiro de texto (mundo pre-definido).\n";
		Consola::gotoxy(6, 16);
		cout << "<inicio> - Se os parametros anteriores estiverem preenchidos, este passa a simular o mundo.\n";
		Consola::gotoxy(6, 19);
		cout << "comando >> ";
		getline(cin, linha);
		Consola::clrscr();
		if (testaComandoSetUp(linha) == false) {
			Consola::gotoxy(3, 18);
			cout << "comando invalido" << endl;
		}
	} while (testaComandoSetUp(linha) == false);
	
	return linha;
}

bool Interface::testaComandoSetUp(string linha){
	string cmd, aux1;
	stringstream is(linha);
	is >> cmd >> aux1;

	if (cmd.compare("defmundo") == 0) {
		if (stoi(aux1) < 10)
			return false;
		else
			return true;
	}else if (cmd.compare("defen") == 0) {
		if (stoi(aux1) < 0)
			return false;
		else
			return true;
	}else if (cmd.compare("defpc") == 0) {
		if (stoi(aux1) < 0 || stoi(aux1) > 100)
			return false;
		else
			return true;
	}else if (cmd.compare("defvt") == 0) {
		if (stoi(aux1) < 0)
			return false;
		else
			return true;
	}else if (cmd.compare("defmi") == 0) {
		if (stoi(aux1) < 0 || stoi(aux1) > 100)
			return false;
		else
			return true;
	}else if (cmd.compare("defme") == 0) {
		if (stoi(aux1) < 0)
			return false;
		else
			return true;
	}else if (cmd.compare("defnm") == 0) {
		if (stoi(aux1) < 0)
			return false;
		else
			return true;
	}else if (cmd.compare("executa") == 0)
		return true;
	else if (cmd.compare("inicio") == 0)
		return true;
	else
		return false;
}

string Interface::printInterface(Mundo * m, int mundo, int focol, int fococ) {
	string linha;

	Consola::setScreenSize(30, 112);
	Consola::setBackgroundColor(0);
	Consola::setTextColor(15);
	do {
		printMapa(mundo);
		/*printFormigas(m, focol, fococ);
		printNinhos(m, focol, fococ);
		printMigalhas(m, focol, fococ);*/
		Consola::gotoxy(70, 1);
		cout << "----------------------------------------" << endl;
		Consola::gotoxy(70, 2);
		cout << "|                                      |" << endl;
		Consola::gotoxy(70, 3);
		cout << "|        Comandos da simulacao         |" << endl;
		Consola::gotoxy(70, 4);
		cout << "|                                      |" << endl;
		Consola::gotoxy(70, 5);
		cout << "----------------------------------------" << endl;
		Consola::gotoxy(70, 6);
		cout << "Comandos possiveis: ";
		Consola::gotoxy(73, 7);
		cout << "-> ninho <linha> <coluna> ";
		Consola::gotoxy(73, 8);
		cout << "-> criaf <F> <T> <N> \n";
		Consola::gotoxy(73, 9);
		cout << "-> cria1 <T> <N> <linha> <coluna>";
		Consola::gotoxy(73, 10);
		cout << "-> migalha <linha> <coluna> ";
		Consola::gotoxy(73, 11);
		cout << "-> foca <linha, coluna> ";
		Consola::gotoxy(73, 12);
		cout << "-> tempo";
		Consola::gotoxy(73, 13);
		cout << "-> tempo <n>";
		Consola::gotoxy(73, 14);
		cout << "-> energninho <N> <E>";
		Consola::gotoxy(73, 15);
		cout << "-> energformiga <linha> <coluna> <E>";
		Consola::gotoxy(73, 16);
		cout << "-> mata <linha> <coluna>";
		Consola::gotoxy(73, 17);
		cout << "-> inseticida <N>";
		Consola::gotoxy(73, 18);
		cout << "-> listamundo";
		Consola::gotoxy(73, 19);
		cout << "-> listaninho <N>";
		Consola::gotoxy(73, 20);
		cout << "-> listaposicao <linha> <coluna>";
		Consola::gotoxy(73, 21);
		cout << "-> guarda <nome>";
		Consola::gotoxy(73, 22);
		cout << "-> muda <nome>";
		Consola::gotoxy(73, 23);
		cout << "-> apaga <nome>";
		Consola::gotoxy(73, 24);
		cout << "-> sair";
		Consola::gotoxy(3, 25);
		cout << "comando >> ";
		getline(cin, linha);
		Consola::clrscr();
		if (testaComandoSimulacao(linha, mundo) == false) {
			Consola::gotoxy(3, 26);
			cout << "comando invalido" << endl;
		}
	} while (testaComandoSimulacao(linha, mundo) == false);

	return linha;
}

bool Interface::testaComandoSimulacao(string linha, int mundo) {
	string cmd, aux1, aux2, aux3;
	stringstream is(linha);
	is >> cmd;
	
	if (cmd.compare("ninho") == 0) {
		return true;
	}else if (cmd.compare("criaf") == 0) {
		return true;
	}else if (cmd.compare("cria1") == 0) {
		return true;
	}else if (cmd.compare("migalha") == 0) {
		return true;
	}else if (cmd.compare("foca") == 0) {
		return true;
	}else if (cmd.compare("tempo") == 0) {
		return true;
	}else if (cmd.compare("energninho") == 0) {
		return true;
	}else if (cmd.compare("energformiga") == 0) {
		return true;
	}else if (cmd.compare("mata") == 0) {
		return true;
	}else if (cmd.compare("inseticida") == 0) {
		return true;
	}else if (cmd.compare("listamundo") == 0) {
		return true;
	}else if (cmd.compare("listaninho") == 0) {
		return true;
	}else if (cmd.compare("listaposicao") == 0) {
		return true;
	}else if (cmd.compare("guarda") == 0) {
		return true;
	}else if (cmd.compare("muda") == 0) {
		return true;
	}else if (cmd.compare("apaga") == 0) {
		return true;
	}else if (cmd.compare("sair") == 0) {
		return true;
	}else
		return false;
}

void Interface::printMapa(int tam) {
	/*int tami = tam, tamj = tam;
	if (tam > 20) {
		tamj = 20;
		if (tam > 50)
			tami = 50;
		else
			tami = tam;
	}*/

	if (tam > 20)
		tam = 20;

	for (int i = 0; i < tam+2; i++) {
		Consola::gotoxy(i+2, 1); cout << char(205);
		Consola::gotoxy(i+2, tam+2); cout << char(205);
	}

	for (int j = 0; j < tam+2; j++) {
		Consola::gotoxy(2, j + 1); cout << char(186);
		Consola::gotoxy(tam+3, j + 1); cout << char(186);
	}

	Consola::gotoxy(2, 1); cout << char(201);
	Consola::gotoxy(2, tam+2); cout << char(200);
	Consola::gotoxy(tam+3, 1); cout << char(187);
	Consola::gotoxy(tam+3, tam+2); cout << char(188);

	Consola::setBackgroundColor(15);
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			Consola::gotoxy(i + 3, j + 2);
			cout << ' ';
		}
	}

	Consola::setBackgroundColor(0);
}

void Interface::printFormigas(Mundo * m, int focol, int fococ) {
	//asd
}

void Interface::printNinhos(Mundo * m, int focol, int fococ) {
	//asd
}

void Interface::printMigalhas(Mundo * m, int focol, int fococ) {
	//asd
}

void Interface::finalizacao() {
	Consola::clrscr();
	Consola::gotoxy(1, 2);
	cout << "Acabou" << endl;
	Consola::gotoxy(1, 4);
	system("pause");
}