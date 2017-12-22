#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tesouros.h"
#include "stackEstaticoTesouros.h"
#include "stackDinamicoTesouros.h"
#include "mapa.h"

void leTesourosFicheiroEstatico(PtStackET stack, Tesouro tesouro, FILE* tesouros, Mapa mapa)
{
    char le[10];
    int valor, valor2;

    fscanf(tesouros, "%d %d", &valor, &valor2);

    mapa->xMax = valor;
    mapa->yMax = valor2;
    mapa->xMax = mapa->xMax - 1;
    mapa->yMax = mapa->yMax - 1;

    if(mapa->xMax < 5 || mapa->xMax > 10)mapa->xMax = 5;
    if(mapa->yMax < 5 || mapa->yMax > 10)mapa->yMax = 5;

    while (fgets(le, sizeof le, tesouros) != NULL)
    {
        if(fscanf(tesouros,"%s", le) != EOF)
        {
            tesouro.y = atoi(&le[1]);
            tesouro.x = atoi(&le[3]);
            stackPushEstaticoT(stack, tesouro);
        }
    }

    fclose(tesouros);
}

void leTesourosFicheiroDinamico(PtStackDT stack, Tesouro tesouro, FILE* tesouros, Mapa mapa)
{
    char le[10];
    int valor, valor2;

    fscanf(tesouros, "%d %d", &valor, &valor2);

    mapa->xMax = valor;
    mapa->yMax = valor2;
    mapa->xMax = mapa->xMax - 1;
    mapa->yMax = mapa->yMax - 1;

    if(mapa->xMax < 5 || mapa->xMax > 10)mapa->xMax = 5;
    if(mapa->yMax < 5 || mapa->yMax > 10)mapa->yMax = 5;

    while (fgets(le, sizeof le, tesouros) != NULL)
    {
        if(fscanf(tesouros,"%s", le) != EOF)
        {
            tesouro.y = atoi(&le[1]);
            tesouro.x = atoi(&le[3]);
            stackPushDinamicoT(stack, tesouro);
        }
    }

    fclose(tesouros);
}
