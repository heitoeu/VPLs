#ifndef TREINADOR_H
#define TREINADOR_H

#include <iostream>
#include <vector>
#include "pokemonCapturado.hpp"
#include "evolutionBall.hpp"
#include "healthBall.hpp"

class Treinador
{
private:
    std::string nome;
    std::vector<EvolutionBall *> evolution_balls;
    std::vector<HealthBall *> health_balls;

public:
    Treinador(std::string _nome);
    ~Treinador();

    HealthBall *selecionarHealthBall(int _id);
    EvolutionBall *selecionarEvolBall(int _id);
    void adicionarPokebola(HealthBall *pokebola);
    void adicionarPokebola(EvolutionBall *pokebola);

    void listarPokemons();
};

#endif

/*
    Possiveis erros:
    Alocação dinamica
    Contrutores e *Destrutores*
    Health Ball (intervalo-não consegue healar)
    EvolutionBall (não consegue evoluir)
*/