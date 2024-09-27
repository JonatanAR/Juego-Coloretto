#ifndef TABLERO_H
#define TABLERO_H

#include <vector>
#include "Columna.h"

class Tablero {
public:
    std::vector<Columna*> columnas;

    Tablero();
    ~Tablero();
    void mostrarTablero();
    void agregarColumna(Columna* columna);
    bool todasTomadas();
};

#endif // TABLERO_H