#ifndef MOVIMENTOS_H_INCLUDED
#define MOVIMENTOS_H_INCLUDED

typedef struct movimento
{
    char* nome;
    int mover, numeroMoves, numeroUndos, x, y;

} Movimento;


Movimento criaMovimento(void);

#endif // MOVIMENTOS_H_INCLUDED
