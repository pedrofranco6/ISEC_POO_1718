#pragma once
#ifndef REGRA_H
#define REGRA_H

#include <time.h>

#include "Mundo.h"
#include "Formiga.h"

class Mundo;
class Formiga;

class Regra {
public:
	virtual bool condicao(Mundo *m, Formiga *f) = 0;
	virtual void acao(Mundo *m, Formiga *f) = 0;
};

class RegraFoge : public Regra {
public:
	virtual bool condicao(Mundo *m, Formiga *f);
	virtual void acao(Mundo *m, Formiga *f);
};

class RegraPersegue : public Regra {
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
	int migalha;
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