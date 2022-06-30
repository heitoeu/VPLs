#include "pessoa.hpp"

void Pessoa::print(std::ostream &out)
{
    out << "(nome = " << this->nome << ", idade = " << this->idade << ", CPF = " << this->cpf << ")";
}

void Pessoa::GetCampos(std::vector<std::string> &out)
{
    out.push_back("nome");
    out.push_back("idade");
    out.push_back("cpf");
}

void Pessoa::setAtributo(std::string key, std::string valor)
{
    if (key == "nome")
    {
        this->nome = valor;
    }
    if (key == "idade")
    {
        this->idade = std::stoi(valor);
    }
    if (key == "cpf")
    {
        this->cpf = std::stoul(valor);
    }
}

std::string Pessoa::GetAtributo(std::string key)
{
    if (key == "nome")
    {
        return this->nome;
    }
    if (key == "idade")
    {
        return std::to_string(this->idade);
    }
    if (key == "cpf")
    {
        // Não funciona to_string por conta do compilador
        std::ostringstream stream_aux;
        stream_aux << this->cpf;
        std::string str_cpf = stream_aux.str();
        return str_cpf;
    }
    return "";
}

bool Pessoa::operator==(Pessoa &rhs)
{
    if (this->cpf == rhs.cpf)
    {
        return true;
    }
    return false;
}