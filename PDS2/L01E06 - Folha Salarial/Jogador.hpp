#ifndef JOGADOR_H
#define JOGADOR_H
#include <iostream>

class Jogador
{
public:
    std::string _nome;
    std::string _posicao;
    int salario;

    void imprimir_dados();
    Jogador(std::string nome, std::string posicao, int salario);
};

#endif