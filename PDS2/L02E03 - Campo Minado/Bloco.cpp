#include "Bloco.hpp"

Bloco::Bloco(Coordenada _coord)
{
    this->coord = _coord;
    this->revelado = false;
    this->valor = 0;
}

Bloco::~Bloco() {}

bool Bloco::revelar(std::vector<std::vector<Bloco *>> &tabuleiro)
{
    // Pegar as coordenadas dos adjacentes
    std::vector<Coordenada> aux_adj;
    tabuleiro[this->coord.getRow()][this->coord.getCol()]->coord.getCoordenadasAdjacentes(aux_adj, tabuleiro.size(), tabuleiro.size());
    tabuleiro[this->coord.getRow()][this->coord.getCol()]->setRevelar();

    // Verificar se o bloco é adjacente e caso seja, revela ele de forma recurssiva
    for (Coordenada vizinho : aux_adj)
    {
        if (tabuleiro[vizinho.getRow()][vizinho.getCol()]->ehRevelado() == false)
        {
            tabuleiro[vizinho.getRow()][vizinho.getCol()]->revelar(tabuleiro);
        }
    }
    return true;
}

std::string Bloco::getSimbolo()
{
    if (this->revelado == false)
    {
        return "#";
    }
    if (this->valor == -1)
    {
        return "*";
    }
    std::string contador = std::to_string(this->valor);
    return contador;
}

bool Bloco::ehRevelado()
{
    return this->revelado;
}

// Métodos Adicionais
void Bloco::setRevelar()
{
    this->revelado = true;
}

Coordenada Bloco::getcoord()
{
    return this->coord;
}

int Bloco::getValor()
{
    return this->valor;
}