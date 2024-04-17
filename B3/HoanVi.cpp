#include <iostream>
using namespace std;

int *a;//Mang ket qua
int *p;//Dung danh dau 1 phan tu trong tap hop da duoc chon hay chua (1: chon roi)
int n;//k = n

void xuatKetQua() {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
//Tap hop = {1,2,3}
void hoanVi(int i) {
	for (int j = 1; j <= n; j++) {
		if (p[j] == 0) {
			a[i] = j;
			p[j] = 1;
			if (i == n - 1)
				xuatKetQua();
			else
				hoanVi(i + 1);
			p[j] = 0;//Phuc hoi de tim ket qua moi
		}
	}
}

int main() {
	cout << "Nhap n: ";
	cin >> n;
	a = new int[n];
	p = new int[n+1];

	for (int i = 0; i < n+1; i++) {
		p[i] = 0;//Khoi tao ban dau tat ca phan tu chua duoc chon
	}

	hoanVi(0);

	delete[]p;
	delete[]a;
	system("pause");
	return 1;
}