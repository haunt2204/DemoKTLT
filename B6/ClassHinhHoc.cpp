#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

#define PI 3.14

class Diem {
private:
	int hoanhDo, tungDo; //Diem A
public:
	//Constructor
	Diem() {
		hoanhDo = 0;
		tungDo = 0;
	}
	Diem(int x, int y) {
		hoanhDo = x;
		tungDo = y;
	}
	//Set
	void setHoanhDo(int x) {
		hoanhDo = x;
	}
	void setTungDo(int y) {
		tungDo = y;
	}
	//Get
	int getHoanhDo() {
		return hoanhDo;
	}
	int getTungDo() {
		return tungDo;
	}
	//Hien thi
	void hienThi() {
		cout << "(" << hoanhDo << "," << tungDo << ")";
	}

	//Nhap 1 diem
	void nhapDiem() {
		cout << "Nhap hoanh do: "; cin >> hoanhDo;
		cout << "Nhap tung do: "; cin >> tungDo;
	}

	//Tinh khoang cach
	double tinhKhoangCach(Diem dB);
};

double Diem::tinhKhoangCach(Diem dB) {
	return sqrt(pow(hoanhDo - dB.getHoanhDo(), 2) + pow(tungDo - dB.getTungDo(), 2));
}
//Cac ham cua DuongTron
class DuongTron {
private:
	Diem toaDoTam;
	double banKinh;
public:
	DuongTron() {

	}
	DuongTron(Diem d, double bk) {
		toaDoTam = d;
		banKinh = bk;
	}
	void nhapDuongTron();
	void xuatDuongTron();
	int ktViTriTuongDoiDT(DuongTron dtB);
	double tinhDT();
	double tinhCV();
	//Get
	Diem getToaDoTam() {
		return toaDoTam;
	}
	double getBanKinh() {
		return banKinh;
	}
};

//Nhap xuat DuongTron
void DuongTron::nhapDuongTron() {
	cout << "Nhap toa do tam: ";
	toaDoTam.nhapDiem();
	cout << "Nhap ban kinh: ";
	cin >> banKinh;
}

void DuongTron::xuatDuongTron() {
	cout << "(";
	toaDoTam.hienThi();
	cout << "," << banKinh << ")";
	cout << " DT: " << tinhDT() << endl;
}

//Kiem tra vi tri tuong doi 2 DuongTron
int DuongTron::ktViTriTuongDoiDT(DuongTron dtB) {
	double kc = toaDoTam.tinhKhoangCach(dtB.toaDoTam);
	double tongBk = banKinh + dtB.banKinh;
	if (kc > tongBk)
		return 0;
	else if (kc == tongBk)
		return 1;
	return 2;
}

//Tinh DT, CV 
double DuongTron::tinhCV() {
	return 2 * PI*banKinh;
}

double DuongTron::tinhDT() {
	return PI*banKinh*banKinh;
}

//Cac ham cua DSDT
class DSDT {
private:
	vector<DuongTron> ds;
public:
	void nhapDsTuFile(string fileName);
	void xuatDsManHinh();
	void sapXep();
	void xuatDsTapTin(string fileName);
};

void DSDT::nhapDsTuFile(string fileName) {
	ifstream inFile(fileName);
	if (inFile.is_open()) {

		while (inFile.eof() == false) {
			int x, y;
			double bk;
			inFile >> x >> y >> bk;

			Diem d(x, y);//Toa do tam
			DuongTron dt(d, bk);

			ds.push_back(dt);
		}

		inFile.close();
	}
}

void DSDT::xuatDsManHinh() {
	for (int i = 0; i < ds.size(); i++) {
		ds[i].xuatDuongTron();
	}
}

void DSDT::xuatDsTapTin(string fileName) {
	ofstream outFile;
	outFile.open(fileName);
	if (outFile.is_open()) {
		for (int i = 0; i < ds.size(); i++) {
			outFile << ds[i].getToaDoTam().getHoanhDo() << "#"
				<< ds[i].getToaDoTam().getTungDo() << "#"
				<< ds[i].getBanKinh() << "#"
				<< ds[i].tinhCV() << "#"
				<< ds[i].tinhDT() << endl;
		}
		outFile.close();
	}
}

void swap(DuongTron &dt1, DuongTron &dt2) {
	DuongTron tam = dt1;
	dt1 = dt2;
	dt2 = tam;
}

void DSDT::sapXep() {
	for(int i=0; i<ds.size()-1; i++)
		for (int j = i + 1; j < ds.size(); j++) {
			if (ds[i].tinhDT() > ds[j].tinhDT()) //Tang dan
				swap(ds[i], ds[j]);
		}
}


int main() {
	Diem d1(2,3), d2(2,4), d3(8, 3);
	DuongTron dt1(d1,2), dt2(d3,1);

	///*dt1.xuatDuongTron();*/
	///*cout << "Khoang cach tu d2 -> d3: " << d2.tinhKhoangCach(d3) << endl;*/
	//string vtTuongDoi[] = { "Khong cat", "Tiep xuc", "Cat" };
	//cout << "Vi tri tuong doi dt1 va dt2: " << vtTuongDoi[dt1.ktViTriTuongDoiDT(dt2)] << endl;

	DSDT ds;
	ds.nhapDsTuFile("DuongTron.txt");
	ds.sapXep();
	ds.xuatDsManHinh();
	ds.xuatDsTapTin("DT_OUT.txt");
	system("pause");
	return 1;
}