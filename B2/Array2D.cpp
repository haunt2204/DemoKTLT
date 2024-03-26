#include <iostream>
using namespace std;

void nhapMang(int **&a, int &r, int &c) {
	do {
		cout << "Nhap dong: "; cin >> r;
		cout << "Nhap cot: "; cin >> c;
		if (r <= 0 || c <= 0)
			cout << "Nhap lai r va c!\n";
	} while (r <= 0 || c <= 0);
	a = new int*[r];
	for (int i = 0; i < r; i++) {
		a[i] = new int[c];
	}

	if (a != NULL) {
		for (int i = 0; i < r; i++) {
			//cout << "Nhap dong " << i << ": ";
			for (int j = 0; j < c; j++) {
				a[i][j] = rand()%100+1;
			}
		}
	}
}

void xuatMang(int **a, int r, int c) {
	if (a != NULL) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
	}
}

//Cac thao tac tren mang 2 chieu
//Tinh tong so nguyen to tren ma tran

bool isNguyenTo(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return false;
	return true;
}

int tinhTongNT(int **a, int r, int c) {
	int tong = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (isNguyenTo(a[i][j]))
				tong += a[i][j];
		}
	}

	return tong;
}

//Dem so luong cuc tri
bool isCucTri(int **a, int r, int c, int vtDong, int vtCot) {//Kiem tra lai
	bool max = true, min = true;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (vtDong + i >= 0 && vtDong + i < r && vtCot + j >= 0 && vtCot + j < c && !(i == 0 && j == 0)) {
				if (a[vtDong][vtCot] < a[vtDong + i][vtCot + j])
					max = false;
				if (a[vtDong][vtCot] > a[vtDong + i][vtCot + j])
					min = false;
			}
			if (max == false && min == false)
				break;
		}
	}
	if (max == false && min == false)
		return false;
	return true;
}

int demCucTri(int **a, int r, int c) {
	int count = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (isCucTri(a, r, c, i, j))
				count++;
		}
	}
	return count;
}


int main() {
	int **a = NULL, r, c;
	nhapMang(a, r, c);
	xuatMang(a, r, c);

	cout << "SL cuc tri la: " << demCucTri(a, r, c) << endl;
	cout << "Tong nguyen to: " << tinhTongNT(a, r, c) << endl;


	for (int i = 0; i < r; i++) {
		delete[] a[i];
		a[i] = nullptr;
	}
	delete[]a;
	a = nullptr;
	system("pause");
	return 1;
}