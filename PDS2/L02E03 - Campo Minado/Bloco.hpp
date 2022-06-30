#ifndef BLOCO_H
#define BLOCO_H

#include <vector>
#include <string>
#include "Coordenada.hpp"

class Bloco
{
protected:
    Coordenada coord;
    bool revelado;
    int valor;

public:
    Bloco(Coordenada _coord);
    Bloco() {}

    virtual ~Bloco();
    virtual bool revelar(std::vector<std::vector<Bloco *>> &tabuleiro);
    std::string getSimbolo();
    bool ehRevelado();

    void setRevelar();
    int getValor();
    Coordenada getcoord();
};

#endif