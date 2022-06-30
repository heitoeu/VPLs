#ifndef REGISTRONBA_H
#define REGISTRONBA_H
#include <map>
#include <iostream>
#include "Time.hpp"

class RegistroNBA
{

public:
    std::map<std::string, Time> times;

    void adicionar_time(std::string nome);
    void adicionar_jogador(std::string nome_time, std::string nome_jogador, std::string posicao, int salario);
    void imprimir_lista_jogadores_time(std::string nome_time);
    void imprimir_folha_consolidada_time(std::string nome_time);
    void imprimir_folha_salarial_geral();

    RegistroNBA() {}
};

#endif