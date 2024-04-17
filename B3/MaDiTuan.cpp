#include <iostream>
using namespace std;

#define SIZE 8
int a[SIZE][SIZE] = { 0 };
int dd[] = {-2,-1,1,2,2,1,-1,-2};
int dc[] = {1,2,2,1,-1,-2,-2,-1};

void xuatKetQua() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void nuocDi(int n, int vtDong, int vtCot) {
	for (int i = 0; i < 8; i++) {
		int dmoi = vtDong + dd[i];
		int cmoi = vtCot + dc[i];
		if (dmoi >= 0 && dmoi < SIZE && cmoi >= 0 && cmoi < SIZE&&a[dmoi][cmoi] == 0) {
			a[dmoi][cmoi] = n;
			if (n == SIZE*SIZE) {
				xuatKetQua();
				char c;
				cout << "Nhap ky tu bat ky de tiep tuc: "; cin >> c;
			}
			else
				nuocDi(n + 1, dmoi, cmoi);
			a[dmoi][cmoi] = 0;
		}
	}
}

int main() {
	a[0][0] = 1;
	nuocDi(2, 0, 0);
	system("pause");
	return 1;
}