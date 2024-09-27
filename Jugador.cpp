#include "Jugador.h"
#include <iostream>
#include <algorithm>

Jugador::Jugador(std::string n) : nombre(n), cartasPuntuacion(0) {}

Jugador::~Jugador() {
    for (Carta* carta : cartasRecolectadasComodin) {
        delete carta;
    }
}

void Jugador::recolectarCarta(Carta* carta) {
    if (carta->tipo == "+2") {
        cartasPuntuacion++;
    } else if (carta->tipo == "Comodin") {
        std::string colorElegido;
        std::cout << "Ha recogido un comodín. Elija un color (Rojo, Verde, Azul, etc.): ";
        std::cin >> colorElegido;
        cartasRecolectadas[colorElegido]++;
    } else if (carta->tipo == "Camaleon") {
        cartasRecolectadas[carta->color]++;
    }
}

void Jugador::mostrarCartas() {
    std::cout << nombre << "'s cartas: ";
    for (auto& par : cartasRecolectadas) {
        std::cout << par.first << ": " << par.second << " ";
    }
    std::cout << "(+2: " << cartasPuntuacion << ") (Comodines: " << cartasRecolectadasComodin.size() << ") ";
    std::cout << std::endl;
}

int Jugador::calcularPuntuacion() {
    std::vector<int> cantidades;
    for (auto& par : cartasRecolectadas) {
        cantidades.push_back(par.second);
    }
    std::sort(cantidades.rbegin(), cantidades.rend());

    int puntos = 0;
    for (int i = 0; i < 3 && i < cantidades.size(); i++) {
        puntos += calcularPuntosPositivos(cantidades[i]);
    }
    for (int i = 3; i < cantidades.size(); i++) {
        puntos += calcularPuntosNegativos(cantidades[i]);
    }
    puntos += cartasPuntuacion * 2;
    return puntos;
}

int Jugador::calcularPuntosPositivos(int cantidad) {
    switch (cantidad) {
    case 1: return 1;
    case 2: return 3;
    case 3: return 6;
    case 4: return 10;
    case 5: return 15;
    case 6: return 21;
    default: return 28;
    }
}

int Jugador::calcularPuntosNegativos(int cantidad) {
    switch (cantidad) {
    case 1: return -2;
    case 2: return -3;
    case 3: return -6;
    case 4: return -10;
    case 5: return -15;
    case 6: return -21;
    default: return -28;
    }
}