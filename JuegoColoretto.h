#ifndef JUEGOCOLORETTO_H
#define JUEGOCOLORETTO_H

#include <vector>
#include <string>
#include "Baraja.h"
#include "Tablero.h"
#include "Jugador.h"

class JuegoColoretto {
public:
    // Constructor y destructor
    JuegoColoretto(int numJugadores);
    ~JuegoColoretto();

    // Métodos principales del juego
    void iniciarJuego();
    void mostrarEstadoJuego();
    void jugarTurno(Jugador* jugador);
    void mostrarResultados();

private:
    Baraja* baraja;        // Puntero a la baraja de cartas
    Tablero* tablero;      // Puntero al tablero de juego
    std::vector<Jugador*> jugadores;  // Vector de jugadores
    int turnoActual;       // Variable que guarda el turno actual
    bool ultimaRonda;      // Booleano que indica si se ha revelado la carta de última ronda
};

#endif
