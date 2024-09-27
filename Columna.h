#ifndef COLUMNA_H
#define COLUMNA_H

#include <vector>
#include <iostream>
#include "Carta.h"

class Columna {
public:
    std::vector<Carta*> cartas;
    bool tomada;  // Nueva propiedad para marcar si la columna ha sido tomada

    Columna();
    void agregarCarta(Carta* carta);
    bool estaLlena();
    void mostrarCartas();
};

#endif // COLUMNA_H