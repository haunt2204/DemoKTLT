#include <iostream>
#include <ctime>
using namespace std;

#define MAXROW 100
#define MAXCOL 50

void nhapMang(int a[MAXROW][MAXCOL], int& r, int& c);
void xuatMang(const int a[MAXROW][MAXCOL], int r, int c);
void sinhMaTranNN(int a[MAXROW][MAXCOL], int& r, int& c);
void sinhMaTranNN2(int a[MAXROW][MAXCOL], int r, int c);
int tinhTongHang(const int a[MAXROW][MAXCOL], int r, int c, int vtHang);
int tinhTongCot(const int a[MAXROW][MAXCOL], int r, int c, int vtCot);
void nhapHangCot(int& r, int& c);
void tinh2MaTran(const int a[MAXROW][MAXCOL], const int b[MAXROW][MAXCOL], 
	int result[MAXROW][MAXCOL], int r, int c, int phepTinh(int x, int y));

int cong(int a, int b) {
	return a + b;
}

int nhan(int a, int b) {
	return a * b;
}

int main() {
	int a[MAXROW][MAXCOL] = {{ 0 }};
	int b[MAXROW][MAXCOL] = { { 0 } };
	int result[MAXROW][MAXCOL] = { { 0 } };
	int r, c, chon, vtHang, vtCot;
	bool flag = false;
	do {
		cout << "===========BAI THUC HANH 1================\n";
		cout << "1. Nhap mang\n";
		cout << "2. Xuat mang\n";
		cout << "3. Sinh mang ngau nhien\n";
		cout << "4. Tinh tong dong\n";
		cout << "5. Tinh tong cot\n";
		cout << "6. Sinh mang ngau nhien\n";
		cout << "7. Tinh tong 2 ma tran\n";
		cout << "8. Tinh tich 2 ma tran\n";
		cout << "0. Thoat!\n";
		cin >> chon;
		system("cls");
		switch (chon)
		{
		case 1:
			nhapMang(a, r, c); 
			flag = true;
			break;
		case 2:
			if (flag == true)
				xuatMang(a, r, c);
			else
				cout << "Vui long nhap mang!\n";
			break;
		case 3:
			sinhMaTranNN(a, r, c); 
			flag = true;
			break;
		case 4:
			if (flag == true) {
				cout << "Nhap hang can tinh: "; cin >> vtHang;
				cout << "Tong hang " << vtHang << " la: " << tinhTongHang(a, r, c, vtHang-1);
			}
			else
				cout << "Vui long nhap mang!\n";
			break;
		case 7:
			srand((int)time(NULL));
			nhapHangCot(r, c);
			//Sinh ma tran a
			sinhMaTranNN2(a, r, c);
			cout << "==============Mang a: \n";
			xuatMang(a, r, c);
			//Sinh ma tran b;
			sinhMaTranNN2(b, r, c);
			cout << "==============Mang b: \n";
			xuatMang(b, r, c);
			//Tinh tong a + b
			tinh2MaTran(a, b,result, r, c, cong);
			cout << "==============Mang a + b: \n";
			xuatMang(result, r, c);
			break;
		case 8:
			srand((int)time(NULL));
			nhapHangCot(r, c);
			//Sinh ma tran a
			sinhMaTranNN2(a, r, c);
			cout << "==============Mang a: \n";
			xuatMang(a, r, c);
			//Sinh ma tran b;
			sinhMaTranNN2(b, r, c);
			cout << "==============Mang b: \n";
			xuatMang(b, r, c);
			//Tinh tich a * b
			tinh2MaTran(a, b, result, r, c, nhan);
			cout << "==============Mang a * b: \n";
			xuatMang(result, r, c);
			break;
		default:;
			break;
		}
	} while (chon != 0);
	
	system("pause");
	return 1;
}

void nhapHangCot(int& r, int& c) {
	do {
		cout << "Nhap so hang: "; cin >> r;
		cout << "Nhap so cot: "; cin >> c;
		if (r <= 0 || r > MAXROW || c <= 0 || c > MAXCOL)
			cout << "Nhap sai, nhap lai di!\n";
	} while (r <= 0 || r>MAXROW || c <= 0 || c>MAXCOL);
}

void nhapMang(int a[MAXROW][MAXCOL], int& r, int& c) {
	nhapHangCot(r, c);

	for (int i = 0; i < r; i++) {
		cout << "Nhap dong thu " << i + 1 << ": ";
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
}

void xuatMang(const int a[MAXROW][MAXCOL], int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void sinhMaTranNN(int a[MAXROW][MAXCOL], int& r, int& c) {
	srand((int) time(NULL));
	nhapHangCot(r, c);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand()%100+1;//1-100
		}
	}
}

void sinhMaTranNN2(int a[MAXROW][MAXCOL], int r, int c) {
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			a[i][j] = rand() % 10 + 1;//1-100
		}
	}
}


int tinhTongHang(const int a[MAXROW][MAXCOL], int r, int c, int vtHang) {
	int tong = 0;
	for (int j = 0; j < c; j++) {
		tong += a[vtHang][j];
	}

	return tong;
}

int tinhTongCot(const int a[MAXROW][MAXCOL], int r, int c, int vtCot) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		tong += a[i][vtCot];
	}

	return tong;
}

void tinh2MaTran(const int a[MAXROW][MAXCOL], const int b[MAXROW][MAXCOL],
	int result[MAXROW][MAXCOL], int r, int c, int phepTinh(int x, int y)) 
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			result[i][j] = phepTinh(a[i][j], b[i][j]);
		}
	}
}