//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#define SOMH 3

//Dinh nghia
struct SinhVien
{
    long long mssv;
    char hoVaTen[50];
    char maLop[9];
    char ngaySinh[11];
    string queQuan;
    double diem[SOMH];
};

struct DSSV
{
    SinhVien *ds;
    int n;
};

//Cac ham cua SV
void nhap1Sv(SinhVien &sv) {
    cout << "Nhap MSSV: ";
    cin >> sv.mssv;
    cin.ignore(1);
    cout << "Nhap ho ten: ";
    cin.getline(sv.hoVaTen, 50);
    cout << "Nhap ma lop: ";
    cin >> sv.maLop;
    cout << "Nhap ngay sinh: ";
    cin >> sv.ngaySinh;
    cin.ignore(1);
    cout << "Nhap que quan: ";
    getline(cin, sv.queQuan);
    cout << "Nhap 3 cot diem: ";
    for (int i = 0; i < SOMH; i++) {
        cin >> sv.diem[i];
    }
}

double calAverage(const SinhVien sv) {
    double diem = 0;
    for (int i = 0; i < SOMH; i++) {
        diem += sv.diem[i];
    }
    return diem / SOMH;
}

bool isHocBong(const SinhVien sv){
    if(calAverage(sv)>=8.0)
        return true;
    return false;
}

void xuat1Sv(const SinhVien sv) {
    cout << "============================\n";
    cout << "MSSV: " << sv.mssv << endl;
    cout << "Ho va ten: " << sv.hoVaTen << endl;
    cout << "Ma lop: " << sv.maLop << endl;
    cout << "Ngay sinh: " << sv.ngaySinh << endl;
    cout << "Que quan: " << sv.queQuan << endl;
    cout << "Diem: ";
    for (int i = 0; i < SOMH; i++) {
        cout << sv.diem[i] << " ";
    }
    cout << "\nDiem TB: " << calAverage(sv) << endl;
    cout << "============================\n";
}

void update(SinhVien &sv) {
    //...Vi du nguoi dung cap nhat ngay sinh
    char nsMoi[11];
    cout << "Nhap ngay sinh moi: ";
    cin >> nsMoi;
    strcpy(sv.ngaySinh,nsMoi);
}

//Cac ham cua DSSV
void nhapDsSv(DSSV &mh) {
    do {
        cout << "Nhap so luong SV: "; //n
        cin >> mh.n;
        if (mh.n <= 0 || mh.n > 50)
            cout << "Nhap lai!\n";
    } while (mh.n <= 0 || mh.n > 50);
    
    mh.ds = new SinhVien[mh.n];
    
    for (int i = 0; i < mh.n; i++) {
        nhap1Sv(mh.ds[i]);
    }
}

void nhapDsSvTuFile(DSSV &mh) {
    ifstream myFile;
    myFile.open("data_sv_2.txt");
    if (myFile.is_open()) {
        myFile >> mh.n;
            //Cap phat
        mh.ds = new SinhVien[mh.n];
        
        for (int i = 0; i < mh.n; i++) {
            myFile >> mh.ds[i].mssv;
            myFile.ignore(1);
            myFile.getline(mh.ds[i].hoVaTen, 50);
            myFile >> mh.ds[i].maLop;
            myFile.ignore(1);
            getline(myFile, mh.ds[i].queQuan);
            myFile >> mh.ds[i].ngaySinh;
            for (int j = 0; j < SOMH; j++) {
                myFile >> mh.ds[i].diem[j];
            }
        }
        myFile.close();
    }
}

void huyDsSv(DSSV &mh) {
    delete[]mh.ds;
    mh.ds = NULL;
}

void xuatDsSv(const DSSV mh) {
    for (int i = 0; i < mh.n; i++) {
        xuat1Sv(mh.ds[i]);
    }
}

int statByClass(const DSSV mh, char *className) {
    int count = 0;
    for (int i = 0; i < mh.n; i++) {
        if (strcmp(mh.ds[i].maLop,className)==0)
            count++;
    }
    return count;
}

int statByAverage(const DSSV mh, double avg) {
    int count = 0;
    for (int i = 0; i < mh.n; i++) {
        if (calAverage(mh.ds[i])>=avg)
            count++;
    }
    return count;
}

void swap(SinhVien &sv1, SinhVien &sv2) {
    SinhVien tmp = sv1;
    sv1 = sv2;
    sv2 = tmp;
}

int cmpWithAverageDesc(const SinhVien sv1, const SinhVien sv2) {
    if (calAverage(sv1) > calAverage(sv2))
        return 1;
    if (calAverage(sv1) < calAverage(sv2))
        return -1;
    return 0;
}

int cmpWithAverageAsc(const SinhVien sv1, const SinhVien sv2) {
    return -cmpWithAverageDesc(sv1, sv2);
}

int cmpWithIdDesc(const SinhVien sv1, const SinhVien sv2) {
    return (int) (sv1.mssv - sv2.mssv);
}

int cmpWithIdAsc(const SinhVien sv1, const SinhVien sv2) {
    return (int) (sv2.mssv - sv1.mssv);
}

int cmpWithAddress(const SinhVien sv1, const SinhVien sv2) {
    if (sv1.queQuan > sv2.queQuan)
        return 1;
    if (sv1.queQuan < sv2.queQuan)
        return -1;
    return 0;
}

int cpmWithClass(const SinhVien sv1, const SinhVien sv2) {
    return strcmp(sv1.maLop, sv2.maLop);
}

void sapXep(DSSV mh, int comparator(SinhVien, SinhVien)) {
    for (int i = 0; i < mh.n - 1; i++) {
        for (int j = i + 1; j < mh.n; j++) {
            if (comparator(mh.ds[i], mh.ds[j])<0) {
                swap(mh.ds[i], mh.ds[j]);
            }
        }
    }
}

void xoaSV(DSSV &mh, long long id) {
    for (int i = 0; i < mh.n; i++) {
        if (mh.ds[i].mssv == id) {
            for (int j = i; j < mh.n - 1; j++) {
                mh.ds[j] = mh.ds[j + 1];
            }
            mh.n--;
        }
    }
}

void themSV(DSSV &mh, SinhVien svMoi) {
    if (mh.ds == NULL) {
        mh.n = 1;
        mh.ds = new SinhVien[mh.n];
        mh.ds[0] = svMoi;
    }
    else
        {
        SinhVien *tam = mh.ds;
        mh.ds = new SinhVien[mh.n + 1];
        for (int i=0; i < mh.n; i++) {
            mh.ds[i] = tam[i];
        }
        mh.ds[mh.n++] = svMoi;
        
        delete[] tam;
        }
}

void xuatDsSvHb(const DSSV mh){
    vector<SinhVien> res;
    ofstream myFile("SV_HB.txt");
    if(myFile.is_open()){
        for(int i=0; i<mh.n; i++){
            if(isHocBong(mh.ds[i])==true){
                res.push_back(mh.ds[i]);

            }
        }
        myFile << res.size() << endl;
        for(int i=0; i<res.size(); i++){
            myFile << res[i].mssv << "#";
            myFile << res[i].hoVaTen << "#";
            myFile << res[i].maLop << "#";
            myFile << calAverage(res[i]) << endl;
        }
        myFile.close();
    }
}

int main() {    
    DSSV mh1;
    mh1.ds = NULL;
    mh1.n = 0;
    
    nhapDsSvTuFile(mh1);
//    xuatDsSv(mh1);
//    sapXep(mh1, cmpWithIdDesc);
    cout << "===SV DAT HOC BONG===\n";
    xuatDsSvHb(mh1);
    huyDsSv(mh1);
    system("pause");
    return 1;
}
