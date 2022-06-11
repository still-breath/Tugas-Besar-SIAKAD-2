#ifndef __MAHASISWA_HPP__
#define __MAHASISWA_HPP__

#include <iostream>
#include "include/person.hpp"
#include "include/matkul.hpp"

class mahasiswa : public person {
private:
	int jumlahmatkul;
	std::string nrp;
	std::string departemen;
	int tahunmasuk;
	int semesterke;
	int skslulus;
	float ipk;
	std::vector<float> ips;

public:
	mahasiswa(int id, std::string nama, int dd, int mm, int yy,
					std::string nrp, std::string departemen, int tahunmasuk, int semesterke, int skslulus, float ipk, int jumlahmatkul);
	
	void setNRP(std::string nrp);
	std::string getNRP();

	void setDepartemen(std::string Departemen);
	std::string getDepartemen();

	void setTahunMasuk(int tahunmasuk);
	int getTahunMasuk();

	void setSemester(int semesterke);
	int getSemester();

	void setSKSLulus(int skslulus);
	int getSKSLulus();

	void setIPK(float ipk);
	float getIPK();

	void hitungIPK();

	void setIPS(int semester, float ips);
	float getIPS(int semester);
	std::vector<float> getAllIPS();
	std::vector<matkul> matkulDipilih;
};

#endif
