#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movimentos.h"
#include "gestorMovimento.h"
#include "tesouros.h"
#include "gestorTesouros.h"
#include "filaDinamica.h"
#include "filaEstatica.h"
#include "stackEstatico.h"
#include "stackDinamico.h"
#include "stackDinamicoTesouros.h"
#include "stackEstaticoTesouros.h"
#include "mapa.h"
#include "jogar.h"
#include "gestorLocalizacoes.h"

void jogarEstatico(void);
void jogarDinamico(void);
void imprimeFila(PtQueue queue);
void imprimePilha(PtStackET stack);
void imprimeFilaDinamica(PtQueueD queue);
void imprimePilhaDinamica(PtStackDT stack);
void imprimeLocalizacoes(PtStackEL stack);
void imprimeLocalizacoesDinamico(PtStackDL stack);
void guardaficheiro(FILE* file, PtStackEL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao, unsigned int NLocalizacoes, Mapa mapa);
void guardaficheiroDinamico(FILE* file, PtStackDL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao, unsigned int NLocalizacoes, Mapa mapa);

int main()
{
    int escolha;
    printf("Estatico: 1 | Dinamico: 2\n");
    scanf("%d", &escolha);

    if(escolha == 1) jogarEstatico();

    else if(escolha == 2) jogarDinamico();

    else printf("Escolha inválida\n");

    return 0;
}

void jogarEstatico(void)
{
    FILE *movimentos;
    movimentos = fopen("movimentos.txt", "r");
    if(movimentos == NULL)perror("movimentos.txt");

    FILE *tesouros;
    tesouros = fopen("mapa.txt", "r");
    if(tesouros == NULL)perror("mapa.txt");

    FILE* resultados;
    resultados = fopen("resultados.txt", "w+");
    if(resultados == NULL)perror("resultados.txt");

    PtQueue queueMovimentos = queueCreateEstatico();
    PtStackET stackTesouros = stackCreateEstaticoT();
    PtStackEL stackLocalizacao = stackCreateEstaticoL();

    unsigned int pelem = 0;
    unsigned int NLocalizacoes = 0;

    Movimento movimento = criaMovimento();
    Tesouro tesouro = criaTesouro();
    Mapa mapa = criaMapa();
    LocalizacaoAtual ultimaLocalizacao = criaLocalizacaoAtual();

    leMovimentosFicheiro(queueMovimentos, movimento, movimentos);
    leTesourosFicheiroEstatico(stackTesouros, tesouro, tesouros, mapa);

    printf("Tamnho do mapa = %d %d\n", mapa->xMax + 1, mapa->yMax + 1);

    printf("\nMovimentos\n");
    imprimeFila(queueMovimentos);

    queueSizeEstatico(queueMovimentos, &pelem);
    printf("Numero de Movimentos = %u\n", pelem);

    printf("\nTesouros\n");
    imprimePilha(stackTesouros);
    stackSizeEstaticoT(stackTesouros, &pelem);
    printf("Numero de Tesouros = %d\n", pelem);

    jogaEstatico(stackTesouros, queueMovimentos, mapa, stackLocalizacao, ultimaLocalizacao);

    printf("\nTesouros\n");
    imprimePilha(stackTesouros);
    stackSizeEstaticoT(stackTesouros, &pelem);
    printf("Numero de Tesouros = %d\n", pelem);
    printf("Numero de Tesouros Encontrados: %d\n", mapa->numeroTesouros);

    stackSizeEstaticoL(stackLocalizacao, &NLocalizacoes);
    printf("\nNumero Localizacoes: %d\n", NLocalizacoes);

    printf("Ultima Localizacao: X = %d, Y = %d\n", ultimaLocalizacao->xAtual, ultimaLocalizacao->yAtual);

    contarLocalizacoes(stackLocalizacao);

    imprimeLocalizacoes(stackLocalizacao);

    guardaficheiro(resultados, stackLocalizacao, ultimaLocalizacao, NLocalizacoes, mapa);

    fclose(resultados);

    queueDestroyEstatico(&queueMovimentos);
    stackDestroyEstaticoT(&stackTesouros);
    stackDestroyEstaticoL(&stackLocalizacao);
}

void jogarDinamico(void)
{
    FILE *movimentos;
    movimentos = fopen("movimentos.txt", "r");
    if(movimentos == NULL)perror("movimentos.txt");

    FILE *tesouros;
    tesouros = fopen("mapa.txt", "r");
    if(tesouros == NULL) perror("mapa.txt");

    FILE* resultados;
    resultados = fopen("resultados.txt", "w+");
    if(resultados == NULL)perror("resultados.txt");

    PtQueueD queueMovimentos = queueCreateDinamico();
    PtStackDT stackTesouros = stackCreateDinamicoT();
    PtStackDL stackLocalizacao = stackCreateDinamicoL();

    unsigned int pelem = 0;
    unsigned int NLocalizacoes = 0;

    Movimento movimento = criaMovimento();
    Tesouro tesouro = criaTesouro();
    Mapa mapa = criaMapa();
    LocalizacaoAtual ultimaLocalizacao = criaLocalizacaoAtual();

    leMovimentosFicheiroDinamico(queueMovimentos, movimento, movimentos);
    leTesourosFicheiroDinamico(stackTesouros, tesouro, tesouros, mapa);

    printf("Tamnho do mapa = %d %d\n", mapa->xMax, mapa->yMax);

    printf("\nMovimentos\n");
    imprimeFilaDinamica(queueMovimentos);

    queueSizeDinamico(queueMovimentos, &pelem);
    printf("Numero de Movimentos = %u\n", pelem);

    printf("\nTesouros\n");
    imprimePilhaDinamica(stackTesouros);
    stackSizeDinamicoT(stackTesouros, &pelem);
    printf("Numero de Tesouros = %d\n", pelem);

    jogaDinamico(stackTesouros, queueMovimentos, mapa, stackLocalizacao, ultimaLocalizacao);

    printf("\nTesouros\n");
    imprimePilhaDinamica(stackTesouros);
    stackSizeDinamicoT(stackTesouros, &pelem);
    printf("Numero de Tesouros = %d\n", pelem);
    printf("Numero de Tesouros Encontrados: %d\n", mapa->numeroTesouros);

    stackSizeDinamicoL(stackLocalizacao, &NLocalizacoes);
    printf("\nNumero Localizacoes: %d\n", NLocalizacoes);

    printf("Ultima Localizacao: X = %d, Y = %d\n", ultimaLocalizacao->xAtual, ultimaLocalizacao->yAtual);

    contarLocalizacoesDinamico(stackLocalizacao);

    imprimeLocalizacoesDinamico(stackLocalizacao);

    guardaficheiroDinamico(resultados, stackLocalizacao, ultimaLocalizacao, NLocalizacoes, mapa);

    fclose(resultados);

    queueDestroyDinamico(&queueMovimentos);
    stackDestroyDinamicoT(&stackTesouros);
    stackDestroyDinamicoL(&stackLocalizacao);
}

void imprimeFila(PtQueue queue)
{
    Movimento movimento = criaMovimento();

    PtQueue pilha2 = queueCreateEstatico();

    while(!queueIsEmptyEstatico(queue))
    {
        queueDequeueEstatico(queue, &movimento);
        printf("%s\n", movimento.nome);
        queueEnqueueEstatico(pilha2, movimento);
    }

    while(!queueIsEmptyEstatico(pilha2))
    {
        queueDequeueEstatico(pilha2, &movimento);
        queueEnqueueEstatico(queue, movimento);
    }
}
void imprimePilha(PtStackET stack)
{
    Tesouro tesouro;

    PtStackET stack2 = stackCreateEstaticoT();

    while(!stackIsEmptyEstaticoT(stack))
    {
        stackPopEstaticoT(stack, &tesouro);
        stackPushEstaticoT(stack2, tesouro);
    }

    while(!stackIsEmptyEstaticoT(stack2))
    {
        stackPopEstaticoT(stack2, &tesouro);
        printf("X = %d -  Y = %d -  N = %d\n", tesouro.y, tesouro.x, tesouro.encontrado);
        stackPushEstaticoT(stack, tesouro);
    }
}

void imprimeFilaDinamica(PtQueueD queue)
{
    Movimento movimento = criaMovimento();

    PtQueueD pilha2 = queueCreateDinamico();

    while(!queueIsEmptyDinamico(queue))
    {
        queueDequeueDinamico(queue, &movimento);
        printf("%s\n", movimento.nome);
        queueEnqueueDinamico(pilha2, movimento);
    }

    while(!queueIsEmptyDinamico(pilha2))
    {
        queueDequeueDinamico(pilha2, &movimento);
        queueEnqueueDinamico(queue, movimento);
    }

}
void imprimePilhaDinamica(PtStackDT stack)
{
    Tesouro tesouro = criaTesouro();

    PtStackDT stack2 = stackCreateDinamicoT();

    while(!stackIsEmptyDinamicoT(stack))
    {
        stackPopDinamicoT(stack, &tesouro);
        stackPushDinamicoT(stack2, tesouro);
    }

    while(!stackIsEmptyDinamicoT(stack2))
    {
        stackPopDinamicoT(stack2, &tesouro);
        printf("X = %d -  Y = %d -  N = %d\n", tesouro.y, tesouro.x, tesouro.encontrado);
        stackPushDinamicoT(stack, tesouro);
    }
}

void imprimeLocalizacoes(PtStackEL stack)
{
    Localizacao localizacao;
    PtStackEL aux = stackCreateEstaticoL();

    while(!stackIsEmptyEstaticoL(stack))
    {
        stackPopEstaticoL(stack, &localizacao);
        stackPushEstaticoL(aux, localizacao);
    }

    while(!stackIsEmptyEstaticoL(aux))
    {
        stackPopEstaticoL(aux, &localizacao);
        printf("LOCALIZACAO: x = %d, y = %d, n = %d\n", localizacao.y, localizacao.x, localizacao.n);
        stackPushEstaticoL(stack, localizacao);
    }
}

void imprimeLocalizacoesDinamico(PtStackDL stack)
{
    Localizacao localizacao;
    PtStackDL aux = stackCreateDinamicoL();

    while(!stackIsEmptyDinamicoL(stack))
    {
        stackPopDinamicoL(stack, &localizacao);
        stackPushDinamicoL(aux, localizacao);
    }

    while(!stackIsEmptyDinamicoL(aux))
    {
        stackPopDinamicoL(aux, &localizacao);
        printf("LOCALIZACAO: x = %d, y = %d, n = %d\n", localizacao.y, localizacao.x, localizacao.n);
        stackPushDinamicoL(stack, localizacao);
    }
}

void guardaficheiro(FILE* file, PtStackEL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao, unsigned int NLocalizacoes, Mapa mapa)
{
    fprintf(file, "(%d,%d)\n", ultimaLocalizacao->xAtual + 1, ultimaLocalizacao->yAtual + 1);
    fprintf(file, "%d\n", NLocalizacoes);
    fprintf(file, "%d\n", mapa->numeroTesouros);

    Localizacao local;

    while(!stackIsEmptyEstaticoL(stackLocalizacao))
    {
        stackPopEstaticoL(stackLocalizacao, &local);
        fprintf(file,"(%d, %d, %d)\n", local.y, local.x, local.n);
    }

}

void guardaficheiroDinamico(FILE* file, PtStackDL stackLocalizacao, LocalizacaoAtual ultimaLocalizacao, unsigned int NLocalizacoes, Mapa mapa)
{
    fprintf(file, "(%d,%d)\n", ultimaLocalizacao->xAtual + 1, ultimaLocalizacao->yAtual + 1);
    fprintf(file, "%d\n", NLocalizacoes);
    fprintf(file, "%d\n", mapa->numeroTesouros);

    Localizacao local;

    while(!stackIsEmptyDinamicoL(stackLocalizacao))
    {
        stackPopDinamicoL(stackLocalizacao, &local);
        fprintf(file,"(%d, %d, %d)\n", local.y, local.x, local.n);
    }

}
