#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "localizacaoAtual.h"

LocalizacaoAtual criaLocalizacaoAtual()
{
    LocalizacaoAtual localizacaoAtual;

    if((localizacaoAtual = (LocalizacaoAtual) malloc (sizeof (struct localizacaoAtual))) == NULL)
        return NULL;

    localizacaoAtual->xAtual = 0;
    localizacaoAtual->yAtual = 0;
    localizacaoAtual->n = 0;

    return localizacaoAtual;
}
