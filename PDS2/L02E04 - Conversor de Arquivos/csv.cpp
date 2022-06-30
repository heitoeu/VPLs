#include "csv.hpp"

void CSV::split(std::string &str, std::vector<std::string> &out)
{
    // FUNCIONA!!!]
    std::string str_split = str;
    std::string target = ";";
    size_t pos = 0;
    std::string word;

    while ((pos = str_split.find(target)) != std::string::npos)
    {
        word = str_split.substr(0, pos);
        out.push_back(word);
        str_split.erase(0, pos + target.length());
    }
    out.push_back(str_split);
}

std::string CSV::getHeader(IReadable &object)
{
    std::string header;
    std::ostringstream stream_aux;
    std::vector<std::string> vec_campos;

    object.GetCampos(vec_campos);
    stream_aux << vec_campos[0] << ";" << vec_campos[1] << ";" << vec_campos[2];
    header = stream_aux.str();

    return header;
}

void CSV::readLine(std::string &head, std::string &line, IReadable &object)
{
    std::vector<std::string> header;
    this->split(head, header);

    std::vector<std::string> dados;
    this->split(line, dados);

    object.setAtributo(header[0], dados[0]);
    object.setAtributo(header[1], dados[1]);
    object.setAtributo(header[2], dados[2]);
}

std::string CSV::write(IReadable &object)
{
    std::vector<std::string> out;
    std::stringstream string_aux;
    std::string obj_convertido;
    object.GetCampos(out);
    string_aux << object.GetAtributo(out[0]) << ";" << object.GetAtributo(out[1]) << ";" << object.GetAtributo(out[2]);
    obj_convertido = string_aux.str();

    return obj_convertido;
}