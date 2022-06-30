#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <string>
#define maxHP 100

class Pokemon
{
protected:
    std::string nome;
    std::string tipo;

    double saude;
    double forcaAtaque;
    double forcaDefesa;

    std::string proxEvolucao;

public:
    Pokemon() {}
    Pokemon(std::string _nome, std::string _tipo, std::string _pEvol, double _fA, double _fD, double _saude);
    Pokemon(const Pokemon &p);

    std::string getNome();
    void maxSaude();
    void info();
};

#endif