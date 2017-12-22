#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapa.h"

Mapa criaMapa(void)
{
    Mapa mapa;

    if((mapa = (Mapa) malloc (sizeof (struct mapa))) == NULL)
        return NULL;

    mapa->xMax = 5;
    mapa->yMax = 5;
    mapa->numeroTesouros = 0;

    return mapa;
}

