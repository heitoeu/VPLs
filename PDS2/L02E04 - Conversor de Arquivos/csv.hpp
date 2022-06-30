#ifndef CSV_H
#define CSV_H

#include <sstream>

#include "file.hpp"

class CSV : public File
{
private:
    void split(std::string &str, std::vector<std::string> &out);

public:
    std::string getHeader(IReadable &object);
    virtual void readLine(std::string &head, std::string &line, IReadable &object) override;
    virtual std::string write(IReadable &object) override;
};

#endif