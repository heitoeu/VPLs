#ifndef COORDENADA_H
#define COORDENADA_H

#include <vector>
#include <math.h>
#include <iostream>

class Coordenada
{
private:
    int row;
    int col;

public:
    Coordenada();
    Coordenada(int _row, int _col);

    void getCoordenadasAdjacentes(std::vector<Coordenada> &adjacentes, int rowBoundary, int colBoundary);

    int getRow();
    int getCol();
};

#endif