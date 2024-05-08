#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define SOMH 3

class SinhVien {
private:
    long maHV;
    char hoTen[50];
    string queQuan;
    char ngaySinh[11];
    double diem[3];
public:
    void setMaHV(long id){
        maHV = id;
    }
    void setHoTen(char *ht){
        strcpy(hoTen, ht);
    }
    void setQueQuan(string q){
        queQuan = q;
    }
    void setNgaySinh(char *ns){
        strcpy(ngaySinh, ns);
    }
    void setDiem(double *d){
        for(int i=0; i<SOMH; i++)
            diem[i] = d[i];
    }
    
    void show(){
        cout << "====================\n";
        cout << maHV <<endl;
        cout << hoTen <<endl;
        cout << queQuan <<endl;
        cout << ngaySinh <<endl;
        for(int i=0; i<SOMH; i++){
            cout << diem[i] << " ";
        }
        cout << "\n====================\n";
    }
};


int main(){
    ifstream inFile;
    inFile.open("data_sv.txt");
    if(inFile.is_open()){
        while(inFile.eof()==false){
            long maHV;
            char hoTen[50];
            string queQuan;
            char ngaySinh[11];
            double diem[SOMH];
            
            SinhVien sv;
            inFile>>maHV;
            sv.setMaHV(maHV);
            inFile.ignore(1);
            inFile.getline(hoTen, 50, '\n');
            sv.setHoTen(hoTen);
            getline(inFile, queQuan, '\n');
            sv.setQueQuan(queQuan);
            inFile.getline(ngaySinh, 11, '\n');
            sv.setNgaySinh(ngaySinh);
            
            for(int i=0; i<3; i++){
                inFile>>diem[i];
            }
            sv.setDiem(diem);
            
            sv.show();
        }
        inFile.close();
    }
    return 1;
}
