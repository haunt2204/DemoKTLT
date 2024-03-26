//Tim UCLN cua 2 so nguyen a, b
#include <iostream>
using namespace std;


int main() {
	int *pa = NULL, *pb = NULL;

	pa = new int;
	pb = new int;

	cout << "Nhap a, b: "; 
	cin >> *pa;
	cin >> *pb;

	while (*pa != *pb) {
		if (*pa > *pb)
			*pa = *pa - *pb;
		else
			*pb = *pb - *pa;
	}

	cout << "UCLN cua a va b: " << *pa << endl;

	delete pa;
	delete pb;

	system("pause");
	return 1;
}