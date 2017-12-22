#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movimentos.h"
#include "stackEstatico.h"
#include "gestorMovimento.h"
#include "filaEstatica.h"
#include "stackDinamico.h"
#include "filaDinamica.h"

void leMovimentosFicheiro(PtQueue queue, Movimento movimento, FILE* movimentos)
{
    PtStackE stackGuarda = stackCreateEstatico();
    PtStackE stackRedo = stackCreateEstatico();
    PtStackE stackOrdena = stackCreateEstatico();

    char leNome[20];

    while(fscanf(movimentos,"%s\n", leNome) != EOF)
    {
        movimento.nome = leNome;
        decompoemMoveEstatico(stackGuarda, stackRedo, movimento);
    }

    fclose(movimentos);
    stackDestroyEstatico(&stackRedo);
    ordenaPilha(stackGuarda, stackOrdena);
    passarFila(stackOrdena, queue);

}

void decompoemMoveEstatico(StackE guarda, StackE redo, Movimento movimento)
{
    if(strncmp(movimento.nome, "MOVE", 4) == 0)
    {
        movimento.mover = atoi(&movimento.nome[5]);
        movimento.nome = "MOVE";

        stackPushEstatico(guarda, movimento);
    }

    if(strncmp(movimento.nome, "LOOP", 4) == 0)
    {
        movimento.mover = atoi(&movimento.nome[5]);
        movimento.numeroMoves = atoi(&movimento.nome[7]);
        movimento.nome = "LOOP";

        stackPushEstatico(guarda, movimento);
    }

    if(strncmp(movimento.nome, "JUMP", 4) == 0)
    {
        movimento.x = atoi(&movimento.nome[5]);
        movimento.y = atoi(&movimento.nome[7]);
        movimento.nome = "JUMP";

        stackPushEstatico(guarda, movimento);
    }

    if(strncmp(movimento.nome, "UNDO", 4) == 0)
    {
        int aux;
        int numeroUndos;
        int count;

        movimento.numeroUndos = atoi(&movimento.nome[5]);
        movimento.nome = "UNDO";

        aux = movimento.numeroUndos;
        numeroUndos = movimento.numeroUndos;
        count = aux;

        stackPopEstatico(guarda, &movimento);
        count--;

        while(count > 0)
        {
            if(strncmp(movimento.nome, "JUMP", 4) == 0)
            {
                while(count < numeroUndos)
                {
                    stackPushEstatico(guarda, movimento);

                    if(count < numeroUndos)
                    {
                        stackPopEstatico(redo, &movimento);
                        count++;
                    }
                }
                break;
            }
            else
            {
                stackPushEstatico(redo, movimento);
                stackPopEstatico(guarda, &movimento);
                count--;
            }
        }

        if(strncmp(movimento.nome, "JUMP", 4) == 0 && count == 0)
        {
            while(count < numeroUndos)
            {
                stackPushEstatico(guarda, movimento);

                if(count < numeroUndos)
                {
                    stackPopEstatico(redo, &movimento);
                    count++;
                }
            }
        }
    }
}

void ordenaPilha(StackE guarda, StackE ordenado)
{
    TElem elemento;

    while(!stackIsEmptyEstatico(guarda))
    {
        stackPopEstatico(guarda, &elemento);
        stackPushEstatico(ordenado, elemento);
    }

    stackDestroyEstatico(&guarda);
}

void passarFila(StackE stackEstatico, PtQueue queue)
{
    Movimento movimento = criaMovimento();

    while(!stackIsEmptyEstatico(stackEstatico))
    {
        stackPopEstatico(stackEstatico, &movimento);
        queueEnqueueEstatico(queue, movimento);
    }

    stackDestroyEstatico(&stackEstatico);
}

/*
*INICIO DAS FUNÇÕES COM USO DE PILHAS E FILAS DINAMICAS
*/

void leMovimentosFicheiroDinamico(PtQueueD queue, Movimento movimento, FILE* movimentos)
{
    PtStackD guarda = stackCreateDinamico();
    PtStackD redo = stackCreateDinamico();
    PtStackD ordenada = stackCreateDinamico();

    char leNome[20];

    while(fscanf(movimentos,"%s\n", leNome) != EOF)
    {
        movimento.nome = leNome;
        decompoemMoveDinamico(guarda, redo, movimento);
    }

    fclose(movimentos);
    stackDestroyDinamico(&redo);
    ordenaPilhaDinamico(guarda, ordenada);
    passarFilaDinamico(ordenada, queue);
}

void decompoemMoveDinamico(StackD guarda, StackD redo, Movimento movimento)
{
    if(strncmp(movimento.nome, "MOVE", 4) == 0)
    {
        movimento.mover = atoi(&movimento.nome[5]);
        movimento.nome = "MOVE";

        stackPushDinamico(guarda, movimento);
    }

    if(strncmp(movimento.nome, "LOOP", 4) == 0)
    {
        movimento.mover = atoi(&movimento.nome[5]);
        movimento.numeroMoves = atoi(&movimento.nome[7]);
        movimento.nome = "LOOP";

        stackPushDinamico(guarda, movimento);
    }

    if(strncmp(movimento.nome, "JUMP", 4) == 0)
    {
        movimento.x = atoi(&movimento.nome[5]);
        movimento.y = atoi(&movimento.nome[7]);
        movimento.nome = "JUMP";

        stackPushDinamico(guarda, movimento);
    }

    if(strncmp(movimento.nome, "UNDO", 4) == 0)
    {
        int aux;
        int numeroUndos;
        int count;

        movimento.numeroUndos = atoi(&movimento.nome[5]);
        movimento.nome = "UNDO";

        aux = movimento.numeroUndos;
        numeroUndos = movimento.numeroUndos;
        count = aux;

        stackPopDinamico(guarda, &movimento);
        count--;

        while(count > 0)
        {
            if(strncmp(movimento.nome, "JUMP", 4) == 0)
            {
                while(count < numeroUndos)
                {
                    stackPushDinamico(guarda, movimento);

                    if(count < numeroUndos)
                    {
                        stackPopDinamico(redo, &movimento);
                        count++;
                    }
                }
                break;
            }
            else
            {
                stackPushDinamico(redo, movimento);
                stackPopDinamico(guarda, &movimento);
                count--;
            }
        }

        if(strncmp(movimento.nome, "JUMP", 4) == 0 && count == 0)
        {
            while(count < numeroUndos)
            {
                stackPushDinamico(guarda, movimento);

                if(count < numeroUndos)
                {
                    stackPopDinamico(redo, &movimento);
                    count++;
                }
            }
        }
    }
}

void ordenaPilhaDinamico(StackD guarda, StackD ordenada)
{
    TElem elemento;

    while(!stackIsEmptyDinamico(guarda))
    {
        stackPopDinamico(guarda, &elemento);
        stackPushDinamico(ordenada, elemento);
    }

    stackDestroyDinamico(&guarda);
}

void passarFilaDinamico(StackD ordenada, PtQueueD queueD)
{
    Movimento elemento;

    while(!stackIsEmptyDinamico(ordenada))
    {
        stackPopDinamico(ordenada, &elemento);
        queueEnqueueDinamico(queueD, elemento);
    }

    stackDestroyDinamico(&ordenada);
}
