// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_nba.hpp"
#include <iostream>

int main()
{
    RegistroNBA registro_nba;
    char data;
    std::string nome_time, nome_jogador, posicao;
    int salario = 0;

    while (cin >> data)
    {

        switch (data)
        {
        case 't':
            cin >> nome_time;
            registro_nba.adicionar_time(nome_time);
            break;
        case 'j':
            cin >> nome_time >> nome_jogador >> posicao >> salario;
            registro_nba.adicionar_jogador(nome_time, nome_jogador, posicao, salario);
            break;
        case 'l':
            cin >> nome_time;
            registro_nba.imprimir_lista_jogadores_time(nome_time);
            break;
        case 'f':
            cin >> nome_time;
            registro_nba.imprimir_folha_consolidada_time(nome_time);
            break;
        case 'g':
            registro_nba.imprimir_folha_salarial_geral();
            break;
        case 'b':
            avaliacao_basica();
            break;
        }
    }

    return 0;
}