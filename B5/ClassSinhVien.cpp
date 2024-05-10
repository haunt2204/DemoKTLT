#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

#define SOMH 3

//Cac ham cua kieu SinhVien
class SinhVien {
private:
    long long mssv;
    char hoVaTen[50];
    char maLop[9];
    char ngaySinh[11];
    string queQuan;
    double diem[SOMH];
    
public:
    //constructor
    SinhVien(){
        
    }
    //constructor
    SinhVien(long long id, char *ht, char *ml, char *ns, string qq, double *d){
        mssv = id;
        strcpy(hoVaTen, ht);
        strcpy(maLop, ml);
        strcpy(ngaySinh,ns);
        queQuan = qq;
        for(int i=0; i<SOMH; i++){
            diem[i] = d[i];
        }
    }
    char* getMaLop(){
        return maLop;
    }
    long long getMssv(){
        return mssv;
    }
    string getQueQuan(){
        return queQuan;
    }
    void nhap1SV();
    void xuat1SV();
    double calAverage();
};

void SinhVien::nhap1SV(){
    cout << "Nhap MSSV: ";
    cin >> mssv;
    cin.ignore(1);
    cout << "Nhap ho ten: ";
    cin.getline(hoVaTen, 50);
    cout << "Nhap ma lop: ";
    cin >> maLop;
    cout << "Nhap ngay sinh: ";
    cin >> ngaySinh;
    cin.ignore(1);
    cout << "Nhap que quan: ";
    getline(cin, queQuan);
    cout << "Nhap 3 cot diem: ";
    for (int i = 0; i < SOMH; i++) {
        cin >> diem[i];
    }
}

double SinhVien::calAverage(){
    double tong = 0;
    for(int i=0; i<SOMH; i++)
        tong+=diem[i];
    return tong/SOMH;
}

void SinhVien::xuat1SV(){
    cout << "============================\n";
    cout << "MSSV: " << mssv << endl;
    cout << "Ho va ten: " << hoVaTen << endl;
    cout << "Ma lop: " << maLop << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Que quan: " << queQuan << endl;
    cout << "Diem: ";
    for (int i = 0; i < SOMH; i++) {
        cout << diem[i] << " ";
    }
    cout << "\nDiem TB: " << calAverage() << endl;
    cout << "============================\n";
}

//Ham dung chung
void swap(SinhVien &sv1, SinhVien &sv2) {
    SinhVien tmp = sv1;
    sv1 = sv2;
    sv2 = tmp;
}

int cmpWithAddressAsc(SinhVien sv1, SinhVien sv2) {
    if (sv1.getQueQuan() < sv2.getQueQuan())
        return 1;
    if (sv1.getQueQuan() > sv2.getQueQuan())
        return -1;
    return 0;
}

//Cac ham cua kieu DSSV
class DSSV {
private:
    SinhVien *ds;
    int n;
    
public:
    //constructor
    DSSV(){
        
    }
    //destructor
    ~DSSV();
    void nhapDsSv();
    void nhapDsSvTuFile();
    void xuatDsSv();
    int statByClass(char *className);
    void sapXep(int comparator(SinhVien, SinhVien));
    void xoaSV(long long mssv);
};

void DSSV::nhapDsSv(){
    do {
        cout << "Nhap so luong SV: "; //n
        cin >> n;
        if (n <= 0 || n > 50)
            cout << "Nhap lai!\n";
    } while (n <= 0 || n > 50);
    
    ds = new SinhVien[n];
    
    for (int i = 0; i < n; i++) {
        ds[i].nhap1SV();
    }
}

void DSSV::xuatDsSv(){
    for (int i = 0; i < n; i++) {
        ds[i].xuat1SV();
    }
}

int DSSV::statByClass(char *className){
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].getMaLop(),className)==0)
            count++;
    }
    return count;
}

void DSSV::nhapDsSvTuFile(){
    ifstream myFile;
    myFile.open("data_sv_2.txt");
    if (myFile.is_open()) {
        myFile >> n;
            //Cap phat
        ds = new SinhVien[n];
        
        for (int i = 0; i < n; i++) {
            long long mssv;
            char hoVaTen[50];
            char maLop[9];
            string queQuan;
            char ngaySinh[11];
            double diem[3];
            
            
            myFile >> mssv;
            myFile.ignore(1);
            myFile.getline(hoVaTen, 50);
            myFile >> maLop;
            myFile.ignore(1);
            getline(myFile, queQuan);
            myFile >> ngaySinh;
            for (int j = 0; j < SOMH; j++) {
                myFile >> diem[j];
            }
            
            SinhVien sv(mssv, hoVaTen, maLop, ngaySinh, queQuan, diem);
            ds[i] = sv;
        }
        myFile.close();
    }
}

void DSSV::sapXep(int comparator(SinhVien, SinhVien)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (comparator(ds[i], ds[j])<0) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

void DSSV::xoaSV(long long id) {
    for (int i = 0; i < n; i++) {
        if (ds[i].getMssv() == id) {
            for (int j = i; j < n - 1; j++) {
                ds[j] = ds[j + 1];
            }
            n--;
        }
    }
}

//destructor
DSSV::~DSSV(){
    delete []ds;
    ds = NULL;
}

int main(){
    DSSV ds;
//    ds.nhapDsSv();
    ds.nhapDsSvTuFile();
    ds.sapXep(cmpWithAddressAsc);
    ds.xuatDsSv();
//    cout << "Thong ke SV thuoc lop DH23CS01: " << ds.statByClass("DH23CS01") << endl;
    return 1;
}
