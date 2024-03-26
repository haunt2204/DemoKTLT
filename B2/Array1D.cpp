#include "Array1D.h"


int main() {
	int *a = NULL, n, *b = NULL, m;
	int *c = NULL;
	srand((int)time(NULL));
	genArrRand(a, n);
	outputArr(a, n);
	genArrRand(b, m);
	outputArr(b, m);
	c = concateArr(a, n, b, m);
	outputArr(c, m+n);
	/*outputArr(a, n);
	sortArr(a, n);
	outputArr(a, n);
	reverseArr(a, n);
	outputArr(a, n);*/
	/*inputArr(a, n);*/
	//Them phan thu thu n+1
	/*pushBackArr(a, n, 8);*/
	freeArr(c);
	freeArr(b);
	freeArr(a);
	system("pause");
	return 1;
}