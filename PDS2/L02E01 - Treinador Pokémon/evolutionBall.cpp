#include "evolutionBall.hpp"

EvolutionBall::EvolutionBall(double _taxaPoder)
{
    this->taxaPoder = _taxaPoder;
}

bool EvolutionBall::evoluirPokemon()
{
    if (this->poke != nullptr)
    {
        if (poke->get_evoluido() == 0)
        {
            poke->evoluir(taxaPoder);
            return true;
        }
        return false;
    }
    return false;
}