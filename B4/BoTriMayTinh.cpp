#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int *a;//Luu 1 ket qua
int *p;//Danh dau 1 ptu da duoc chon
int n;
string *kh;
int *nhuCau; //Nhu cau cua tung khach hang
int *khaNang; //Kha nang phuc vu cua tung may tinh

void show(){
    ofstream outFile("data_net_OUT.txt",ios::app);
    if (outFile.is_open()) {
        for(int i=0; i<n; i++){
            outFile << kh[i] << "-MT"<< a[i] << " ";
        }
        outFile << endl;
        outFile.close();
    }
}

void hoanVi(int i){
    for(int j=1; j<n+1; j++){
        if(p[j]==0 && nhuCau[i]<=khaNang[j-1]){//&& nhuCau[i]<=khaNang[j-1]
            a[i] = j;
            p[j] = 1;
            if(i==n-1){
                show();
//                bool flag = true;
//                for(int k=0; k<n; k++){
//                    if(nhuCau[k]>khaNang[a[k]-1])
//                        flag = false;
//                }
//                if(flag)
//                    show();
            }else
                hoanVi(i+1);
            p[j] = 0;
        }
    }
}

int main(){
    ifstream myFile("data_net.txt");
    if(myFile.is_open()){
        myFile>>n;
        a = new int[n];
        p = new int[n+1];
        kh = new string[n];
        nhuCau = new int[n];
        khaNang = new int[n];
        
        for(int i=0; i<n+1; i++)
            p[i] = 0;
        
        //Doc ten khach hang tu tap tin
        for(int i=0; i<n; i++){
            myFile>>kh[i];
        }
        
        //Doc nhu cau cua tung khach hang
        for(int i=0; i<n; i++){
            myFile>>nhuCau[i];
        }
        
        //Doc kha nang cua tung may tinh
        for(int i=0; i<n; i++){
            myFile>>khaNang[i];
        }
        
        hoanVi(0);
        
        delete [] khaNang;
        delete [] nhuCau;
        delete [] kh;
        delete [] a;
        delete [] p;
        myFile.close();
    }
    return 0;
}
