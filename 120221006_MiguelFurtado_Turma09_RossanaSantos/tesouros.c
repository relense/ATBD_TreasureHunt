#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tesouros.h"

Tesouro criaTesouro(void)
{
    Tesouro tesouro;

   tesouro.x = 0;
   tesouro.y = 0;
   tesouro.encontrado = 0;

    return tesouro;
}
