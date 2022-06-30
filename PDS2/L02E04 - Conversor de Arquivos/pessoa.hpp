#ifndef PESSOA_H
#define PESSOA_H

#include "ireadable.hpp"
#include <string>
#include <sstream>

class Pessoa : public IReadable
{
private:
    std::string nome;
    int idade;
    unsigned long cpf;

protected:
    virtual void print(std::ostream &out) override;

public:
    virtual void GetCampos(std::vector<std::string> &out) override;
    virtual void setAtributo(std::string key, std::string valor) override;
    virtual std::string GetAtributo(std::string key) override;

    bool operator==(Pessoa &rhs);
};

#endif