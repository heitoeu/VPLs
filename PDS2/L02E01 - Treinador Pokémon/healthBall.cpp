#include "healthBall.hpp"

HealthBall::HealthBall(double _intervalo)
{
    this->intervalo = _intervalo;
}

bool HealthBall::recuperarPokemon()
{
    time_t atual = time(NULL);
    if (this->poke != nullptr)
    {
        if (difftime(atual, ultimoUso) > intervalo)
        {
            this->ultimoUso = atual;
            this->poke->maxSaude();
            return true;
        }
        return false;
    }
    return false;
}
