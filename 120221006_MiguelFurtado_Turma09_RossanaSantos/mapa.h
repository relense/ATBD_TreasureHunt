#ifndef MAPA_H_INCLUDED
#define MAPA_H_INCLUDED

struct mapa
{
    int xMax, yMax, numeroTesouros;

};

typedef struct mapa *Mapa;

Mapa criaMapa(void);

#endif // MAPA_H_INCLUDED
