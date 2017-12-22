#ifndef LOCALIZACAOATUAL_H_INCLUDED
#define LOCALIZACAOATUAL_H_INCLUDED

struct localizacaoAtual
{
    int xAtual, yAtual, n;

};

typedef struct localizacaoAtual *LocalizacaoAtual;

LocalizacaoAtual criaLocalizacaoAtual();

#endif // LOCALIZACAOATUAL_H_INCLUDED
