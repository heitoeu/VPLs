// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_excecoes.hpp"
#include "LimitedQueue.hpp"
#include "Exceptions.hpp"

int main()
{
    char data;
    int max_size;
    int k;
    LimitedQueue queue;

    while (std::cin >> data)
    {
        switch (data)
        {
        case 'i':
            std::cin >> max_size;
            try
            {
                queue = LimitedQueue(max_size);
            }
            catch (InvalidSizeException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            break;

        case 'p':
            std::cin >> k;
            try
            {
                queue.push_back(k);
            }
            catch (QueueFullException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            break;

        case 'o':
            try
            {
                queue.pop_front();
            }
            catch (QueueEmptyException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            break;
        case 'f':
            try
            {
                std::cout << queue.front();
            }
            catch (QueueEmptyException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            break;

        case 'l':
            try
            {
                std::cout << queue.back();
            }
            catch (QueueEmptyException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            break;
        case 'm':
            try
            {
                queue.print();
            }
            catch (QueueEmptyException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            break;
        case 'd':
            std::cin >> k;
            try
            {
                std::cout << queue.find(k) << std::endl;
            }
            catch (QueueEmptyException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            catch (ItemNotFoundException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            break;
        case 'b':
            try
            {
                avaliacao_basica();
            }
            catch (InvalidSizeException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            catch (QueueFullException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            catch (QueueEmptyException &e)
            {
                std::cout << "Excecao: " << e.name;
            }
            catch (ItemNotFoundException &e)
            {
                std::cout << "Excecao: " << e.name;
            }

            break;
        }
    }
    return 0;
}