#include "pokebola.hpp"
// verificar como usar atributos estáticos
int Pokebola::count = 0;
Pokebola::Pokebola()
{
    this->id = count;
    this->poke = nullptr;
    count++;
}

Pokebola::~Pokebola()
{
    delete poke;
}

int Pokebola::getId()
{
    return this->id;
}

pokemonCapturado *Pokebola::getPokemon()
{
    return this->poke;
}

void Pokebola::guardarPokemon()
{
    if (poke != nullptr)
    {
        poke->set_dormindo(true);
    }
}

Pokemon *Pokebola::liberarPokemon()
{
    poke->set_dormindo(0);
    return poke;
}

bool Pokebola::capturar(Pokemon &_poke)
{
    double numSorte = rand();
    double chanceCaptura = (numSorte / RAND_MAX);

    if (chanceCaptura > 0.5)
    {
        pokemonCapturado *pokemon_capturado = new pokemonCapturado(_poke);
        poke = pokemon_capturado;
        return true;
    }
    return false;
}