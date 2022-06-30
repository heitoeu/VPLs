#ifndef PIXEL_H
#define PIXEL_H
#include <vector>
#include <iostream>
#include <iomanip>

class Pixel
{
private:
    int _red;
    int _green;
    int _blue;

public:
    Pixel();
    Pixel(int red, int green, int blue);

    void set_rgb(int red, int green, int blue);
    std::vector<int> get_rgb();

    void print();
};

#endif