#ifndef BARJA_H
#define BARJA_H

#include <vector>
#include "Carta.h"

class Baraja {
public:
    std::vector<Carta*> cartas;

    Baraja();
    ~Baraja();
    void mezclarBaraja();
    Carta* sacarCarta();
};

#endif // BARJA_H