#include <iostream>
#include <vector>
#include "include/matkul.hpp"

matkul::matkul(){}
matkul::matkul(int idmatkul, std::string kodemk, std::string namamatkul, int bebansks)
        : idmatkul(idmatkul), kodemk(kodemk), namamatkul(namamatkul), bebansks(bebansks)
{
}
void matkul::setIdMatkul(int idmatkul)
{
    this->idmatkul = idmatkul;
}
int matkul::getIdMatkul()
{
    return this->idmatkul;
}

void matkul::setKodeMK(std::string kodemk)
{
    this->kodemk = kodemk;
}
std::string matkul::getKodeMK()
{
    return this->kodemk;
}

void matkul::setNamaMatkul(std::string namamatkul)
{
    this->namamatkul = namamatkul;
}
std::string matkul::getNamaMatkul()
{
    return this->namamatkul;
}

void matkul::setBebanSKS(int bebansks)
{
    this->bebansks = bebansks;
}
int matkul::getBebanSKS()
{
    return this->bebansks;
}