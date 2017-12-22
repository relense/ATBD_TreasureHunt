#ifndef GESTORMOVIMENTO_H_INCLUDED
#define GESTORMOVIMENTO_H_INCLUDED
#include "movimentos.h"
#include "stackEstatico.h"
#include "stackDinamico.h"
#include "filaEstatica.h"
#include "filaDinamica.h"

typedef PtStackE StackE;
typedef PtStackD StackD;
typedef PtQueue  Queue;
typedef PtQueueD QueueD;

void leMovimentosFicheiro(PtQueue queue, Movimento movimento, FILE* movimentos);
void decompoemMoveEstatico(StackE guarda, StackE redo, Movimento movimento);
void ordenaPilha(StackE guarda, StackE ordenado);
void passarFila(StackE stackEstatico, PtQueue queue);

void leMovimentosFicheiroDinamico(PtQueueD queue, Movimento movimento, FILE* movimentos);
void decompoemMoveDinamico(StackD guarda, StackD redo, Movimento movimento);
void ordenaPilhaDinamico(StackD guarda, StackD ordenada);
void passarFilaDinamico(StackD ordenada, PtQueueD queueD);


#endif // GESTORMOVIMENTO_H_INCLUDED
