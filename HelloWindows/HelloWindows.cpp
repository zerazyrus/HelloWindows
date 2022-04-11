#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<fstream>

using namespace std;

class HocSinh {
private:
    string Hoten;
    int Maso;
    int Sdt;
    float Dtb;
public:
    HocSinh();
    ~HocSinh();
    void Nhap();
    void Xuat();
    string getHoten();
    float getDTB();
};

class LopHoc {
private:
    vector<HocSinh*> A;
    int n;
public:
    LopHoc();
    ~LopHoc();
    void ThemHocSinh();
    void XoaHocSinh();
    void XuatHocSinh();
    void XuatHocSinhDTB8();
    void NhapTuTapTin();
};

HocSinh::HocSinh()
{
    Hoten = "";
    Maso = 0;
    Sdt = 0;
    Dtb = 0;
}

void HocSinh::Nhap()
{
    cin >> Hoten >> Maso >> Sdt >> Dtb;
}

void HocSinh::Xuat()
{
    cout << "Ho ten: " << Hoten << ", Ma so: " << Maso << ", So dien thoai: " << Sdt << ", Diem trung binh: " << Dtb << endl;
}

string HocSinh::getHoten()
{
    return Hoten;
}

float HocSinh::getDTB()
{
    return Dtb;
}

HocSinh::~HocSinh()
{

}

LopHoc::LopHoc()
{
    n = 0;
}

LopHoc::~LopHoc()
{

}

void LopHoc::ThemHocSinh()
{
    cout << "Nhap so luong hoc sinh: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap lan luot ho ten, ma so, so dien thoai va diem trung binh cua hoc sinh thu: "<<i+1<< endl;
        HocSinh* temp = new HocSinh();
        temp->Nhap();

        if (A.empty() == true) 
        {
            A.push_back(temp);
        }
        else 
        {
            for (HocSinh* j : A)
            {
                if (temp->getHoten() == j->getHoten())
                {
                    cout << "Da co hoc sinh trong lop" << endl;
                }
                else
                {
                    A.push_back(temp);
                }
            }
        }

        
    }
}

void LopHoc::XoaHocSinh()
{
    int count = 0;
    string temp;
    cout << "Nhap ten hoc sinh can xoa: ";
    cin >> temp;
    HocSinh* j = new HocSinh();

    for (int i = 0; i < A.size(); i++)
    {
        j = A[i];
        if (temp == j->getHoten())
        {
            A.erase(A.begin() + i);
            cout << "Xoa hoc sinh thanh cong" << endl;
        }
        else count = 1;;
    }

    if (count==1) cout << "Khong co hoc sinh trong lop" << endl;
}

void LopHoc::XuatHocSinh()
{
    for (HocSinh* k : A)
    {
        k->Xuat();
    }
}

void LopHoc::XuatHocSinhDTB8()
{
    for (HocSinh* k : A)
    {
        if (k->getDTB() > 8)
            k->Xuat();
    }
}

void LopHoc::NhapTuTapTin()
{
    fstream myFile;
    myFile.open("LopHoc.txt", fstream::in | fstream::app);
    myFile << "Text";

    myFile.close();
}

int main()
{
    LopHoc H;
    H.ThemHocSinh();
    H.XuatHocSinh();
    H.XoaHocSinh();
    H.XuatHocSinh();
    H.XuatHocSinhDTB8();
    H.NhapTuTapTin();
    return 0;
}

