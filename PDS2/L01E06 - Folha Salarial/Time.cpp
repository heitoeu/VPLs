#include "Time.hpp"

Time::Time(std::string nome)
{
    this->_nome = nome;
}

void Time::adicionar_jogador(std::string nome, std::string posicao, int salario)
{
    Jogador jogador = Jogador(nome, posicao, salario);
    this->_jogadores.insert(jogador);
}

void Time::imprimir_lista_jogadores()
{
    std::cout << this->_nome << std::endl;
    for (Jogador i : this->_jogadores)
    {
        i.imprimir_dados();
    }
}

void Time::imprimir_folha_salarial_consolidada()
{
    int folha_salarial = 0;
    for (Jogador i : this->_jogadores)
    {
        folha_salarial += i.salario;
    }

    std::cout << this->_nome << "\t" << folha_salarial << std::endl;
}