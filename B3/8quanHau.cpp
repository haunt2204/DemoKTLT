#include <iostream>
using namespace std;

#define SIZE 8
int queens[SIZE] = { 0 };


void xuatKetQua() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (queens[i] == j)
				cout << "Q\t";
			else
				cout << "-\t";
		}
		cout << endl;
	}
}

bool checkViTri(int i, int j) {
	for (int k = 0; k < i; k++) {
		if (queens[k] == j || abs(k-i) == abs(queens[k] - j))
			return false;
	}
	return true;
}

void putQueen(int i) {
	for (int j = 0; j < SIZE; j++) {
		if (checkViTri(i, j)) {
			queens[i] = j;
			if (i == SIZE - 1) {
				xuatKetQua();
				char c;
				cout << "Nhap ky tu bat ky:";
				cin >> c;
			}	
			else
				putQueen(i + 1);
			queens[i] = 0;
		}
	}
}

int main() {
	putQueen(0);
	system("system");
	return 1;
}