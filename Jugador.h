#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include <map>
#include <vector>
#include "Carta.h"

class Jugador {
public:
    std::string nombre;
    std::map<std::string, int> cartasRecolectadas;
    int cartasPuntuacion;
    std::vector<Carta*> cartasRecolectadasComodin;

    Jugador(std::string n);
    ~Jugador();
    void recolectarCarta(Carta* carta);
    void mostrarCartas();
    int calcularPuntuacion();
private:
    int calcularPuntosPositivos(int cantidad);
    int calcularPuntosNegativos(int cantidad);
};

#endif // JUGADOR_H