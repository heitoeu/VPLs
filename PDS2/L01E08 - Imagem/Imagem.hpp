#ifndef IMAGEM_H
#define IMAGEM_H
#include "Pixel.hpp"
#include <string>

class Imagem
{
private:
    int _width;
    int _height;
    std::vector<std::vector<Pixel>> _screen_matrix;

public:
    Imagem();
    Imagem(int width, int height);

    void initialize_image(int width, int height);
    void fill(int row, int col, std::string pixel);

    void to_grayscale();
    void grayscale_thresholding(int lim);

    void show();
};

#endif