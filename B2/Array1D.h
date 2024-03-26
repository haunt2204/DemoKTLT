#include <iostream>
#include <ctime>
using namespace std;

void init(int *&a, int n) {
	a = new int[n];
}

void freeArr(int *&a) {
	delete[] a;
	a = nullptr;
}

void inputArrOld(int *&a, int &n) {
	do {
		cout << "Nhap so luong phan tu: "; cin >> n;
		if (n <= 0)
			cout << "Nhap lai so phan tu!\n";
	} while (n <= 0);
	init(a, n);
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << "a[" << i << "] = ";
			cin >> a[i];
		}
	}
}

void outputArr(int *a, int n) {
	if (a != NULL) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << "\t";
		}
		cout << endl;
	}
}

void pushBackArr(int *&a, int &n, int x) {
	//Co 2 truong hop co the xay ra
	//Mang a dang rong
	if (a == NULL) {
		n = 1;
		init(a, n);
		if (a != NULL) {
			a[n - 1] = x;//a[0] = x
		}
		return;
	}
	//Mang a da co n phan tu 
	int *oldArr = a;
	init(a, n + 1);
	if (a != NULL) {
		for (int i = 0; i < n; i++)
			a[i] = oldArr[i];

		a[n] = x;//Gan gia tri cho phan thu n+1 vao mang a
		n++;
	}
	freeArr(oldArr);
}

void inputArr(int *&a, int &n) {
	int x;
	cout << "Nhap x: ";
	while (cin >> x) {
		pushBackArr(a, n, x);
		cout << "Nhap x: ";
	}
}

void genArrRand(int *&a, int &n) {
	do {
		cout << "Nhap so luong phan tu: "; cin >> n;
		if (n <= 0)
			cout << "Nhap lai so phan tu!\n";
	} while (n <= 0);
	init(a, n);
	if(a!=NULL)
		for (int i = 0; i < n; i++) {
			a[i] = rand() % 100 + 1;
		}
}

void swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

void sortArr(int *a, int n) {
	if (a != NULL) {
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (a[j] < a[i])
					swap(a[i], a[j]);
	}
}

void reverseArr(int *a, int n) {
	if (a != NULL) {
		int l = 0, r = n - 1;
		while (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
}

int* concateArr(int *a, int n, int *b, int m) {
	int *c;
	init(c, n + m);
	if (c != NULL) {
		int dem = 0;
		for (int i = 0; i < n; i++)
			c[dem++] = a[i];
		for (int i = 0; i < m; i++)
			c[dem++] = b[i];
	}
	return c;
}

int* findMax(int *a, int n) {
	if (a != NULL) {
		int iMax = 0;
		for (int i = 1; i < n; i++)
			if (a[i] > a[iMax])
				iMax = i;
		return &a[iMax];
	}
	return NULL;
}