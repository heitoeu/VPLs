#ifndef FILE_H
#define FILE_H

#include "ireadable.hpp"
class File
{
public:
    virtual void readLine(std::string &head, std::string &line, IReadable &object) = 0;
    virtual std::string write(IReadable &object) = 0;
};

#endif