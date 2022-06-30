#include "pokemonCapturado.hpp"

pokemonCapturado::pokemonCapturado(Pokemon &_pok) : Pokemon(_pok)
{
    this->evoluido = false;
    this->dormindo = true;
}

void pokemonCapturado::set_dormindo(bool valor)
{
    this->dormindo = valor;
}

bool pokemonCapturado::get_evoluido()
{
    return this->evoluido;
}

void pokemonCapturado::evoluir(double taxaPoder)
{
    this->evoluido = true;
    this->nome = this->proxEvolucao;
    this->proxEvolucao = "";

    this->forcaAtaque += this->forcaAtaque * taxaPoder;
    this->forcaDefesa += this->forcaDefesa * taxaPoder;
}