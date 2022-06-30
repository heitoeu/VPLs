// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_atendimento.hpp"
//#include "Cliente.hpp"
//#include "FilaAtendimento.hpp"

#include <iostream>

int main()
{

    FilaAtendimento fila_atendimento;

    std::string nome;
    int idade, senha;
    char data;

    while (cin >> data)
    {

        switch (data)
        {
        case 'a':
            std::cin >> nome >> idade;
            fila_atendimento.adicionar_cliente(nome, idade);

            break;

        case 'c':
            fila_atendimento.chamar_cliente();

            break;
        case 'e':
            std::cin >> senha;
            fila_atendimento.estimativa_tempo_espera(senha);

            break;
        case 'p':
            fila_atendimento.imprimir_fila();

            break;
        case 'b':
            avaliacao_basica();
            break;
        }
    }

    return 0;
}