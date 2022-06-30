#include "Cliente.hpp"

Cliente::Cliente()
{
    _idade = 0;
    _senha = 1;
}

Cliente::Cliente(std::string nome, int idade, int senha)
{
    _idade = idade;
    _senha = senha;
    _nome = nome;
}

bool Cliente::eh_prioritario()
{
    if (_idade >= 60)
    {
        return true;
    }
    return false;
}

int Cliente::tempo_estimado_atendimento()
{
    if (eh_prioritario())
    {
        return 12;
    }
    return 8;
}

void Cliente::imprimir_dados()
{
    std::cout << _senha << "\t" << _nome << "\t" << _idade << std::endl;
}