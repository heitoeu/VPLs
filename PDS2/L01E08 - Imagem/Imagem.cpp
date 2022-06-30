#include "Imagem.hpp"

Imagem::Imagem() {}
Imagem::Imagem(int width, int height)
{
    this->_width = width;
    this->_height = height;
}

void Imagem::initialize_image(int width, int height)
{
    this->_width = width;
    this->_height = height;
    _screen_matrix = std::vector<std::vector<Pixel>>(height, std::vector<Pixel>(width));
}

void Imagem::fill(int row, int col, std::string pixel)
{
    std::string str_red = pixel.substr(0, 3);
    std::string str_green = pixel.substr(3, 3);
    std::string str_blue = pixel.substr(6, 3);

    //  Pixel que tem que receber as info
    _screen_matrix[row][col].set_rgb(stoi(str_red), stoi(str_green), stoi(str_blue));
}

void Imagem::to_grayscale()
{
    for (int i = 0; i < this->_height; i++)
    {
        for (int j = 0; j < this->_width; i++)
        {
            std::vector<int> pixel_rgb = _screen_matrix[i][j].get_rgb();
            int gray_pixel = (pixel_rgb[0] + pixel_rgb[1] + pixel_rgb[2]) / 3;

            _screen_matrix[i][j].set_rgb(gray_pixel, gray_pixel, gray_pixel);
        }
    }
}

void Imagem::grayscale_thresholding(int lim)
{
    for (int i = 0; i < this->_height; i++)
    {
        for (int j = 0; j < this->_width; i++)
        {
            std::vector<int> pixel_rgb = _screen_matrix[i][j].get_rgb();
            int gray_pixel = (pixel_rgb[0] + pixel_rgb[1] + pixel_rgb[2]) / 3;
            if (gray_pixel > lim)
            {
                gray_pixel = 255;
            }
            else
            {
                gray_pixel = 0;
            }

            _screen_matrix[i][j].set_rgb(gray_pixel, gray_pixel, gray_pixel);
        }
    }
}

void Imagem::show()
{
    for (int i = 0; i < this->_width; i++)
    {
        for (int j = 0; j < this->_height; j++)
        {
            _screen_matrix[i][j].print();
            std::cout << " ";
        }

        std::cout << std::endl;
    }
}