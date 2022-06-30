#include "Jogador.hpp"

Jogador::Jogador(std::string nome, std::string posicao, int salario)
{
    this->_nome = nome;
    this->_posicao = posicao;
    this->salario = salario;
}

void Jogador::imprimir_dados()
{
    std::cout << _nome << "\t";
    std::cout << _posicao << "\t";
    std::cout << salario << std::endl;
}