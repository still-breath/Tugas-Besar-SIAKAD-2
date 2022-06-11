#ifndef __MATKUL_HPP__
#define __MATKUL_HPP__

#include <iostream>
#include <string>
#include <vector>

class matkul {
private:
    int idmatkul;
    std::string kodemk;
    std::string namamatkul;
    int bebansks;

public:
    matkul();
    matkul(int idmatkul, std::string kodemk, std::string namamatkul, int bebansks);

    void setIdMatkul(int idmatkul);
    int getIdMatkul();

    void setKodeMK(std::string kodemk);
    std::string getKodeMK();

    void setNamaMatkul(std::string namamatkul);
    std::string getNamaMatkul();

    void setBebanSKS(int bebansks);
    int getBebanSKS();
};

#endif
