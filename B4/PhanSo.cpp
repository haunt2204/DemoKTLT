#include <iostream>
using namespace std;

class PhanSo {
private:
    int tuSo, mauSo;
    
public:
    PhanSo(int a, int b){
        tuSo = a;
        mauSo = b;
    }
    PhanSo(){
        
    }
    ~PhanSo(){
        
    }
    int getTuSo(){
        return tuSo;
    }
    int getMauSo();
    void setTuSo(int ts);
    void setMauSo(int ms);
    PhanSo tinhTich(PhanSo ps);
    void hienThi(){
        cout << tuSo << "/" << mauSo << endl;
    }
    PhanSo tinhThuong(PhanSo ps){
        PhanSo kq;
        
        int ts = tuSo*ps.getMauSo();
        int ms = mauSo*ps.getTuSo();
        
        kq.setTuSo(ts);
        kq.setMauSo(ms);
        
        return kq;
    }
    PhanSo tinhHieu(PhanSo ps){
        PhanSo kq;
        
        int ts = tuSo*ps.getMauSo()-ps.tuSo*mauSo;
        int ms = mauSo*ps.getMauSo();
        
        kq.setTuSo(ts);
        kq.setMauSo(ms);
        
        return kq;
    }
};

int PhanSo::getMauSo(){
    return mauSo;
}

void PhanSo::setTuSo(int ts){
    tuSo = ts;
}

void PhanSo::setMauSo(int ms){
    mauSo = ms;
}

PhanSo PhanSo::tinhTich(PhanSo ps){
    PhanSo kq;
    
    int ts = ps.getTuSo()*tuSo;
    int ms = ps.getMauSo()*mauSo;
    
    kq.setTuSo(ts);
    kq.setMauSo(ms);
    
    return kq;
}

int main(){
    
    PhanSo ps1(1,2);
    ps1.hienThi();
    
    PhanSo ps2(2,3);
    ps2.hienThi();
    
    PhanSo kq = ps1.tinhHieu(ps2);
    kq.hienThi();
    
    return 1;
}
