#include "RegistroNBA.hpp"

void RegistroNBA::adicionar_time(std::string nome)
{
    Time time = Time(nome);
    this->times.insert(std::pair<std::string, Time>(nome, time));
}

void RegistroNBA::adicionar_jogador(std::string nome_time, std::string nome_jogador, std::string posicao, int salario)
{
    times[nome_time].adicionar_jogador(nome_jogador, posicao, salario);
    if (times[nome_time]._nome == "")
    {
        times[nome_time]._nome = nome_time;
    }
}

void RegistroNBA::imprimir_lista_jogadores_time(std::string nome_time)
{
    times[nome_time].imprimir_lista_jogadores();
}

void RegistroNBA::imprimir_folha_consolidada_time(std::string nome_time)
{
    times[nome_time].imprimir_folha_salarial_consolidada();
}

void RegistroNBA::imprimir_folha_salarial_geral()
{
    std::map<std::string, Time>::iterator it;
    for (it = times.begin(); it != times.end(); it++)
    {
        times[it->first].imprimir_folha_salarial_consolidada();
    }
}