#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


//Dinh nghia cac kieu du lieu
struct NTN {
	int dd, mm, yyyy;
};

struct Lop {
	char maLop[5]; //CS31
	char tenLop[9]; //DH23CS01
	string tenKhoa;
	int soSv;
	NTN ngayKg;//02/03/2024
};

struct DSL {
	vector<Lop> ds;
};

//Cac ham dung chung
bool isNamNhuan(int nNam) {
	if (nNam % 400 == 0 || (nNam % 4 == 0 && nNam % 100 != 0))
		return true;
	return false;
}

int tinhSoNgay(int nThang, int nNam) {
	int soNgay = 0;
	switch (nThang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		soNgay = 31;
		break;
	case 4: case 6: case 9: case 11:
		soNgay = 30;
		break;
	case 2:
		if (isNamNhuan(nNam) == true)
			soNgay = 29;
		else
			soNgay = 28;
		break;
	}
	return soNgay;
}


//Cac ham cua NTN
bool ktNgayHopLe(const NTN ntn) {
	if (ntn.yyyy <= 0)
		return false;
	if (ntn.mm <= 0 || ntn.mm > 12)
		return false;
	if (ntn.dd <= 0 || ntn.dd > tinhSoNgay(ntn.mm, ntn.yyyy))
		return false;
	return true;
}

//Cac ham cua Lop
int nhap1Lop(Lop *&l) {
	cout << "Nhap ma lop: ";
	cin >> l->maLop;
	cout << "Nhap ten lop: ";
	cin >> l->tenLop;
	cout << "Nhap ten khoa: ";
	getline(cin, l->tenKhoa);
	cin >> l->soSv;
	//Nhap ngay khai giang
	NTN ngay;
	cout << "Nhap ngay khai giang: ";
	cin >> ngay.dd;
	cin.ignore(1);
	cin >> ngay.mm;
	cin.ignore(1);
	cin >> ngay.yyyy;

	if (ktNgayHopLe(ngay) == true) {
		l->ngayKg = ngay;
		return 1;
	}
	else {
		cout << "Ngay thang nam khong hop le!\n";
		return 0;
	}
		
}

void xuat1Lop(const Lop *l) {
	cout << "=================\n";
	cout << "Ma lop: " << l->maLop << endl;
	cout << "Ten lop: " << l->tenLop << endl;
	cout << "Ten khoa: " << l->tenKhoa << endl;
	cout << "So sv: " << l->soSv << endl;
	cout << "Ngay khai giang: " << l->ngayKg.dd << "/" << l->ngayKg.mm << "/" << l->ngayKg.yyyy << endl;
	cout << "==================\n";
}

//Cac ham cua DSL
void nhapTuFile(DSL &dsl, string fileName) {
	ifstream inFile(fileName);
	if (inFile.is_open()) {
		while (inFile.eof() == false) {
			Lop l;
			inFile.getline(l.maLop, 5, '#');
			inFile.getline(l.tenLop, 9, '#');
			getline(inFile, l.tenKhoa, '#');
			inFile >> l.soSv;
			inFile.ignore(1);
			NTN ngay;
			inFile >> ngay.dd;
			inFile.ignore(1);
			inFile >> ngay.mm;
			inFile.ignore(1);
			inFile >> ngay.yyyy;
			inFile.ignore(1);
			if (ktNgayHopLe(ngay) == true) {
				l.ngayKg = ngay;
				dsl.ds.push_back(l);
			}
			else {
				cout << "Ngay khong hop le!\n";
				break;
			}
		}

		inFile.close();
	}
}

void xuatDsLop(const DSL dsl) {
	for (int i = 0; i < dsl.ds.size(); i++) {
		xuat1Lop(&dsl.ds[i]);
	}
}

int tinhSlSv(const DSL dsl, const string tenKhoa) {
	int tong = 0;
	for (int i = 0; i < dsl.ds.size(); i++) {
		if (dsl.ds[i].tenKhoa == tenKhoa) {
			tong += dsl.ds[i].soSv;
		}
	}
	return tong;
}

void xoaLop(DSL &dsl, char *maLop){
	for (int i = 0; i < dsl.ds.size(); i++) {
		if (strcmp(dsl.ds[i].maLop, maLop)==0) {
			//Xoa tren mang 1 chieu, doi cac phan tu ben phai sang trai 1 o va giam n di 1
			//Xoa tren vector
			dsl.ds.erase(dsl.ds.begin()+i);
			break;//Co the dung lap vi ma lop trong DS la duy nhat
			//i = i-1;//Can xoa nhieu phan tu lien tiep
		}
	}
}

int main() {

	/*Lop *l1 = new Lop;
	if(nhap1Lop(l1)==1)
		xuat1Lop(l1);
	delete l1;*/
	DSL ds;
	nhapTuFile(ds, "DSLop.txt");
	xuatDsLop(ds);
	cout << "===============DS SAU KHI XOA==============\n";
	xoaLop(ds, (char*) "CB31");
	xuatDsLop(ds);

	system("pause");
	return 1;
}