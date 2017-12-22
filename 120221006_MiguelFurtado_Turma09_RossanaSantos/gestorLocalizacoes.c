#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "localizacao.h"
#include "stackEstaticoLocalizacao.h"
#include "stackDinamicoLocalizacao.h"
#include "gestorLocalizacoes.h"
#include "localizacaoAtual.h"

void contarLocalizacoes(PtStackEL stackL)
{
    PtStackEL aux = stackCreateEstaticoL();
    Localizacao localizacao;

    unsigned int nElem;
    stackSizeEstaticoL(stackL, &nElem);

    while(nElem > 0)
    {
        while(!stackIsEmptyEstaticoL(stackL))
        {
            stackPopEstaticoL(stackL, &localizacao);

            if(localizacao.n == 0)
            {
                contador(stackL, localizacao);
            }

            stackPushEstaticoL(aux, localizacao);
        }
        nElem--;
    }

    while(!stackIsEmptyEstaticoL(aux))
    {
        stackPopEstaticoL(aux, &localizacao);

        if(localizacao.n > 1)
        {
            stackPushEstaticoL(stackL, localizacao);
        }
    }

    stackDestroyEstaticoL(&aux);

    confirm(stackL);
}

void contador(PtStackEL stack, Localizacao localizacao)
{
    PtStackEL stackAux = stackCreateEstaticoL();
    LocalizacaoAtual localAtual = criaLocalizacaoAtual();

    localAtual->n = 0;
    localizacao.n = localAtual->n;

    localAtual->xAtual = localizacao.x;
    localAtual->yAtual = localizacao.y;
    stackPushEstaticoL(stack, localizacao);

    while(!stackIsEmptyEstaticoL(stack))
    {
        stackPopEstaticoL(stack, &localizacao);

        if(localizacao.x == localAtual->xAtual && localizacao.y == localAtual->yAtual)
        {
            localAtual->n++;
        }

        stackPushEstaticoL(stackAux, localizacao);
    }

    while(!stackIsEmptyEstaticoL(stackAux))
    {
        stackPopEstaticoL(stackAux, &localizacao);

        if(localizacao.x == localAtual->xAtual && localizacao.y == localAtual->yAtual)
        {
            localizacao.n = localAtual->n;
        }

        stackPushEstaticoL(stack, localizacao);
    }

    stackDestroyEstaticoL(&stackAux);
}

void confirm(PtStackEL stack)
{
    PtStackEL aux = stackCreateEstaticoL();
    PtStackEL aux2 = stackCreateEstaticoL();

    LocalizacaoAtual localAtual = criaLocalizacaoAtual();
    Localizacao localizacao;

    unsigned int nElem;
    stackSizeEstaticoL(stack, &nElem);
    printf("SIZE = %d\n", nElem);


    while(nElem > 0)
    {
        stackPopEstaticoL(stack, &localizacao);
        stackPushEstaticoL(aux2, localizacao);
        nElem--;

        localAtual->xAtual = localizacao.x;
        localAtual->yAtual = localizacao.y;

        while(!stackIsEmptyEstaticoL(stack))
        {
            stackPopEstaticoL(stack, &localizacao);

            if(localizacao.x == localAtual->xAtual && localizacao.y == localAtual->yAtual)
            {
                nElem--;
            }
            else
            {
                stackPushEstaticoL(aux, localizacao);
            }
        }

        while(!stackIsEmptyEstaticoL(aux))
        {
            stackPopEstaticoL(aux, &localizacao);
            stackPushEstaticoL(stack, localizacao);
        }

    }

    while(!stackIsEmptyEstaticoL(aux2))
    {
        stackPopEstaticoL(aux2, &localizacao);
        stackPushEstaticoL(stack, localizacao);

    }

    stackSizeEstaticoL(stack, &nElem);
    printf("\nSIZE = %d\n", nElem);

    stackDestroyEstaticoL(&aux);
    stackDestroyEstaticoL(&aux2);
}


void contarLocalizacoesDinamico(PtStackDL stackL)
{
    PtStackDL aux = stackCreateDinamicoL();
    Localizacao localizacao;

    unsigned int nElem;
    stackSizeDinamicoL(stackL, &nElem);

    while(nElem > 0)
    {
        while(!stackIsEmptyDinamicoL(stackL))
        {
            stackPopDinamicoL(stackL, &localizacao);

            if(localizacao.n == 0)
            {
                contadorDinamico(stackL, localizacao);
            }

            stackPushDinamicoL(aux, localizacao);
        }
        nElem--;
    }

    while(!stackIsEmptyDinamicoL(aux))
    {
        stackPopDinamicoL(aux, &localizacao);

        if(localizacao.n > 1)
        {
            stackPushDinamicoL(stackL, localizacao);
        }
    }

    confirmDinamico(stackL);

    stackDestroyDinamicoL(&aux);
}
void contadorDinamico(PtStackDL stack, Localizacao localizacao)
{
    PtStackDL stackAux = stackCreateDinamicoL();
    LocalizacaoAtual localAtual = criaLocalizacaoAtual();

    localAtual->n = 0;
    localizacao.n = localAtual->n;

    localAtual->xAtual = localizacao.x;
    localAtual->yAtual = localizacao.y;
    stackPushDinamicoL(stack, localizacao);

    while(!stackIsEmptyDinamicoL(stack))
    {
        stackPopDinamicoL(stack, &localizacao);

        if(localizacao.x == localAtual->xAtual && localizacao.y == localAtual->yAtual)
        {
            localAtual->n++;
        }

        stackPushDinamicoL(stackAux, localizacao);
    }

    while(!stackIsEmptyDinamicoL(stackAux))
    {
        stackPopDinamicoL(stackAux, &localizacao);

        if(localizacao.x == localAtual->xAtual && localizacao.y == localAtual->yAtual)
        {
            localizacao.n = localAtual->n;
        }

        stackPushDinamicoL(stack, localizacao);
    }

    stackDestroyDinamicoL(&stackAux);
}
void confirmDinamico(PtStackDL stack)
{
    PtStackDL aux = stackCreateDinamicoL();
    PtStackDL aux2 = stackCreateDinamicoL();
    LocalizacaoAtual localAtual = criaLocalizacaoAtual();
    Localizacao localizacao;

    unsigned int nElem;
    stackSizeDinamicoL(stack, &nElem);
    printf("SIZE = %d\n", nElem);

    while(nElem > 0)
    {
        stackPopDinamicoL(stack, &localizacao);
        stackPushDinamicoL(aux2, localizacao);
        nElem--;

        localAtual->xAtual = localizacao.x;
        localAtual->yAtual = localizacao.y;

        while(!stackIsEmptyDinamicoL(stack))
        {
            stackPopDinamicoL(stack, &localizacao);

            if(localizacao.x == localAtual->xAtual && localizacao.y == localAtual->yAtual)
            {
                nElem--;
            }
            else stackPushDinamicoL(aux, localizacao);
        }

        while(!stackIsEmptyDinamicoL(aux))
        {
            stackPopDinamicoL(aux, &localizacao);
            stackPushDinamicoL(stack, localizacao);
        }
    }

     while(!stackIsEmptyDinamicoL(aux2))
    {
        stackPopDinamicoL(aux2, &localizacao);
        stackPushDinamicoL(stack, localizacao);

    }

    stackSizeDinamicoL(stack, &nElem);
    printf("\nSIZE = %d\n", nElem);

    stackDestroyDinamicoL(&aux);
    stackDestroyDinamicoL(&aux2);
}
