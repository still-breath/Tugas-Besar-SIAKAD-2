#include <iostream>
#include <vector>

#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matkul.hpp"

using namespace std;

long long unsigned idmatkul = 0, inputID = 0;

int main()
{
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;
	vector<matkul> recMatkul;

	int menu_terpilih;
	int dd, mm, yy, tahunmasuk, id=0, semesterke, skslulus, bebansks=0, jumlahmatkul=0;
	string nama, nrp, npp, departemen, pendidikan, unit, namamatkul, kodemk;

	while(1) {
		cout << endl;
		cout << "Selamat datang di Universitas X" << endl << endl;
		cout << "Data statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << " mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << " mahasiswa" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << " mahasiswa" << endl;
		cout << endl;
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
		cout << "  4. Tambah Matkul Baru" << endl;
		cout << "  5. Masukkan Nilai Mahasiswa" << endl;
		cout << "  6. Menu Mahasiswa Ambil Matkul" << endl;
		cout << "  7. Tampilkan semua Mahasiswa dan Matkul Yang Diambil" << endl;
		cout << "  8. Tampilkan semua Dosen" << endl;
		cout << "  9. Tampilkan semua Tenaga Kependidikan" << endl;
		cout << "  10. Tampilkan semua Mata Kuliah" << endl;
		cout << "  0. Tutup Program SIAKAD" << endl;
		cout << "-> Silahkan memilih salah satu: ";
		cin >> menu_terpilih;

		switch (menu_terpilih) {
			case 1:
			{
				cout << "Nama Mahasiswa: ";
				getline(cin >> ws, nama);
				
				cout << "Tanggal Lahir (dd mm yyyy): ";
				cin >> dd >> mm >> yy;

				cout << "Departemen: ";
				getline(cin >> ws, departemen);

				cout << "NRP Mahasiswa: ";
				cin >> nrp;

				cout << "Tahun Masuk: ";
				cin >> tahunmasuk;

				cout << "Semester ke: ";
				cin >> semesterke;

				cout << "SKS Lulus (keseluruhan): ";
				cin >> skslulus;

				float ipk = 0.0;
				cout << "IPK: " << ipk;

				id = 1 + recMhs.size();
				mahasiswa mhs(id, nama, dd, mm, yy, nrp, departemen, tahunmasuk, semesterke, skslulus, ipk, jumlahmatkul);
				recMhs.push_back(mhs);
			}
				break;
			case 2:
			{
				cout << "Nama Dosen: ";
				getline(cin >> ws, nama);

				cout << "Tanggal Lahir (dd mm yyyy): ";
				cin >> dd >> mm >> yy;

				cout << "Departemen: ";
				getline(cin >> ws, departemen);

				cout << "NPP Dosen: ";
				cin >> npp;

				cout << "Pendidikan Terakhir: ";
				getline(cin >> ws, pendidikan);

				id = 1 + recDosen.size();
				dosen dosen(id, nama, dd, mm, yy, npp, departemen, pendidikan);
				recDosen.push_back(dosen);
			}
				break;
			case 3:
			{
				cout << "Nama Tendik: ";
				getline(cin >> ws, nama);

				cout << "Tanggal Lahir (dd mm yyyy): ";
				cin >> dd >> mm >> yy;

				cout << "NPP Tendik: ";
				cin >> npp;

				cout << "Unit: ";
				getline(cin >> ws, unit);

				id = 1 + recTendik.size();
				tendik tendik(id, nama, dd, mm, yy, npp, unit);
				recTendik.push_back(tendik);
			}
				break;			
			case 4:
			{
				cout << endl;
				cout << "Menu Tambah Mata Kuliah" << endl;
				cout << "[]===[]>>>> <<<<[]===[]" << endl;
				
				cout << "Nama Mata Kuliah: ";
				getline(cin >> ws, namamatkul);
				cout << "Kode Mata Kuliah: ";
				getline(cin >> ws, kodemk);
				cout << "Beban SKS: ";
				cin >> bebansks;
				++idmatkul;

				matkul matkul(idmatkul, kodemk, namamatkul, bebansks);
				recMatkul.push_back(matkul);
			}
				break;
			case 5:
			{
				cout << endl;
				cout << "Menu Input Nilai Mahasiswa" << endl;
				for(long unsigned i=0; i<recMhs.size(); i++)
				{
					cout << endl;
					cout << "ID Mahasiswa: " << recMhs[i].getId() << endl;
					cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
					cout << "NRP dan Departemen: " << recMhs[i].getNRP() << "/" << recMhs[i].getDepartemen() << endl;
				}
				cout << endl;
				cout << "Masukkan ID Mahasiswa: ";
				cin >> inputID;
				system("cls||clear");

				cout << "\n" << recMhs[inputID-1].getId() << endl;
				cout << recMhs[inputID-1].getNama() << endl;

				cout << "-> Masukkan Nilai IP: ";
				if(recMhs[inputID-1].getSemester() > 1)
				{
					float ipk = 0.0, ips = 0.0;
					for(long unsigned i=1; i<recMhs[inputID-1].getSemester(); i++)
					{
						cout << "Semester " << i << ": ";
						cin >> ips; recMhs[inputID-1].setIPS(i,ips);
						ipk += recMhs[inputID-1].getIPS(i);
					}					
					ipk /= (recMhs[inputID-1].getSemester() - 1);
					recMhs[inputID-1].setIPK(ipk);
					cout << "IPK: " << ipk << endl;
				} else {
					continue;
				}
				cin.ignore();
			}
				break;
			case 6:
			{
				cout << endl;
				cout << "Menu Ambil Mata Kuliah bagi Mahasiswa" << endl;
				cout << "=====================================" << endl;
				while (recMatkul.size() == 0)
				{
					cout << "Maaf Belum Tersedia Matkul" << endl;
					cout << "Silahkan Tekan Enter Untuk Kembali Ke Menu";
					cin.ignore(); cin.ignore();
					return main();
				}
				for(long unsigned i=0; i<recMhs.size(); i++)
				{
					cout << endl;
					cout << "ID Mahasiswa: " << recMhs[i].getId() << endl;
					cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
					cout << "NRP dan Departemen: " << recMhs[i].getNRP() << "/" << recMhs[i].getDepartemen() << endl;
				}
				cout << endl;
				cout << "Masukkan ID Mahasiswa: ";
				cin >> inputID;

				cout << "Daftar Mata Kuliah" << endl;
				cout << "==================" << endl;
				for(long unsigned i = 0; i<recMatkul.size(); i++){
					cout << "ID Mata Kuliah: " << recMatkul[i].getIdMatkul() << endl;
					cout << "Nama Mata Kuliah: " << recMatkul[i].getNamaMatkul() << endl;
					cout << "Kode Mata Kuliah: " << recMatkul[i].getKodeMK() << endl;
					cout << "Beban SKS: " << recMatkul[i].getBebanSKS() << endl;
				}

				cout << "Input ID Mata Kuliah Yang Ingin Diambil: ";
				cin >> idmatkul;

				int pos1 = recMatkul[idmatkul-1].getIdMatkul();
				string pos2 = recMatkul[idmatkul-1].getNamaMatkul();
				string pos3 = recMatkul[idmatkul-1].getKodeMK();
				int pos4 = recMatkul[idmatkul-1].getBebanSKS();

				matkul matkul;
				recMhs[inputID-1].matkulDipilih.push_back(matkul);
				recMhs[inputID-1].matkulDipilih[jumlahmatkul].setIdMatkul(pos1);
				recMhs[inputID-1].matkulDipilih[jumlahmatkul].setNamaMatkul(pos2);
				recMhs[inputID-1].matkulDipilih[jumlahmatkul].setKodeMK(pos3);
				recMhs[inputID-1].matkulDipilih[jumlahmatkul].setBebanSKS(pos4);
				jumlahmatkul++;

				cout << endl;
				cout << "Mata Kuliah Berhasil Ditambahkan" << endl;
			}
				break;
			case 7:
			{
				for(long unsigned i=0; i<recMhs.size(); i++)
				{
					cout << endl;
					cout << "ID Mahasiswa: " << recMhs[i].getId() << endl;
					cout << "Nama Mahasiswa: " << recMhs[i].getNama() << endl;
					cout << "Tanggal Lahir: " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
					cout << "NRP: " << recMhs[i].getNRP() << endl;
					cout << "Departemen: " << recMhs[i].getDepartemen() << endl;
					cout << "Tahun Masuk: " << recMhs[i].getTahunMasuk() << endl;
					cout << "Semester ke: " << recMhs[i].getSemester() << endl;
					cout << "SKS Lulus: " << recMhs[i].getSKSLulus() << endl;
					cout << "Jumlah Mata Kuliah: " << recMhs[i].matkulDipilih.size() << endl;
					cout << "IPK: " << recMhs[i].getIPK() << endl << endl;
				}
				int idmhs;
				cout << "Pilih ID Mahasiswa Yang Ingin Dilihat Data Matkulnya" << endl;
				cout << "-> ID: ";
				cin >> idmhs;	

				cout << "Data Mata Kuliah " << recMhs[idmhs-1].getNama() << endl;
				for(long unsigned i = 0; i<recMhs[idmhs-1].matkulDipilih.size(); i++){
					cout << "ID Mata Kuliah: " << recMhs[idmhs-1].matkulDipilih[i].getIdMatkul() << endl;
					cout << "Nama Mata Kuliah: " << recMhs[idmhs-1].matkulDipilih[i].getNamaMatkul() << endl;
					cout << "Kode Mata Kuliah: " << recMhs[idmhs-1].matkulDipilih[i].getKodeMK() << endl;
					cout << "Beban SKS: " << recMhs[idmhs-1].matkulDipilih[i].getBebanSKS() << endl; 
				}
			}
				break;
			case 8:
			{
				for(long unsigned i=0; i<recDosen.size(); i++)
				{
					cout << endl;
					cout << "ID Dosen: " << recDosen[i].getId() << endl;
					cout << "Nama Dosen: " << recDosen[i].getNama() << endl;
					cout << "Tanggal Lahir: " << recDosen[i].getTglLahir() << "/" << recDosen[i].getBulanLahir() << "/" << recDosen[i].getTahunLahir() << endl;
					cout << "NPP: " << recDosen[i].getNPP() << endl;
					cout << "Departemen: " << recDosen[i].getDepartemen() << endl;
					cout << "Pendidikan Terakhir: " << recDosen[i].getPendidikan() << endl;
				}
			}
				break;
			case 9:
			{
				for(long unsigned i=0; i<recTendik.size(); i++)
				{
					cout << endl;
					cout << "ID Tenaga Kependidikan: " << recTendik[i].getId() << endl;
					cout << "Nama Tenaga Kependidikan: " << recTendik[i].getNama() << endl;
					cout << "Tanggal Lahir: " << recTendik[i].getTglLahir() << "/" << recTendik[i].getBulanLahir() << "/" << recTendik[i].getTahunLahir() << endl;
					cout << "NPP: " << recTendik[i].getNPP() << endl;
					cout << "Unit: " << recTendik[i].getUnit() << endl;
					cout << endl;
				}
			}
				break;
			case 10:
			{
				for (long unsigned i = 0; i<recMatkul.size(); i++)
				{
					cout << endl;
					cout << "ID Mata Kuliah: " << recMatkul[i].getIdMatkul() << endl;
					cout << "Nama Mata Kuliah: " << recMatkul[i].getNamaMatkul() << endl;
					cout << "Kode Mata Kuliah: " << recMatkul[i].getKodeMK() << endl;
					cout << "Beban SKS: " << recMatkul[i].getBebanSKS() << endl;
				}
			}
				break;
			case 0:
				return 0;
				break;
		}
	}

	return 0;
}
