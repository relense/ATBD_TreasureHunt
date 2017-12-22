#ifndef GESTORTESOUROS_H_INCLUDED
#define GESTORTESOUROS_H_INCLUDED
#include "tesouros.h"
#include "stackEstaticoTesouros.h"
#include "stackDinamicoTesouros.h"
#include "mapa.h"

typedef PtStackET StackET;
typedef PtStackDT StackDT;

void leTesourosFicheiroEstatico(PtStackET stack, Tesouro tesouro, FILE* tesouros, Mapa mapa);
void leTesourosFicheiroDinamico(PtStackDT stack, Tesouro tesouro, FILE* tesouros, Mapa mapa);

#endif // GESTORTESOUROS_H_INCLUDED
