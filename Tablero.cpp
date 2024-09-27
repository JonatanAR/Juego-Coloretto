#include "Tablero.h"
#include <iostream>

Tablero::Tablero() {
    for (int i = 0; i < 3; i++) {
        columnas.push_back(new Columna());
    }
}

Tablero::~Tablero() {
    for (Columna* columna : columnas) {
        delete columna;
    }
}

void Tablero::mostrarTablero() {
    for (int i = 0; i < columnas.size(); i++) {
        std::cout << "Columna " << i + 1 << ": ";
        columnas[i]->mostrarCartas();
    }
}

void Tablero::agregarColumna(Columna* columna) {
    if (columnas.size() < 3) {
        columnas.push_back(columna);
    } else {
        std::cout << "El tablero está lleno.\n";
    }
}

bool Tablero::todasTomadas() {
    for (auto columna : columnas) {
        if (!columna->tomada) {
            return false;
        }
    }
    return true;
}