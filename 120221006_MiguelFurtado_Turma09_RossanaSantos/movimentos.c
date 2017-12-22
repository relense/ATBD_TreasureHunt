#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movimentos.h"

Movimento criaMovimento(void)
{
    Movimento movimento;

    movimento.nome = (char*) calloc (20, sizeof(char));

    return movimento;
}


