#ifndef PONTO2D_H
#define PONTO2D_H

#include <iostream>
#include <cmath>
#include <iomanip>

struct Ponto2D
{
    double _x;
    double _y;

    // Método Construtor
    Ponto2D();
    Ponto2D(double x, double y);

    double calcular_distancia(Ponto2D *ponto);

    std::string get_dados();
};

#endif