#include "pokemon.hpp"

Pokemon::Pokemon(std::string _nome, std::string _tipo, std::string _pEvol, double _fA, double _fD, double _saude)
{
    this->nome = _nome;
    this->tipo = _tipo;
    this->proxEvolucao = _pEvol;
    this->forcaAtaque = _fA;
    this->forcaDefesa = _fD;
    this->saude = _saude;
}

Pokemon::Pokemon(const Pokemon &p)
{
    this->nome = p.nome;
    this->tipo = p.tipo;
    this->proxEvolucao = p.proxEvolucao;
    this->forcaAtaque = p.forcaAtaque;
    this->forcaDefesa = p.forcaDefesa;
    this->saude = p.saude;
}

std::string Pokemon::getNome()
{
    return this->nome;
}

void Pokemon::maxSaude()
{
    this->saude = maxHP;
}

void Pokemon::info()
{
    std::cout << "Pokemon: " << nome << ", " << tipo << ", " << forcaAtaque << ", " << forcaDefesa << ", " << saude << std::endl;
}
