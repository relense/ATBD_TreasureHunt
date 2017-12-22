#include <stdio.h>
#include <stdlib.h>
#include "localizacao.h"

Localizacao criarLocalizacao(void)
{
    Localizacao localizacao;

    localizacao.x = 0;
    localizacao.y = 0;
    localizacao.n = 0;

    return localizacao;
}
