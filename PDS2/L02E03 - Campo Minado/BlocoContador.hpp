#ifndef BLOCOCONTADOR
#define BLOCOCONTADOR

#include "Bloco.hpp"

class BlocoContador : public Bloco
{
public:
    BlocoContador(Coordenada _coord);

    virtual bool revelar(std::vector<std::vector<Bloco *>> &tabuleiro) override;
    virtual ~BlocoContador();
    void incrementarValor();
};

#endif