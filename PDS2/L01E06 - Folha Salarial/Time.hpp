#ifndef TIME_H
#define TIME_H

#include "Jogador.hpp"
#include <iostream>
#include <set>

class comparar_jogadores
{
public:
    bool operator()(const Jogador &j1, const Jogador &j2)
    {
        return j1.salario > j2.salario;
    }
};

class Time
{

public:
    std::string _nome;
    std::multiset<Jogador, comparar_jogadores> _jogadores;

    Time() {}
    Time(std::string nome);

    void adicionar_jogador(std::string nome, std::string posicao, int salario);
    void imprimir_lista_jogadores();
    void imprimir_folha_salarial_consolidada();
};

#endif