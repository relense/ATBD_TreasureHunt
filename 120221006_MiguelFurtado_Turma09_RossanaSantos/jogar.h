#ifndef JOGAR_H_INCLUDED
#define JOGAR_H_INCLUDED
#include "stackDinamicoLocalizacao.h"
#include "stackEstaticoLocalizacao.h"
#include "filaDinamica.h"
#include "filaEstatica.h"
#include "stackDinamicoTesouros.h"
#include "stackEstaticoTesouros.h"
#include "mapa.h"
#include "localizacaoAtual.h"
#include "localizacao.h"

typedef PtStackEL StackEl;
typedef PtStackDL StackDl;
typedef PtStackET StackET;
typedef PtStackDT StackDT;
typedef PtQueue  Queue;
typedef PtQueueD QueueD;

void jogaEstatico(PtStackET stack, PtQueue queue, Mapa mapa, PtStackEL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao);
void leMove(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackEL stack, PtStackET stackT, LocalizacaoAtual localizacaoAtual);
void leLoop(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackEL stack, PtStackET stackT, LocalizacaoAtual localizacaoAtual);
void leJump(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackEL stack, PtStackET stackT, LocalizacaoAtual localizacaoAtual);
void existeTesouro(Localizacao localizacao, PtStackET stackt, LocalizacaoAtual localizacaoAtual, Mapa mapa);
void imprimePilhaLocalizacoes(PtStackEL stack, LocalizacaoAtual ultimaLocalizacao);

void jogaDinamico(PtStackDT stack, PtQueueD queue, Mapa mapa, PtStackDL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao);
void leMoveDinamico(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackDL stack, PtStackDT stackT, LocalizacaoAtual localizacaoAtual);
void leLoopDinamico(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackDL stack, PtStackDT stackT, LocalizacaoAtual localizacaoAtual);
void leJumpDinamico(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackDL stack, PtStackDT stackT, LocalizacaoAtual localizacaoAtual);
void existeTesouroDinamico(Localizacao localizacao, PtStackDT stackt, LocalizacaoAtual localizacaoAtual, Mapa mapa);
void imprimePilhaLocalizacoesDinamica(PtStackDL stack, LocalizacaoAtual ultimaLocalizacao);


#endif // JOGAR_H_INCLUDED
