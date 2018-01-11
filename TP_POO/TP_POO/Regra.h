#pragma once
#ifndef REGRA_H
#define REGRA_H

#include "Mundo.h"
#include "Formiga.h"

class Regra
{
public:
	virtual bool condicao(Mundo *m, Formiga *f) = 0;
	virtual void agir(Mundo *m, Formiga *f) = 0;
};

class RegraFoge : public Regra
{
	int x, y;// coordenadas do inimigo encontrado que sao atribuidos caso a condição seja verdadeira e possam ser usados //no agir
public:

	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};
class RegraPersegue : public Regra
{
	int x, y;// coordenadas do inimigo encontrado que sao atribuidos caso a condição seja verdadeira e possam ser usados //no agir
public:

	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};

class RegraAssalta : public Regra {
	
public:
	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};
class RegraProtege : public Regra {
public:
	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};
class RegraVaiParaNinho : public Regra {

public:
	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};

class RegraProcuraMigalha : public Regra {

public:
	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};

class RegraComeMigalha : public Regra {

public:
	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};
class RegraPasseia : public Regra {

public:
	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};

#endif