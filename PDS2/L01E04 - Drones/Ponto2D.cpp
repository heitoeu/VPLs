#include "Ponto2D.hpp"
#include <sstream>

Ponto2D::Ponto2D()
{
    this->_x = 0;
    this->_y = 0;
}

Ponto2D::Ponto2D(double x, double y)
{
    this->_x = x;
    this->_y = y;
}

double Ponto2D::calcular_distancia(Ponto2D *ponto)
{
    float dx = ponto->_x - this->_x;
    float dy = ponto->_y - this->_y;
    return sqrt(dx * dx + dy * dy);
}

std::string Ponto2D::get_dados()
{
    std::string dados;
    std::ostringstream stream_x_y;

    stream_x_y << "[" << std::fixed << std::setprecision(2) << _x << ", " << _y << "]";
    dados = stream_x_y.str();

    return dados;
}