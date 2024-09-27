#include "Columna.h"
#include <algorithm>
#include <map>

// Constantes de colores ANSI
const std::map<std::string, std::string> coloresANSI = {
    {"Rojo", "\033[31m"},
    {"Verde", "\033[32m"},
    {"Azul", "\033[34m"},
    {"Amarillo", "\033[33m"},
    {"Marron", "\033[37m"},
    {"Rosa", "\033[35m"},
    {"Naranja", "\033[36m"},
    {"Reset", "\033[0m"}
};

Columna::Columna() : tomada(false) {}

void Columna::agregarCarta(Carta* carta) {
    if (cartas.size() < 3 && !tomada) {
        cartas.push_back(carta);
    } else if (tomada) {
        std::cout << "Esta columna ya ha sido tomada.\n";
    } else {
        std::cout << "Columna llena, no se puede agregar más cartas.\n";
    }
}

bool Columna::estaLlena() {
    return cartas.size() == 3;
}

void Columna::mostrarCartas() {
    if (tomada) {
        std::cout << "[Tomada] ";  // Marcar visualmente que está tomada
    } else {
        for (auto carta : cartas) {
            if (carta->tipo == "Camaleon") {
                std::cout << coloresANSI.at(carta->color) << carta->color << coloresANSI.at("Reset") << " ";
            } else {
                std::cout << carta->tipo << " ";
            }
        }
    }
    std::cout << std::endl;
}