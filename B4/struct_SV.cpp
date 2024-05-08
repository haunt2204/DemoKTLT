#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

struct SinhVien {
    long maHV;
    char hoTen[50];
    string queQuan;
    char ngaySinh[11];
    double diem[3];
};

void xuat1SV(SinhVien sv){
    cout << "====================\n";
    cout << sv.maHV <<endl;
    cout << sv.hoTen <<endl;
    cout << sv.queQuan <<endl;
    cout << sv.ngaySinh <<endl;
    for(int i=0; i<3; i++){
        cout << sv.diem[i] << " ";
    }
    cout << "\n====================\n";
}

SinhVien* timKiemSV(SinhVien ds[], int n, long maHV){
    SinhVien *kqTimKiem = nullptr;
    for(int i=0; i<n;i++){
        if(ds[i].maHV==maHV)
            kqTimKiem=&ds[i];
    }

    return kqTimKiem;
}

void xuatDSSV(const SinhVien ds[], const int n){
    for(int i=0; i<n;i++){
        xuat1SV(ds[i]);
    }
}

int cmpWithIdAsc(SinhVien *ds, int n, int i, int j){
    return (int) (ds[i].maHV-ds[j].maHV);
}

int cmpWithIdDesc(SinhVien *ds, int n, int i, int j){
    return (int) -(ds[i].maHV-ds[j].maHV);
}

int cmpWithAddressAsc(SinhVien *ds, int n, int i, int j){
    if(ds[i].queQuan>ds[j].queQuan)
        return 1;
    if(ds[i].queQuan<ds[j].queQuan)
        return -1;
    return 0;
}

int cmpWithNameAsc(SinhVien *ds, int n, int i, int j){
    return strcmp(ds[i].hoTen, ds[j].hoTen);
}

void sapXep(SinhVien ds[], const int n, int comparator(SinhVien*, int, int, int)=cmpWithIdAsc){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(comparator(ds, n, i, j)>0){
                SinhVien s = ds[i];
                ds[i] = ds[j];
                ds[j] = s;
            }
        }
    }
}

int main(){
//    SinhVien *sv = new SinhVien;
    SinhVien ds[10];
    int n = 0;//Phan tu hien co trong mang
    ifstream inFile;
    inFile.open("data_sv.txt");
    if(inFile.is_open()){
        while(inFile.eof()==false){
            SinhVien sv;
            inFile>>sv.maHV;
            inFile.ignore(1);
            inFile.getline(sv.hoTen, 50, '\n');
            getline(inFile, sv.queQuan, '\n');
            inFile.getline(sv.ngaySinh, 11, '\n');
            
            for(int i=0; i<3; i++){
                inFile>>sv.diem[i];
            }
            ds[n++] = sv;
        }
        

        cout <<"=====TIM KIEM=====\n";
        long tmp = 2151010003;
        
        SinhVien kq = *timKiemSV(ds, n, tmp);
        
        xuat1SV(kq);
        
        cout <<"=====SAP XEP=====\n";
        sapXep(ds, n, cmpWithNameAsc);
        xuatDSSV(ds, n);
        inFile.close();
    }
//    delete sv;
    return 1;
}
