#include "LimitedQueue.hpp"

LimitedQueue::LimitedQueue(int max_size)
{
    if (max_size <= 0)
    {
        throw InvalidSizeException();
    }
    this->max_size = max_size;
}

void LimitedQueue::push_back(int k)
{

    if (this->fila.size() >= this->max_size)
    {
        throw QueueFullException();
    }

    this->fila.push_back(k);
}

void LimitedQueue::pop_front()
{
    if (this->fila.empty())
    {
        throw QueueEmptyException();
    }

    this->fila.pop_front();
}

int LimitedQueue::front()
{
    if (this->fila.empty())
    {
        throw QueueEmptyException();
    }

    return this->fila.front();
}

int LimitedQueue::back()
{
    if (this->fila.empty())
    {
        throw QueueEmptyException();
    }

    return this->fila.back();
}

int LimitedQueue::find(int k)
{
    if (this->fila.empty())
    {
        throw QueueEmptyException();
    }

    int aux = 0;
    for (auto element : this->fila)
    {
        if (element == k)
        {
            return aux;
        }
        aux++;
    }
    throw ItemNotFoundException();
}

void LimitedQueue::print()
{
    if (this->fila.empty())
    {
        throw QueueEmptyException();
    }
    else
    {
        for (auto element : this->fila)
        {
            std::cout << element << std::endl;
        }
    }
}

int LimitedQueue::get_max_size()
{
    return this->max_size;
}