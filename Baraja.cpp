#include "Baraja.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

const std::vector<std::string> COLORES = { "Rojo", "Verde", "Azul", "Amarillo", "Marron", "Rosa", "Naranja" };
const int NUM_CARTAS_COLOR = 9; 
const int NUM_CARTAS_COMODIN = 3;
const int NUM_CARTAS_PUNTUACION = 10; 

Baraja::Baraja() {
    for (auto& color : COLORES) {
        for (int i = 0; i < NUM_CARTAS_COLOR; i++) {
            cartas.push_back(new Carta("Camaleon", color));
        }
    }
    for (int i = 0; i < NUM_CARTAS_COMODIN; i++) {
        cartas.push_back(new Carta("Comodin"));
    }
    for (int i = 0; i < NUM_CARTAS_PUNTUACION; i++) {
        cartas.push_back(new Carta("+2"));
    }
    cartas.push_back(new Carta("Ultima Ronda"));

    mezclarBaraja();
}

Baraja::~Baraja() {
    for (Carta* carta : cartas) {
        delete carta;
    }
}

void Baraja::mezclarBaraja() {
    std::srand(std::time(0));
    std::random_shuffle(cartas.begin(), cartas.end());
}

Carta* Baraja::sacarCarta() {
    if (cartas.empty()) return nullptr;
    Carta* carta = cartas.back();
    cartas.pop_back();
    return carta;
}