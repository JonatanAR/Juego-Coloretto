#include "JuegoColoretto.h"
#include <iostream>
#include <stdexcept>

// Constructor
JuegoColoretto::JuegoColoretto(int numJugadores) {
    if (numJugadores < 3 || numJugadores > 5) {
        throw std::invalid_argument("El número de jugadores debe estar entre 3 y 5.");
    }

    // Inicializar los punteros a baraja y tablero
    baraja = new Baraja();  
    tablero = new Tablero();  // Asegúrate de que el constructor de Tablero no requiera argumentos

    // Inicialización de jugadores
    for (int i = 0; i < numJugadores; i++) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << (i + 1) << ": ";
        std::cin >> nombre;
        jugadores.push_back(new Jugador(nombre));  // Crear jugadores dinámicamente
    }

    turnoActual = 0;
    ultimaRonda = false;
}

// Destructor
JuegoColoretto::~JuegoColoretto() {
    delete baraja;
    delete tablero;

    // Liberar memoria de los jugadores
    for (Jugador* jugador : jugadores) {
        delete jugador;
    }
}

// Método para iniciar el juego
void JuegoColoretto::iniciarJuego() {
    while (!baraja->cartas.empty() && !ultimaRonda) {
        std::cout << "\n=== Nueva ronda ===\n";
        bool rondaCompleta = false;

        // Mientras la ronda no esté completa
        while (!rondaCompleta) {
            for (Jugador* jugador : jugadores) {
                mostrarEstadoJuego();  // Mostrar el estado actual del juego
                jugarTurno(jugador);   // Jugar turno de cada jugador

                // Comprobar si la ronda está completa
                rondaCompleta = true;
                for (auto columna : tablero->columnas) {
                    if (!columna->tomada) {
                        rondaCompleta = false;
                        break;
                    }
                }

                if (rondaCompleta) break;  // Termina la ronda
            }
        }

        // Reiniciar las columnas
        for (auto columna : tablero->columnas) {
            columna->tomada = false;
        }

        // Verificar si se ha revelado la carta de última ronda
        if (ultimaRonda) {
            std::cout << "¡Se ha revelado la carta de finalización! El juego termina aquí.\n";
            break;
        }
    }

    std::cout << "El juego ha terminado.\n";
    mostrarResultados();
}

// Mostrar el estado actual del juego
void JuegoColoretto::mostrarEstadoJuego() {
    tablero->mostrarTablero();
}

// Jugar el turno de un jugador
void JuegoColoretto::jugarTurno(Jugador* jugador) {
    std::cout << jugador->nombre << "'s turno.\n";
    int opcion;

    // Comprobar si hay columnas completas
    bool hayColumnasCompletas = false;
    for (auto columna : tablero->columnas) {
        if (columna->cartas.size() == 3) {
            hayColumnasCompletas = true;
            break;
        }
    }

    if (hayColumnasCompletas) {
        // Si hay columnas completas, el jugador solo puede recoger una columna
        std::cout << "¡Hay columnas completas! Solo puedes recoger una columna.\n";
        int columna;
        do {
            std::cout << "Elige una columna para recoger (1-" << tablero->columnas.size() << "): ";
            std::cin >> columna;
        } while (columna < 1 || columna > tablero->columnas.size() || tablero->columnas[columna - 1]->cartas.empty());

        // Recolectar cartas de la columna seleccionada
        for (auto carta : tablero->columnas[columna - 1]->cartas) {
            jugador->recolectarCarta(carta);
        }

        tablero->columnas[columna - 1]->cartas.clear();  // Limpiar las cartas de la columna
        tablero->columnas[columna - 1]->tomada = true;   // Marcar la columna como tomada
    } else {
        // Opción para sacar carta o tomar una columna
        std::cout << "1. Sacar una carta\n2. Tomar una columna\nElige una opción: ";
        std::cin >> opcion;

        if (opcion == 1) {
            // Sacar una carta de la baraja
            Carta* carta = baraja->sacarCarta();
            if (!carta) return;

            // Mostrar la carta que el jugador ha sacado
            std::cout << "Has sacado una carta: " << carta->color << " (" << carta->tipo << ")\n";

            if (carta->tipo == "Ultima Ronda") {
                ultimaRonda = true;
                std::cout << "¡Se ha revelado la carta de última ronda!\n";
                return;
            }

            // Colocar la carta en una columna
            int columna;
            do {
                std::cout << "Elige una columna para colocar la carta (1-" << tablero->columnas.size() << "): ";
                std::cin >> columna;
            } while (columna < 1 || columna > tablero->columnas.size() || tablero->columnas[columna - 1]->estaLlena());

            tablero->columnas[columna - 1]->agregarCarta(carta);  // Agregar la carta a la columna seleccionada
        } else if (opcion == 2) {
            // Tomar una columna
            int columna;
            do {
                std::cout << "Elige una columna para recoger sus cartas (1-" << tablero->columnas.size() << "): ";
                std::cin >> columna;
            } while (columna < 1 || columna > tablero->columnas.size() || tablero->columnas[columna - 1]->cartas.empty());

            // Recolectar cartas de la columna
            for (auto carta : tablero->columnas[columna - 1]->cartas) {
                jugador->recolectarCarta(carta);
            }

            tablero->columnas[columna - 1]->cartas.clear();  // Limpiar la columna
            tablero->columnas[columna - 1]->tomada = true;   // Marcar la columna como tomada
        }
    }
}


// Mostrar los resultados finales del juego
void JuegoColoretto::mostrarResultados() {
    std::cout << "\n=== Resultados Finales ===\n";
    for (auto jugador : jugadores) {
        jugador->mostrarCartas();  // Mostrar las cartas del jugador
        std::cout << "Puntuación final: " << jugador->calcularPuntuacion() << " puntos.\n";
    }
}
