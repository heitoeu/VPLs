#include "Coordenada.hpp"

Coordenada::Coordenada() {}

Coordenada::Coordenada(int _row, int _col)
{
    this->row = _row;
    this->col = _col;
}

void Coordenada::getCoordenadasAdjacentes(std::vector<Coordenada> &adjacentes, int rowBoundary, int colBoundary)
{

    for (int i = (row - 1); i <= (row + 1); i++)
    {
        for (int j = (col - 1); j <= (col + 1); j++)
        {
            if ((0 <= i && i < rowBoundary) && (0 <= j && j < colBoundary))
            {
                Coordenada *aux = new Coordenada(i, j);
                adjacentes.push_back(*aux);
            }
        }
    }
}

// Adicionados posteriormente

int Coordenada::getRow()
{
    return this->row;
}
int Coordenada::getCol()
{
    return this->col;
}