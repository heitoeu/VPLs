#ifndef BLOCOMINA_H
#define BLOCOMINA_H

#include "BlocoContador.hpp"

class BlocoMina : public Bloco
{
public:
    BlocoMina(std::vector<std::vector<Bloco *>> &tabuleiro, Coordenada _coord);
    virtual ~BlocoMina();
    virtual bool revelar(std::vector<std::vector<Bloco *>> &tabuleiro) override;
};

#endif