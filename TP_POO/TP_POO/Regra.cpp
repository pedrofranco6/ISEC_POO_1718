#include "Regra.h"

bool RegraFoge::condicao(Mundo *m, Formiga *f) { return false; }
void RegraFoge::acao(Mundo *m, Formiga *f) {}

bool RegraPersegue::condicao(Mundo *m, Formiga *f) { return false; }
void RegraPersegue::acao(Mundo *m, Formiga *f) {}

bool RegraAssalta::condicao(Mundo *m, Formiga *f) { return false; }
void RegraAssalta::acao(Mundo *m, Formiga *f) {}

bool RegraProtege::condicao(Mundo *m, Formiga *f) { return false; }
void RegraProtege::acao(Mundo *m, Formiga *f) {}

bool RegraVaiParaNinho::condicao(Mundo *m, Formiga *f) { return false; }
void RegraVaiParaNinho::acao(Mundo *m, Formiga *f) {}

bool RegraProcuraMigalha::condicao(Mundo *m, Formiga *f) { return false; }
void RegraProcuraMigalha::acao(Mundo *m, Formiga *f) {}

bool RegraComeMigalha::condicao(Mundo *m, Formiga *f) { 
	for (int i = 0; i < m->getSizeMigalhas(); i++) {
		if (f->getLinha() == m->getMigalha(i)->getLinha() && f->getColuna() == m->getMigalha(i)->getColuna()) {
			migalha = i;
			return true;
		}
	}
	
	return false;
}
void RegraComeMigalha::acao(Mundo *m, Formiga *f) {
	if (f->getTipo() == 'c') {
		f->addEnergia(m->getMigalha(migalha)->getEnergia() / 2 - 1);
		m->getMigalha(migalha)->setEnergia(m->getMigalha(migalha)->getEnergia() / 2);
	} else if (f->getTipo() == 'v') {
		f->addEnergia(m->getMigalha(migalha)->getEnergia() * 0.75 - 1);
		m->getMigalha(migalha)->setEnergia(m->getMigalha(migalha)->getEnergia() * 0.25);
	} else if (f->getTipo() == 'a') {
		f->addEnergia(m->getMigalha(migalha)->getEnergia() * 0.25 - 1);
		m->getMigalha(migalha)->setEnergia(m->getMigalha(migalha)->getEnergia() * 0.75);
	} else if (f->getTipo() == 'e') {
		f->addEnergia(m->getMigalha(migalha)->getEnergia() - 1);
		m->getMigalha(migalha)->setEnergia(0);
	}
}

bool RegraPasseia::condicao(Mundo *m, Formiga *f) { return true; }
void RegraPasseia::acao(Mundo *m, Formiga *f) {
	int linha, coluna;
	srand((unsigned int)time(NULL));

	do {
		linha = f->getLinha() + rand() % (2 * f->getMovimento() + 1) + 1 - f->getMovimento();
		coluna = f->getColuna() + rand() % (2 * f->getMovimento() + 1) + 1 - f->getMovimento();
	} while ( linha > m->getTam() || linha < 1 || coluna > m->getTam() || coluna < 1);

	f->mover(linha, coluna);
}
