#include <iostream>
#include "JuegoColoretto.h"

int main() {
    int numJugadores;
    std::cout << "Bienvenido a Coloretto!\n";

    while (true) {
        std::cout << "Ingrese el número de jugadores (3-5): ";
        std::cin >> numJugadores;
        
        try {
            JuegoColoretto juego(numJugadores);
            juego.iniciarJuego();
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << " Por favor, intente de nuevo.\n";
        }
    }

    return 0;
}