#ifndef GESTORLOCALIZACOES_H_INCLUDED
#define GESTORLOCALIZACOES_H_INCLUDED
#include "localizacao.h"
#include "stackEstaticoLocalizacao.h"
#include "stackDinamicoLocalizacao.h"

typedef PtStackEL StackEL;
typedef PtStackDL StackDL;

void contarLocalizacoes(PtStackEL stackL);
void contador(PtStackEL stack, Localizacao localizacao);
void confirm(PtStackEL stack);

void contarLocalizacoesDinamico(PtStackDL stackL);
void contadorDinamico(PtStackDL stack, Localizacao localizacao);
void confirmDinamico(PtStackDL stack);

#endif // GESTORLOCALIZACOES_H_INCLUDED
