#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackDinamicoLocalizacao.h"
#include "stackEstaticoLocalizacao.h"
#include "filaDinamica.h"
#include "filaEstatica.h"
#include "stackDinamicoTesouros.h"
#include "stackEstaticoTesouros.h"
#include "mapa.h"
#include "jogar.h"
#include "movimentos.h"
#include "tesouros.h"
#include "localizacaoAtual.h"

void jogaEstatico(PtStackET stack, PtQueue queue, Mapa mapa, PtStackEL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao)
{
    LocalizacaoAtual localizacaoAtual = criaLocalizacaoAtual();
    Localizacao localizacao = criarLocalizacao();
    stackPushEstaticoL(stackLocalizacao, localizacao);
    Movimento movimento;

    unsigned int NLocalizacoes = 0;
    stackSizeEstaticoL(stackLocalizacao, &NLocalizacoes);

    printf("\n");
    while(!queueIsEmptyEstatico(queue) && NLocalizacoes <= 100)
    {
        queueDequeueEstatico(queue, &movimento);

        if(strncmp(movimento.nome, "MOVE", 4) == 0)
        {
            leMove(movimento, localizacao, mapa, stackLocalizacao, stack, localizacaoAtual);
        }
        if(strncmp(movimento.nome, "LOOP", 4) == 0)
        {
            leLoop(movimento, localizacao, mapa, stackLocalizacao, stack, localizacaoAtual);
        }
        if(strncmp(movimento.nome, "JUMP", 4) == 0)
        {
            leJump(movimento, localizacao, mapa, stackLocalizacao, stack, localizacaoAtual);
        }

        stackSizeEstaticoL(stackLocalizacao, &NLocalizacoes);
    }

    imprimePilhaLocalizacoes(stackLocalizacao, ultimaLocalizacao);
}

void leMove(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackEL stack, PtStackET stackT, LocalizacaoAtual localizacaoAtual)
{
    if( movimento.mover == 1 && localizacaoAtual->yAtual - 1 >= 0)
    {
        localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushEstaticoL(stack, localizacao);
        existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
    }

    else if(movimento.mover == 2 && localizacaoAtual->yAtual + 1 <= mapa->yMax)
    {
        localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushEstaticoL(stack, localizacao);
        existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
    }

    else if(movimento.mover == 3 && localizacaoAtual->xAtual + 1 <= mapa->xMax)
    {
        localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushEstaticoL(stack, localizacao);
        existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
    }

    else if(movimento.mover == 4 && localizacaoAtual->xAtual - 1 >= 0)
    {
        localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushEstaticoL(stack, localizacao);
        existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
    }
    else
        printf("MOVE(%d) Invalido - Sai fora do limite do mapa\n", movimento.mover);
}

void leLoop(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackEL stack, PtStackET stackT, LocalizacaoAtual localizacaoAtual)
{
    int numeroMovimento = movimento.numeroMoves;

    if( movimento.mover == 1 && localizacaoAtual->yAtual - 1 * movimento.numeroMoves >= 0)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushEstaticoL(stack, localizacao);
            existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
        }
    }

    else if(movimento.mover == 2 && localizacaoAtual->yAtual + 1 * movimento.numeroMoves <= mapa->yMax)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushEstaticoL(stack, localizacao);
            existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
        }
    }

    else if(movimento.mover == 3 && localizacaoAtual->xAtual + 1 * movimento.numeroMoves <= mapa->xMax)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushEstaticoL(stack, localizacao);
            existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
        }
    }

    else if(movimento.mover == 4 && localizacaoAtual->xAtual - 1 * movimento.numeroMoves >= 0)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushEstaticoL(stack, localizacao);
            existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
        }
    }
    else
        printf("LOOP(%d,%d) Invalido - Sai fora do limite do mapa\n", movimento.mover, movimento.numeroMoves);
}
void leJump(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackEL stack, PtStackET stackT, LocalizacaoAtual localizacaoAtual)
{
    if(movimento.x == localizacaoAtual->xAtual && movimento.y == localizacaoAtual->yAtual)
    {
        printf("já estou nessa posição não posso fazer JUMP\n");
    }

    else if(movimento.x == localizacaoAtual->xAtual && movimento.y != localizacaoAtual->yAtual && movimento.y <= mapa->yMax)
    {
        if(movimento.y > localizacaoAtual->yAtual)
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
    }

    else if(movimento.x != localizacaoAtual->xAtual && movimento.y == localizacaoAtual->yAtual && movimento.x <= mapa->xMax)
    {
        if(movimento.x > localizacaoAtual->xAtual)
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
    }

    else if(movimento.x != localizacaoAtual->xAtual && movimento.y != localizacaoAtual->yAtual && movimento.x <= mapa->xMax && movimento.y <= mapa->yMax)
    {
        if(movimento.x > localizacaoAtual->xAtual)
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }

        if(movimento.y > localizacaoAtual->yAtual)
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushEstaticoL(stack, localizacao);
                existeTesouro(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
    }
    else
        printf("JUMP(%d,%d) Invalido - Sai fora do limite do mapa\n",movimento.x, movimento.y);
}

void existeTesouro(Localizacao localizacao, PtStackET stackt, LocalizacaoAtual localizacaoAtual, Mapa mapa)
{
    Tesouro tesouro;
    PtStackET stack2 = stackCreateEstaticoT();

    while(!stackIsEmptyEstaticoT(stackt))
    {
        stackPopEstaticoT(stackt, &tesouro);

        if(tesouro.x == localizacaoAtual->xAtual  && tesouro.y == localizacaoAtual->yAtual)
        {
            if(tesouro.encontrado == 1)
            {
                stackPushEstaticoT(stack2, tesouro);
                break;
            }
            else
            {
                mapa->numeroTesouros++;
                tesouro.encontrado = 1;
                stackPushEstaticoT(stack2, tesouro);
                break;
            }
        }
        else
        {
            stackPushEstaticoT(stack2, tesouro);
        }
    }

    while(!stackIsEmptyEstaticoT(stack2))
    {
        stackPopEstaticoT(stack2, &tesouro);
        stackPushEstaticoT(stackt, tesouro);
    }

    stackDestroyEstaticoT(&stack2);
}

void imprimePilhaLocalizacoes(PtStackEL stack, LocalizacaoAtual ultimaLocalizacao)
{
    Localizacao localizacao;
    PtStackEL stack2 = stackCreateEstaticoL();

    unsigned int pelem = 0;
    stackSizeEstaticoL(stack, &pelem);
    printf("SIZE = %d\n", pelem);

    while(pelem > 0)
    {
        stackPopEstaticoL(stack, &localizacao);
        stackPushEstaticoL(stack2, localizacao);
        stackSizeEstaticoL(stack, &pelem);

    }

    stackSizeEstaticoL(stack2, &pelem);

    while(pelem > 0)
    {
        stackPopEstaticoL(stack2, &localizacao);
        printf("Localizacoes: X = %d -  Y = %d -  N = %d\n", localizacao.y, localizacao.x, localizacao.n);
        stackPushEstaticoL(stack, localizacao);
        stackSizeEstaticoL(stack2, &pelem);
        if(pelem == 0)
        {
            ultimaLocalizacao->xAtual = localizacao.x;
            ultimaLocalizacao->yAtual = localizacao.y;
        }
    }

    stackDestroyEstaticoL(&stack2);
}

void jogaDinamico(PtStackDT stack, PtQueueD queue, Mapa mapa, PtStackDL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao)
{
    LocalizacaoAtual localizacaoAtual = criaLocalizacaoAtual();
    Localizacao localizacao = criarLocalizacao();
    stackPushDinamicoL(stackLocalizacao, localizacao);
    Movimento movimento;

    unsigned int NLocalizacoes = 0;
    stackSizeDinamicoL(stackLocalizacao, &NLocalizacoes);

    printf("\n");
    while(!queueIsEmptyDinamico(queue) && NLocalizacoes <= 100)
    {
        queueDequeueDinamico(queue, &movimento);

        if(strncmp(movimento.nome, "MOVE", 4) == 0)
        {
            leMoveDinamico(movimento, localizacao, mapa, stackLocalizacao, stack, localizacaoAtual);
        }
        if(strncmp(movimento.nome, "LOOP", 4) == 0)
        {
            leLoopDinamico(movimento, localizacao, mapa, stackLocalizacao, stack, localizacaoAtual);
        }
        if(strncmp(movimento.nome, "JUMP", 4) == 0)
        {
            leJumpDinamico(movimento, localizacao, mapa, stackLocalizacao, stack, localizacaoAtual);
        }
         stackSizeDinamicoL(stackLocalizacao, &NLocalizacoes);
    }

    imprimePilhaLocalizacoesDinamica(stackLocalizacao, ultimaLocalizacao);
}
void leMoveDinamico(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackDL stack, PtStackDT stackT, LocalizacaoAtual localizacaoAtual)
{
    if( movimento.mover == 1 && localizacaoAtual->yAtual - 1 >= 0)
    {
        localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushDinamicoL(stack, localizacao);
        existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
    }

    else if(movimento.mover == 2 && localizacaoAtual->yAtual + 1 <= mapa->yMax)
    {
        localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushDinamicoL(stack, localizacao);
        existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
    }

    else if(movimento.mover == 3 && localizacaoAtual->xAtual + 1 <= mapa->xMax)
    {
        localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushDinamicoL(stack, localizacao);
        existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
    }

    else if(movimento.mover == 4 && localizacaoAtual->xAtual - 1 >= 0)
    {
        localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
        localizacao.x = localizacaoAtual->xAtual;
        localizacao.y = localizacaoAtual->yAtual;
        stackPushDinamicoL(stack, localizacao);
        existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
    }
    else
        printf("MOVE(%d) Invalido - Sai fora do limite do mapa\n", movimento.mover);
}
void leLoopDinamico(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackDL stack, PtStackDT stackT, LocalizacaoAtual localizacaoAtual)
{
    int numeroMovimento = movimento.numeroMoves;

    if( movimento.mover == 1 && localizacaoAtual->yAtual - 1 * movimento.numeroMoves >= 0)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushDinamicoL(stack, localizacao);
            existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
        }
    }

    else if(movimento.mover == 2 && localizacaoAtual->yAtual + 1 * movimento.numeroMoves <= mapa->yMax)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushDinamicoL(stack, localizacao);
            existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
        }
    }

    else if(movimento.mover == 3 && localizacaoAtual->xAtual + 1 * movimento.numeroMoves <= mapa->xMax)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushDinamicoL(stack, localizacao);
            existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
        }
    }

    else if(movimento.mover == 4 && localizacaoAtual->xAtual - 1 * movimento.numeroMoves >= 0)
    {
        while(numeroMovimento > 0)
        {
            localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
            numeroMovimento--;
            localizacao.x = localizacaoAtual->xAtual;
            localizacao.y = localizacaoAtual->yAtual;
            stackPushDinamicoL(stack, localizacao);
            existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
        }
    }
    else
        printf("LOOP(%d,%d) Invalido - Sai fora do limite do mapa\n", movimento.mover, movimento.numeroMoves);
}
void leJumpDinamico(Movimento movimento, Localizacao localizacao, Mapa mapa, PtStackDL stack, PtStackDT stackT, LocalizacaoAtual localizacaoAtual)
{
    if(movimento.x == localizacaoAtual->xAtual && movimento.y == localizacaoAtual->yAtual)
    {
        printf("já estou nessa posição não posso fazer JUMP\n");
    }

    else if(movimento.x == localizacaoAtual->xAtual && movimento.y != localizacaoAtual->yAtual && movimento.y <= mapa->yMax)
    {
        if(movimento.y > localizacaoAtual->yAtual)
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
    }

    else if(movimento.x != localizacaoAtual->xAtual && movimento.y == localizacaoAtual->yAtual && movimento.x <= mapa->xMax)
    {
        if(movimento.x > localizacaoAtual->xAtual)
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
    }

    else if(movimento.x != localizacaoAtual->xAtual && movimento.y != localizacaoAtual->yAtual && movimento.x <= mapa->xMax && movimento.y <= mapa->yMax)
    {
        if(movimento.x > localizacaoAtual->xAtual)
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->xAtual != movimento.x)
            {
                localizacaoAtual->xAtual = localizacaoAtual->xAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }

        if(movimento.y > localizacaoAtual->yAtual)
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual + 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
        else
        {
            while(localizacaoAtual->yAtual != movimento.y)
            {
                localizacaoAtual->yAtual = localizacaoAtual->yAtual - 1;
                localizacao.x = localizacaoAtual->xAtual;
                localizacao.y = localizacaoAtual->yAtual;
                stackPushDinamicoL(stack, localizacao);
                existeTesouroDinamico(localizacao, stackT, localizacaoAtual, mapa);
            }
        }
    }
    else
        printf("JUMP(%d,%d) Invalido - Sai fora do limite do mapa\n", movimento.x, movimento.y);
}
void existeTesouroDinamico(Localizacao localizacao, PtStackDT stackt, LocalizacaoAtual localizacaoAtual, Mapa mapa)
{
    Tesouro tesouro;
    PtStackDT stack2 = stackCreateDinamicoT();

    while(!stackIsEmptyDinamicoT(stackt))
    {
        stackPopDinamicoT(stackt, &tesouro);

        if(tesouro.x == localizacaoAtual->xAtual  && tesouro.y == localizacaoAtual->yAtual)
        {
            if(tesouro.encontrado == 1)
            {
                stackPushDinamicoT(stack2, tesouro);
                break;
            }
            else
            {
                mapa->numeroTesouros++;
                tesouro.encontrado = 1;
                stackPushDinamicoT(stack2, tesouro);
                break;
            }
        }
        else
        {
            stackPushDinamicoT(stack2, tesouro);
        }
    }

    while(!stackIsEmptyDinamicoT(stack2))
    {
        stackPopDinamicoT(stack2, &tesouro);
        stackPushDinamicoT(stackt, tesouro);
    }

    stackDestroyDinamicoT(&stack2);
}
void imprimePilhaLocalizacoesDinamica(PtStackDL stack, LocalizacaoAtual ultimaLocalizacao)
{
    Localizacao localizacao;
    PtStackDL stack2 = stackCreateDinamicoL();

    unsigned int pelem = 0;
    stackSizeDinamicoL(stack, &pelem);
    printf("SIZE = %d\n", pelem);

    while(pelem > 0)
    {
        stackPopDinamicoL(stack, &localizacao);
        stackPushDinamicoL(stack2, localizacao);
        stackSizeDinamicoL(stack, &pelem);
    }

    stackSizeDinamicoL(stack2, &pelem);

    while(pelem > 0)
    {
        stackPopDinamicoL(stack2, &localizacao);
        printf("Localizacoes: X = %d -  Y = %d -  N = %d\n", localizacao.y, localizacao.x, localizacao.n);
        stackPushDinamicoL(stack, localizacao);
        stackSizeDinamicoL(stack2, &pelem);
        if(pelem == 0)
        {
            ultimaLocalizacao->xAtual = localizacao.x;
            ultimaLocalizacao->yAtual = localizacao.y;
        }
    }

    stackDestroyDinamicoL(&stack2);
}
