#ifndef IREADABLE_H
#define IREADABLE_H

#include <iostream>
#include <vector>

class IReadable
{
protected:
    virtual void print(std::ostream &out) = 0;

public:
    virtual void GetCampos(std::vector<std::string> &out) = 0;
    virtual void setAtributo(std::string key, std::string valor) = 0;
    virtual std::string GetAtributo(std::string key) = 0;
    friend std::ostream &operator<<(std::ostream &out, IReadable &readable);
};

#endif