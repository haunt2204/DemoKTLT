#include <iostream>
using namespace std;

//Tinh tong cac so nguyen
int tinhTong(int n, int tong=0) {
	//Basic case
	if (n == 0)
		return tong;

	//General case
	return tinhTong(n - 1, tong+n);
}


//Tinh tong binh phuong
int tinhTongBinhPhuong(int n, int tong=0) {
	//Basic case
	if (n == 0)
		return tong;

	//General case
	return tinhTongBinhPhuong(n - 1, tong+n*n);
}


//Tinh giai thua
int tinhGiaiThua(int n, int gt=1) {
	//Basic case
	if (n == 0)
		return gt;

	//General case
	return tinhGiaiThua(n - 1, gt*n);
}

//Tong giai thua
int tinhTongGiaiThua(int n, int tongGT = 0) {
	if (n == 0)
		return tongGT;

	return tinhTongGiaiThua(n - 1, tongGT + tinhGiaiThua(n));
}

//Fibo = 1,1,2,3,...,
int Fibo(int n) {
	if (n == 0 || n == 1)
		return 1;

	return Fibo(n - 2) + Fibo(n - 1);
}

//Tim UCLN giua hai so nguyen a, b
int timUCLN(int a, int b) {
	if (a == b)
		return a;//Hoac b
	
	if (a > b)
		return timUCLN(a - b, b);
	else
		return timUCLN(a, b - a);
}

//Tong cac phan tu trong mang 1 chieu
int tinhTongArr(int a[], int n, int tong = 0) {
	if (n == 0)
		return tong;
	return tinhTongArr(a, n - 1, tong+a[n-1]);
}

//Tim phan tu lon nhat trong mang 1 chieu
int timMax(int a[], int n) {
	//Basic case
	if (n == 1)
		return a[0];
	//General case
	int max = timMax(a, n - 1);
	if (max > a[n - 1])
		return max;
	return a[n - 1];
}

//Tam giac pascal
int tinhTGPascal(int i, int j) {
	if (j == 0 || i == j)
		return 1;
	return tinhTGPascal(i - 1, j - 1) + tinhTGPascal(i - 1, j);
}

//Thap Ha Noi
void chuyenDia(int n, char a, char b, char c) {
	if (n > 0) {
		chuyenDia(n - 1, a, c, b);
		cout << "Chuyen tu " << a << "=>" << c << endl;
		chuyenDia(n - 1, b, a, c);
	}
}

//In so dao nguoc
void inSoDaoNguoc(int n) {
	if (n > 0) {
		cout << n % 10;
		inSoDaoNguoc(n / 10);
	}
}

//Chuyen tu thap phan sang nhi phan
void inNhiPhan(int n) {
	if (n > 0) {
		inNhiPhan(n / 2);
		cout << n % 2;
	}
}

int main() {
	inNhiPhan(13);
	cout << endl;
	//int a[] = { 15,5,8,7,9,6,11 };//44
	//int n = sizeof(a) / sizeof(a[0]);
	//cout << "Tong mang: " << tinhTongArr(a, n) <<endl;
	//cout << "Tim phan tu lon nhat: " << timMax(a, n) << endl;
	/*int h;
	cout << "Nhap chieu cao tam giac: "; cin >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			cout << tinhTGPascal(i, j) << "\t";
		}
		cout << endl;
	}*/
	/*chuyenDia(3, 'A', 'B', 'C');*/
	/*cout << "Tinh tong: " << tinhTong(4) << endl;
	cout << "Tinh tong binh phuong: " << tinhTongBinhPhuong(3) << endl;
	cout << "Tinh giai thua: " << tinhGiaiThua(3) << endl;
	cout << "Fibo: " << Fibo(4) << endl;
	cout << "Tim UCLN: " << timUCLN(3,11) << endl;*/
	/*cout << "Tinh tong GT: " << tinhTongGiaiThua(4) << endl;*/

	system("pause");
	return 0;
}