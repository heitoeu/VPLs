#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>

struct Cliente
{
    int _idade;
    int _senha;
    std::string _nome;

    Cliente();
    Cliente(std::string nome, int idade, int senha);

    bool eh_prioritario();
    int tempo_estimado_atendimento();
    void imprimir_dados();
};

#endif