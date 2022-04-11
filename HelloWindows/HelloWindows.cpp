#include<iostream>
#include<vector>
#include<string>
#include<math.h>

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
};

class LopHoc {
private:
    vector<HocSinh*> A;
    int n;
public:
    LopHoc();
    ~LopHoc();
    void ThemHocSinh();
    void XuatHocSinh();
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
        HocSinh* temp1 = new HocSinh();
        temp->Nhap();

        for (int j = 0; j < A.size(); j++)
        {
            temp1 = A[j];
            if (temp->getHoten() == temp1->getHoten())
            {
                cout << "Da co hoc sinh trong lop";
            }
            else
            {
                A.push_back(temp);
                cout << "1";
            }
        }
    }
}

void LopHoc::XuatHocSinh()
{
    for (HocSinh* k : A)
    {
        k->Xuat();
    }
}

int main()
{
    LopHoc H;
    H.ThemHocSinh();
    H.XuatHocSinh();
    return 0;
}

