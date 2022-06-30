#ifndef POKEBOLA_H
#define POKEBOLA_H

#include "pokemonCapturado.hpp"
#include <cstdlib>

class Pokebola
{
private:
    static int count;

protected:
    int id;
    pokemonCapturado *poke;

public:
    Pokebola();
    virtual ~Pokebola();

    int getId();
    pokemonCapturado *getPokemon();

    void guardarPokemon();
    Pokemon *liberarPokemon();
    virtual bool capturar(Pokemon &_poke);
};

#endif