#include "Pixel.hpp"

Pixel::Pixel()
{
    this->_red = 0;
    this->_green = 0;
    this->_blue = 0;
}

Pixel::Pixel(int red, int green, int blue)
{
    this->_red = red;
    this->_green = green;
    this->_blue = blue;
}

void Pixel::set_rgb(int red, int green, int blue)
{
    this->_red = red;
    this->_green = green;
    this->_blue = blue;
}

std::vector<int> Pixel::get_rgb()
{
    std::vector<int> vetor = {this->_red, this->_green, this->_blue};
    return vetor;
}

void Pixel::print()
{
    std::vector<int> vetor = this->get_rgb();
    std::cout << std::setfill('0') << std::setw(3) << vetor[0];
    std::cout << std::setfill('0') << std::setw(3) << vetor[1];
    std::cout << std::setfill('0') << std::setw(3) << vetor[2];
}