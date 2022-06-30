#ifndef FILAATENDIMENDO_H
#define FILAATENDIMENTO_H

#include "Cliente.hpp"
#include <iostream>

struct Node
{
    Cliente cliente;
    Node *next;

    Node(Cliente cliente, Node *next);
};

struct Fila
{
    int size = 0;

    Node *head = nullptr;
    Node *tail = nullptr;

    Cliente *remove_front();
    void push_back(Cliente cliente);
};

struct FilaAtendimento
{
    int cont_senha = 0;
    Fila normal, prioritaria;

    void adicionar_cliente(std::string nome, int idade);
    Cliente *chamar_cliente();
    void estimativa_tempo_espera(int senha);
    void imprimir_fila();
};

#endif