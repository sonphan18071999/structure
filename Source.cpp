#include<stdio.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
/*Quản lý phiếu bạn đọc
1. Nhập phiếu
2. Thêm phiếu
3. Xóa phiếu
4. Xuất phiếu
5. Hình chỉnh phiếu
6.Tìm phiếu*/
typedef struct DATE
{
	int ngay;
	int thang;
	int nam;
};

typedef struct bill
{
	int mssv[20];
	string ten;
	string sl_sach;
	DATE ngay;
};
struct node
{
	bill data;
	struct node *pNext;
};
typedef struct node NODE;
struct list 
{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void khoitaodanhsach(LIST &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE *khoitaonode(bill x)
{
	NODE *p = new NODE;
	if (p == NULL)
	{
		cout << "\nCap phat that bai!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void Them_Dau(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void ThemCuoi(LIST &l, NODE *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Doc_Ngay_Thang_Nam(ifstream &filein,DATE date)
{
	filein >> date.ngay;
	filein.seekg(1, 1);
	filein >> date.thang;
	filein.seekg(1, 1);
	filein >> date.nam;
	filein.seekg(1, 1);
}
void Doc_Thong_Tin_1_Bill(ifstream &filein, bill &b)
{
	getline(filein, b.mssv, ",");
	filein.seekg(1, 1);
	getline(filein, b.ten, ",");
	filein.seekg(1, 1);
	Doc_Ngay_Thang_Nam(filein, b.ngay);
	filein.seekg(1, 1);
	getline(filein, b.sl_sach, ",");
	filein.seekg(1, 1);
	string temp;
	getline(filein, temp);
}
void Xuat(bill b)
{
	cout << "\nMssv:" << b.mssv;
	cout << "\nTen:" << b.ten;
	cout << "\nNgay" << b.ngay.ngay << "/" << b.ngay.thang << "/n" << b.ngay.nam;
	cout << "\nSo luong sach da muon:" << b.sl_sach;
}
void Doc_Danh_Sach_Sinh_Vien(ifstream &filein,LIST &l)
{
	while (!filein.eof())
	{
		DATE d;
		Doc_Thong_Tin_1_Bill(filein, d);
		NODE *p = khoitaonode(d);
		ThemCuoi(l, p);
	}
}
void Xuat_Danh_Sach_Sinh_Vien(LIST l)
{
	int dem = 1;
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "\n\n\t\t Sinh vien thu" << dem++;
		Xuat(k->data);
	}
}
void Giai_Phong_Vung_Nho(LIST &l);
void Hoan_Vi(bill &x, bill &y);
void Sap_Xep_Tang_Dan(LIST &l);
void Ghi_thong_tin_1_bill(ofstream &fileout, bill b);
void Luu_File_Sap_Xep_Tang_Dan_Diem_Trung_Binh(LIST &l);
using namespace std;
int main()
{	
	LIST l;
	khoitaodanhsach(l);
	bill d; // mo file len
	ifstream filein;
	filein.open("bill.txt", ios::in);
	Doc_Danh_Sach_Sinh_Vien(filein, l);
	Xuat_Danh_Sach_Sinh_Vien(l);

	Doc_Thong_Tin_1_Bill(filein, d);
	Xuat(d);


	Luu_File_Sap_Xep_Tang_Dan_Diem_Trung_Binh(l);
	Giai_Phong_Vung_Nho(l);
	filein.close();
	return 0;
}
void Giai_Phong_Vung_Nho(LIST &l)
{
	NODE *p = NULL;
	while (l.pHead != NULL)
	{
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void Hoan_Vi(bill &x, bill &y)
{
	bill tam = x;
	x = y;
	y = tam;
}
void Sap_Xep_Tang_Dan(LIST &l)
{
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		for (NODE *h = k->pNext; h != NULL; h = h->pNext)
		{
			if (k->data.ten < h->data.ten)
			{
				Hoan_Vi(k->data, h->data);
			}
		}
	}
}
void Ghi_thong_tin_1_bill(ofstream &fileout, bill b)
{
	fileout << bill.mssv << ",";
	fileout << bill.ten << ",";
	fileout << bill.date.ngay << "/" << bill.date.thang << "/" << bill.date.name << ".";

}
void Luu_File_Sap_Xep_Tang_Dan_Diem_Trung_Binh(LIST &l)
{
	ofstream fileout;
	fileout.open("bill.txt", ios::out);
	Sap_Xep_Tang_Dan(l);
	for (NODE *k = l.pHead; k != NULL; k = k->pNext)
	{
		Ghi_thong_tin_1_bill(fileout, k->data);
		fileout << endl;
	}
	fileout.close();

}
