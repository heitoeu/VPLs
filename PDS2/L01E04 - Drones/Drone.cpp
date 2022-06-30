#include "Drone.hpp"
#define ENERGIA_CRITICA 50
#include <sstream>

Drone::Drone()
{
    this->_id = 0;
    this->_position._x = 0;
    this->_position._y = 0;
    this->_raio = 0;
}

Drone::Drone(int id, Ponto2D position, double raio)
{
    this->_id = id;
    this->_position = position;
    this->_raio = raio;
}

void Drone::mover(double v, double th, double t)
{
    float dx = 0, dy = 0;
    float deslocamento = v * t;

    dx = deslocamento * cos(th);
    dy = deslocamento * sin(th);

    _position._x = _position._x + dx;
    _position._y = _position._y + dy;

    _energia = _energia - deslocamento;
    if (_energia < ENERGIA_CRITICA)
    {
        std::cout << "Alerta, energia baixa!" << std::endl;
    }
}
// Possível problema
double Drone::calcular_distancia(Drone *drone)
{
    double distancia = 0;
    distancia = _position.calcular_distancia(&drone->_position);

    return distancia;
}

void Drone::broadcast_mensagem(Drone **drones, int n)
{
    std::string mensagem;
    std::ostringstream stream_mensagem;
    for (int i = 0; i < n; i++)
    {
        if ((this->calcular_distancia(drones[i]) <= this->_raio) && (i != this->_id))
        {
            stream_mensagem << "Drone: " << this->_id << ", Posição: " << this->_position.get_dados() << std::endl;
            mensagem = stream_mensagem.str();
            drones[i]->salvar_mensagem(mensagem);

            stream_mensagem.str("");
            stream_mensagem.clear();
        }
    }
}
// Tá aqui o erro com certeza
void Drone::salvar_mensagem(std::string mensagem)
{
    if (_posicao_mensagem < 5)
    {
        _buffer_mensagens[_posicao_mensagem] = mensagem;
        _posicao_mensagem = _posicao_mensagem + 1;
    }
    else
    {
        _posicao_mensagem = 0;
        _buffer_mensagens[_posicao_mensagem] = mensagem;
        _posicao_mensagem = _posicao_mensagem + 1;
    }
}

void Drone::imprimir_mensagens_recebidas()
{
    std::cout << "Mensagens de " << _id << ":" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        if (_buffer_mensagens[i].size() != 0)
        {
            std::cout << _buffer_mensagens[i];
        }
    }
}

void Drone::imprimir_status()
{
    std::cout << _id << "\t" << _position._x << "\t" << _position._y << "\t" << _energia << std::endl;
}