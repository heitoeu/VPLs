#include "treinador.hpp"

Treinador::Treinador(std::string _nome)
{
    this->nome = _nome;
}

Treinador::~Treinador()
{
    for (unsigned int i = health_balls.size(); i < 0; i--)
    {
        delete health_balls[i];
    }

    for (unsigned int i = evolution_balls.size(); i < 0; i--)
    {
        delete evolution_balls[i];
    }
}

HealthBall *Treinador::selecionarHealthBall(int _id)
{
    for (unsigned i = 0; i < health_balls.size(); i++)
    {
        if (_id == health_balls[i]->getId())
        {
            return health_balls[i];
        }
    }
    return nullptr;
}

EvolutionBall *Treinador::selecionarEvolBall(int _id)
{
    for (unsigned i = 0; i < evolution_balls.size(); i++)
    {
        if (_id == evolution_balls[i]->getId())
        {
            return evolution_balls[i];
        }
    }
    return nullptr;
}

void Treinador::adicionarPokebola(HealthBall *pokebola)
{
    health_balls.push_back(pokebola);
}

void Treinador::adicionarPokebola(EvolutionBall *pokebola)
{
    evolution_balls.push_back(pokebola);
}

void Treinador::listarPokemons()
{
    std::cout << "Treinador: " << this->nome << std::endl;
    if (evolution_balls.size() != 0 || health_balls.size() != 0)
    {
        for (unsigned int i = 0; i < health_balls.size(); i++)
        {
            std::cout << "HealthBall ID:" << health_balls[i]->getId() << std::endl;
            if (health_balls[i]->getPokemon() != nullptr)
            {
                health_balls[i]->getPokemon()->info();
            }
            else
            {
                std::cout << "A pokebola não possui um pokemon" << std::endl;
            }
        }

        for (unsigned int i = 0; i < evolution_balls.size(); i++)
        {
            std::cout << "EvolutionBall ID:" << evolution_balls[i]->getId() << std::endl;
            if (evolution_balls[i]->getPokemon() != nullptr)
            {
                evolution_balls[i]->getPokemon()->info();
            }
            else
            {
                std::cout << "A pokebola não possui um pokemon" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "O treinador não possui pokebolas" << std::endl;
    }
}
