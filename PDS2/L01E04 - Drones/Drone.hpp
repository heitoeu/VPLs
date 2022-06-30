#ifndef DRONE_H
#define DRONE_H
#include "Ponto2D.hpp"

struct Drone
{
    double _energia = 100;

    int _id;
    Ponto2D _position;
    double _raio;
    std::string _buffer_mensagens[5];
    int _posicao_mensagem = 0;

    Drone();
    Drone(int id, Ponto2D position, double raio);
    void mover(double v, double th, double t);
    double calcular_distancia(Drone *drone);

    void broadcast_mensagem(Drone **drones, int n);
    void salvar_mensagem(std::string mensagem);

    void imprimir_mensagens_recebidas();
    void imprimir_status();
};

#endif