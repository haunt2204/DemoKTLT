#include <iostream>
using namespace std;
#define MAX 50


//Tinh tong theo dieu kien
int calArr(const int a[], int n, bool func(int x)) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if (func(a[i]))
			tong += a[i];
	}

	return tong;
}

bool isDuong(int n) {
	//if (n >= 0) return true;
	//return false;
	return n >= 0 ? true : false;
}

bool isAm(int n) {
	//return !isDuong(n);
	return n < 0 ? true : false;
}

bool isNguyenTo(int n) {
	if (n < 2) return false;
	else if (n > 2) {
		if (n % 2 == 0) return false;
		for (int i = 3; i <= sqrt(n); i++)
			if (n%i == 0) return false;
	}
	return true;
}

bool isChinhPhuong(int n) {
	//Cach 1
	/*int i = 1;
	while (i*i <= n) {
		if (i*i == n) return true;
		i++;
	}
	return false;*/
	//Cach 2
	int tam = sqrt(n);
	return tam*tam == n ? true : false;
	
}

int main() {
	int a[] = { 5,9,7,-5,2,-3,8,1,6,4 };
	int n = sizeof(a) / sizeof(a[0]);

	int result = calArr(a, n, isDuong);
	cout << "Tong cac so duong: " << result << endl;
	cout << "Tong cac so am: " << calArr(a, n, isAm) << endl;
	cout << "Tong cac so nguyen to: " << calArr(a, n, isNguyenTo) << endl;
	cout << "Tong cac so chinh phuong: " << calArr(a, n, isChinhPhuong) << endl;

	system("pause");
	return 1;
}