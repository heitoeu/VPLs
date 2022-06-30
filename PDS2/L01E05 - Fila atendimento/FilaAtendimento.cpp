#include "FilaAtendimento.hpp"

Node::Node(Cliente cliente, Node *next)
{
    this->cliente = cliente;
    this->next = next;
}

Cliente *Fila::remove_front()
{
    Node *x = this->head;
    this->head = head->next;
    this->size--;
    return &x->cliente;
}

void Fila::push_back(Cliente cliente)
{
    Node *node = new Node(cliente, nullptr);
    if (this->head == nullptr)
    {
        this->head = node;
        this->tail = node;
        this->size++;
    }
    else
    {
        tail->next = node;
        tail = node;
        this->size++;
    }
}

void FilaAtendimento::adicionar_cliente(std::string nome, int idade)
{
    this->cont_senha++;
    Cliente aux = Cliente(nome, idade, this->cont_senha);
    if (aux.eh_prioritario())
    {
        this->prioritaria.push_back(aux);
    }
    if (!aux.eh_prioritario())
    {
        this->normal.push_back(aux);
    }
}

Cliente *FilaAtendimento::chamar_cliente()
{
    if (prioritaria.size != 0)
    {
        return prioritaria.remove_front();
    }
    if (normal.size != 0)
    {
        return normal.remove_front();
    }
    std::cout << "Fila vazia!";
    return 0;
}

// Provavelmente tem problema aqui (⊙_⊙) AQUI. VAMOS PARA O CAOS E SEQUENCIAS DE IFS
void FilaAtendimento::estimativa_tempo_espera(int senha)
{
    int waiting_time = 0;

    if (prioritaria.size != 0)
    {

        Node *aux = prioritaria.head;
        while (aux != nullptr && aux->cliente._senha != senha)
        {
            waiting_time += aux->cliente.tempo_estimado_atendimento();
            aux = aux->next;
        }

        // Caso a pessoa seja prioritária (o_O) !
        if (aux != nullptr)
        {
            std::cout << "Tempo estimado para atender " << aux->cliente._nome << " eh " << waiting_time << " minutos.";
        }
        else
        {
            aux = normal.head;
            while (aux != nullptr && aux->cliente._senha != senha)
            {
                waiting_time += aux->cliente.tempo_estimado_atendimento();

                aux = aux->next;
            }
            std::cout << "Tempo estimado para atender " << aux->cliente._nome << " eh " << waiting_time << " minutos.";
        }
    }
    else

        if (normal.size != 0)
    {
        Node *aux = normal.head;
        while (aux != nullptr && aux->cliente._senha != senha)
        {
            waiting_time += aux->cliente.tempo_estimado_atendimento();

            aux = aux->next;
        }
        std::cout << "Tempo estimado para atender " << aux->cliente._nome << " eh " << waiting_time << " minutos.";
    }
}

void FilaAtendimento::imprimir_fila()
{
    Node *aux = prioritaria.head;
    while (aux != nullptr)
    {
        aux->cliente.imprimir_dados();
        aux = aux->next;
    }

    aux = normal.head;

    while (aux != nullptr)
    {
        aux->cliente.imprimir_dados();
        aux = aux->next;
    }
}
