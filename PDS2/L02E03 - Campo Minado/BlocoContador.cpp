#include "BlocoContador.hpp"

BlocoContador::BlocoContador(Coordenada _coord)
{
    this->coord = _coord;
    this->revelado = false;
    this->valor = 0;
}

BlocoContador::~BlocoContador() {}

bool BlocoContador::revelar(std::vector<std::vector<Bloco *>> &tabuleiro)
{
    // Gambiarra, eu acho 	(-_-;)・・・
    // tabuleiro[this->coord.getRow()][this->coord.getCol()]->setRevelar(); Pq isso não funcionou???
    this->revelado = true; // e isso funcionou??

    return true;
}

void BlocoContador::incrementarValor()
{
    this->valor++;
}
