#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
public:
    std::string tipo; 
    std::string color;

    Carta(std::string t, std::string c = "");
    virtual ~Carta() = default;
};

#endif // CARTA_H