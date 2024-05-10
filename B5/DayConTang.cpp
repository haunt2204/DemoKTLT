#include <iostream>
#include <fstream>
using namespace std;

int *a, *L, *T;

void readData(int &n){
    ifstream myFile("INCEQ.INP");//Dong 1: n, Dong 2: n so nguyen
    if(myFile.is_open()){
        
        myFile>>n;
        a = new int[n+2];
        L = new int[n+2];
        T = new int[n+2];
        a[0] = INT_MIN;
        a[n+1] = INT_MAX;
        for(int i=1; i<=n; i++){
            myFile>>a[i];
        }
        myFile.close();
    }
}

void buildSolutionLIS(int n){
    L[n+1] = 1;
    for(int i = n; i>=0; i--){
        int jmax = n+1;
        for(int j=i+1; j<=n+1; j++){
            if(a[i]<a[j]&&L[j]>L[jmax])
                jmax = j;
        }
        L[i] = L[jmax] + 1;
        T[i] = jmax;
    }
}

void trace(int n){
    ofstream myFile("INCEQ.OUT");
    if(myFile.is_open()){
        int i = T[0];
        while(i<n+1){
            myFile << a[i] << " ";
            i = T[i];
        }
        myFile.close();
    }
}

int main(){
    int n;
    readData(n);
    buildSolutionLIS(n);
    trace(n);
    delete [] L;
    delete [] T;
    delete [] a;
    return 0;
}
