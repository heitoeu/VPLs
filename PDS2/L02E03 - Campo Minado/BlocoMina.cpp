#include "BlocoMina.hpp"

BlocoMina::BlocoMina(std::vector<std::vector<Bloco *>> &tabuleiro, Coordenada _coord)
{
    this->coord = _coord;
    this->revelado = false;
    this->valor = -1;
    std::vector<Coordenada> aux_adj;
    tabuleiro[this->coord.getRow()][this->coord.getCol()]->getcoord().getCoordenadasAdjacentes(aux_adj, tabuleiro.size(), tabuleiro.size());

    for (Coordenada vizinho : aux_adj)
    {
        if (tabuleiro[vizinho.getRow()][vizinho.getCol()]->getValor() == 0)
        {
            Bloco *b = new BlocoContador(this->getcoord());
            BlocoContador *bc = dynamic_cast<BlocoContador *>(b);
            delete tabuleiro[vizinho.getRow()][vizinho.getCol()];
            tabuleiro[vizinho.getRow()][vizinho.getCol()] = bc;
            bc->incrementarValor();
        }
        else if (tabuleiro[vizinho.getRow()][vizinho.getCol()]->getValor() > 0)
        {
            BlocoContador *bc = dynamic_cast<BlocoContador *>(tabuleiro[vizinho.getRow()][vizinho.getCol()]);
            bc->incrementarValor();
        }
    }
}

BlocoMina::~BlocoMina() {}

bool BlocoMina::revelar(std::vector<std::vector<Bloco *>> &tabuleiro)
{
    this->revelado = true;
    for (unsigned int i = 0; i < tabuleiro.size(); i++)
    {
        for (unsigned int j = 0; j < tabuleiro.size(); j++)
        {
            {
                if (tabuleiro[i][j]->ehRevelado() == false)
                {
                    tabuleiro[i][j]->revelar(tabuleiro);
                }
            }
        }
    }
    return false;
}