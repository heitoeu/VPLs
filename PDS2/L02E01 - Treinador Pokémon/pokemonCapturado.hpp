#ifndef POKEMONCAPTURADO_H
#define POKEMONCAPTURADO_H

#include "pokemon.hpp"

class pokemonCapturado : public Pokemon
{
private:
    bool evoluido;
    bool dormindo;

public:
    pokemonCapturado(Pokemon &_pok);
    void set_dormindo(bool valor);
    bool get_evoluido();
    void evoluir(double taxaPoder);
};

#endif