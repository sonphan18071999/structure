// QLTV2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "cstring"
#include "iomanip"
#include "time.h"
#include "stdio.h"
#include "conio.h"
#include "windows.h"
using namespace std;


long total_book = 0;        // Tong sach cua thu vien.
long total_bill = 0;
long total = 0;
char ma_tam[50];
int i, p;
int info[10];


typedef struct Book {
	int masach;
	char tensach[30];
	char tacgia[30];
	char nxb[30];
	int namxb;
	int trangthai;
};
typedef struct PhieuMuon {
	char maphieu[8];
	char hoten[50];
	int slsach;
};
typedef struct CTPM {
	char hoten[50];
	int mssv;
	int masach;
	char tensach[50];
	char trachua;
};
typedef struct Booknode {
	Book info;
	Booknode *pnext;
};
typedef struct Phieunode {
	PhieuMuon info;
	Phieunode *pnext;
};

typedef struct list {
	Booknode *phead;
	Booknode *ptail;
};
typedef struct list1 {
	Phieunode *ahead;
	Phieunode *atail;
};

Booknode *getnode(Book &s);
int RemoveX(list &l, char key[30]);
void createList(list &l);
void AddHead(list &l, Booknode *p);
int RemoveHead(list &l);
void search_tacgia(list l, char tacgia_key[30]);
int RemoveAfterQ(list &l, Booknode *q);
void xuat(list l);
void selectionsort(list &L);


Phieunode *getnode1(PhieuMuon &s);
void phieu_load_file();
void phieu_save_file();
void phieu_nhap(PhieuMuon &a);
void phieu_xuat(list1 &a);
void nhapphieu(list1 &l, int n);
void addhead(list1 &l, Phieunode *p);
void addtail(list1 &l, Phieunode *p);
void createList1(list1 &l);
void phieu_hieu_chinh(list1 l, char key[30]);
void phieu_them(list1 &l, PhieuMuon &a);
int phieu_xoa(list1 &l);
int removeX(list1 &l, char key[30]);
int removeafterQ(list1 &l, Phieunode *q);

//-----------------------------------------------
void ctphieu_nhap();
void ctphieu_xuat();
void ctphieu_load_file();
void ctphieu_save_file();
//-----------------------------------------------
void sach_load_file();
void sach_save_file();
void sach_nhap(Book &a);
void nhap(list &l, int n);
void sach_xuat(list a);
int RemoveHead(list &l);
void AddTail(list &L, Booknode *p);
void search_tacgia(list l, char tacgia_key[30]);
int RemoveAfterQ(list &l, Booknode *q);
//-----------------------------------------------
void TK_theloai();
void TK_SV_qua_han();           // Sinh vien muon qua han.
void TK_tan_suat_muon();        // Tan suat muon cua moi cuon sach.
void TK_soluong_sach();
//-----------------------------------------------



void file_info();
void interface_main();
void interface_book_manager();
void interface_bill_manager();
void interface_bill_detail_manager();

void main()                                                                                 
{               
	interface_bill_manager();
}                                                                                       
																						
void interface_book_manager() {
begin:
	Book s;
	list l;
	Booknode *p;
	int x, chon;
	char key[30];
	createList(l);
	int n;
	cout << "nhap so luong sach:";
	cin >> n;
	nhap(l, n);
	system("cls");
	cout << endl << endl;
	cout << "               +-------------------------------------------------+ \n";
	cout << "               |      GIAO DIEN QUAN LY SACH TRONG THU VIEN      | \n";
	cout << "               |-------------------------------------------------| \n";
	cout << "               |  0. Nhap sach vao thu vien                      | \n";
	cout << "               |  1. Them 1 quyen sach vao dau danh sach         | \n";
	cout << "               |  2. Duyet danh sach                             | \n";
	cout << "               |  3. Xoa 1 Phan Tu dau Danh Sach                 | \n";
	cout << "               |  4. Xoa 1 quyen sach theo ten tac gia           | \n";
	cout << "               |  5. Seach 1 Quyen sach theo ten tac gia         | \n";
	cout << "               |  6. Sap xep sach trong thu vien theo ma sach    | \n";
	cout << "               |  7. Back.                                       | \n";
	cout << "               |                                                 | \n";
	cout << "               +-------------------------------------------------+ \n";

	
	

	scanf("%d", &chon);
	switch (chon)
	{
	case 1: {
		printf("\n\t Nhap Ma Sach(so): "); scanf("%d", &s.masach); fflush(stdin);
		printf("\n\t Nhap Ten Sach: "); scanf("%s", &s.tensach);
		printf("\n\t Nhap Ten Tac Gia: "); scanf("%s", &s.tacgia);
		printf("\n\t Nhap Ten NXB: "); scanf("%s", &s.nxb);
		printf("\n\t Nhap Nam Xuat Ban: "); scanf("%d", &s.namxb);
		printf("\n\t Trang Thai (0-Chua muon : 1-Da Muon): "); scanf("%d", &s.trangthai);
		p = getnode(s);
		AddHead(l, p);
		break;
	}
	case 2:
	{
		xuat(l);
		break;
	}
	case 3:
	{
		RemoveHead(l);
		cout << "\n\t Xoa Thanh Cong !!!";
		break;
	}
	case 4:
	{
		cout << "\n\t Nhap ten quyen sach can xoa : ";
		scanf("%s", &key);
		RemoveX(l, key);

		cout << "\n\t Xoa Thanh Cong !";
		break;
	}
	case 5:
	{
		cout << "\n\t Nhap Ten Tac Gia : "; fflush(stdin);
		scanf("%s", &key);
		search_tacgia(l, key);
		break;
	}
	case 6:
	{
		selectionsort(l);
	}
	}

	/*goto begin;
end:;*/
}

void interface_bill_manager() {
begin:
	PhieuMuon s;
	list1 l;
	Phieunode *p;
	int x, chon;
	createList1(l);

	int n;
	cout << "nhap so luong phieu:";
	cin >> n;
	nhapphieu(l, n);
	//system("cls");

	cout << endl << endl;
	cout << "               +-------------------------------------------------+ \n";
	cout << "               |      GIAO DIEN QUAN LY PHIEU MUON SACH          | \n";
	cout << "               |-------------------------------------------------| \n";
	cout << "               |                                                 | \n";
	cout << "               |  1. Them Phieu.                                 | \n";
	cout << "               |  2. Xoa Phieu.                                  | \n";
	cout << "               |                                                 | \n";
	cout << "               |  3. Xuat Phieu.                                 | \n";
	cout << "               |  4. Hieu chinh Phieu.                           | \n";
	cout << "               |  5. Tim Phieu.                                  | \n";
	cout << "               |                                                 | \n";
	cout << "               |  6. Back.                                       | \n";
	cout << "               |                                                 | \n";
	cout << "               +-------------------------------------------------+ \n";
	
	
	cin >> chon;
	switch (chon) {
	case 1: {
		//system("cls");
		phieu_them(l, s);
		phieu_xuat(l);
		break; }
	case 2: {
		char key[30];
		cin.ignore();
		cout << "nhap ma phieu can xoa:";
		cin.getline(key, 30);
		removeX(l, key);
		cout << "xoa thanh cong!";
		break; }
	case 3: {
		system("cls");
		phieu_xuat(l);
		break; }
	case 4: {
		system("cls");
		char key1[50];
		cin.getline(key1, 30);
		phieu_hieu_chinh(l, key1);
		break; }
		//case '5':

	case 6:
		//goto end;
		break;
	}
	/*goto begin;
end:;*/
}
//
//void interface_bill_detail_manager() {
//begin:
//	//system("cls");
//	cout << endl << endl;
//	cout << "               +-------------------------------------------------+ \n";
//	cout << "               |     GIAO DIEN QUAN LY CHI TIET PHIEU MUON       | \n";
//	cout << "               |-------------------------------------------------| \n";
//	cout << "               |                                                 | \n";
//	cout << "               |  1. Nhap Chi Tiet Phieu.                        | \n";
//	cout << "               |                                                 | \n";
//	cout << "               |  2. Xuat Chi Tiet Phieu.                        | \n";
//	cout << "               |                                                 | \n";
//	cout << "               |  3. Back.                                       | \n";
//	cout << "               |                                                 | \n";
//	cout << "               +-------------------------------------------------+ \n";
//
//	char chon;
//	bool k = true;
//
//	do
//	{
//		if (k == false)
//			cout << "Hay chon cong viec theo so tu 1 den 3 :";
//		else
//			cout << "Chon cong viec theo so: "; cin >> chon;
//		k = false;
//	} while ((chon < '1') || (chon > '3'));
//
//
//	switch (chon) {
//	case '1':   system("cls");
//		ctphieu_nhap();
//		break;
//	case '2':
//		system("cls");
//		ctphieu_xuat();
//		break;
//	case '3':
//		goto end;
//		break;
//	}
//	goto begin;
//end:;
//}
//
//void interface_main() {
//begin:
//	system("cls");
//	cout << endl << endl;
//	cout << "               +=================================================+ \n";
//	cout << "               |         CHUONG TRINH QUAN LY THU VIEN           | \n";
//	cout << "               |-------------------------------------------------| \n";
//	cout << "               |                                                 | \n";
//	cout << "               |  1. Quan ly sach trong Thu vien.                | \n";
//	cout << "               |  2. Quan ly phieu ban doc  .                    | \n";
//	cout << "               |  3. Quan ly Chi tiet phieu muon sach.           | \n";
//	cout << "               |                                                 | \n";
//	cout << "               |  4. Thong ke sach theo the loai.                | \n";
//	cout << "               |  5. Thong ke doc gia muon qua han               | \n";
//	cout << "               |                                                 | \n";
//	cout << "               |  6. Exit.                                       | \n";
//	cout << "               |                                                 | \n";
//	cout << "               +-------------------------------------------------+ \n";
//
//	char chon;
//	bool k = true;
//
//	do
//	{
//		if (k == false)
//			cout << "Hay chon cong viec theo so tu 1 den 3 :";
//		else
//			cout << "Chon cong viec theo so: "; cin >> chon;
//		k = false;
//	} while ((chon < '1') || (chon > '7'));
//
//
//
//	switch (chon) {
//	case '1':
//		system("cls");
//		interface_book_manager();
//		break;
//	case '2':
//		system("cls");
//		interface_bill_manager();
//		break;
//	case '3':
//		system("cls");
//		interface_bill_detail_manager();
//		break;
//	case '4':
//		system("cls");
//		TK_theloai();
//		break;
//	case '5':
//		system("cls");
//		TK_SV_qua_han();
//		break;
//	case '6':
//		goto end;
//		break;
//	}
//	goto begin;
//end:;
//}

//void file_info() {
//	FILE * f_b;
//	info[0] = total_book;
//	info[1] = total_bill;
//	info[2] = total;
//	f_b = fopen("file_info", "wb");
//	fwrite(info, sizeof(info), 1, f_b);
//	fclose(f_b);
//}
//void sach_load_file() {
//	FILE * f_b;
//	f_b = fopen("book_file", "rb");
//	fread(lst_book, sizeof(lst_book), 1, f_b);
//	fclose(f_b);
//}
//void sach_save_file() {
//	FILE * f_b;
//	f_b = fopen("book_file", "wb");
//	fwrite(lst_book, sizeof(lst_book), 1, f_b);
//	fclose(f_b);
//}
void nhap(list &l, int n)
{
	Book x[100];
	int i = 1;
	Booknode *p;
		for(int i=0;i<n;i++)
		{
			cout << "Nhap dau sach thu " << i << " :" << endl;
			sach_nhap(x[i]);
			p= getnode(x[i]);
			AddTail(l, p);
		}
}
void sach_nhap(Book &a)
{
	cout << "Nhap ma sach: ";
	cin >> a.masach;
	fflush(stdin);
	cout << "Nhap ten sach : ";
	cin.ignore();
	cin.getline(a.tensach, 30);
	cout << "Nhap ten tac gia cua sach: ";
	fflush(stdin);
	cin.ignore();
	cin.getline(a.tacgia, 50);
	fflush(stdin);
	cout << "Nhap ten nxb: ";
	cin.getline(a.nxb, 100);
	fflush(stdin);
	cout << "Nhap nam xuat ban:";
	cin >> a.namxb;
	fflush(stdin);
	cout << endl;
}




Booknode *getnode(Book &s)
{
	Booknode *p;
	p = new Booknode;
	if (p == NULL);
	p->info = s;
	p->pnext = NULL;
	return p;
}

void AddHead(list &l, Booknode *p)
{
	if (l.phead == NULL)
	{
		l.phead = p;
		l.ptail = l.phead;
	}
	else
	{
		p->pnext = l.phead;
		l.phead = p;
	}
}

void AddTail(list &L, Booknode *p)
{
	if (L.phead == NULL)
	{
		L.phead = L.ptail = p;
	}
	else
	{
		L.ptail->pnext = p;
		L.ptail = p;
	}
}
void createList(list &l)
{
	l.phead = NULL;
	l.ptail = NULL;
}


int RemoveX(list &l, char key[30])
{
	Booknode *p, *q = NULL;
	p = l.phead;
	if (p == NULL)
		return 0;
	while ((p != NULL) && (strcmp(p->info.tensach, key) != 0)) // nếu p!=NULL và khi chưa phải là khóa key thì tiếp tục tìm ;lưu ý rằng vòng lặp này đưa con trỏ q tới nút kế tiếp nút có khóa key
	{

		q = p;
		p = p->pnext;

	}
	if (strcmp(l.phead->info.tensach, key) == 0) // vì dử dụng hàm xóa 1 nút đằng sau nút q thì phải xét nội dung của nút đầu trứoc,nếu trùng với khóa key thì tiến hành xóa nút đầu
	{
		RemoveHead(l);
		return 1;
	}

	if (q != NULL) // còn nếu khác đồng thời phía trên tìm đc ví trí nút q thì tiến hnahf xóa nút kế tiếp nút q ,cũng chính là nút có khóa key
	{
		RemoveAfterQ(l, q);
	}
	else
		return 1;

}
int RemoveHead(list &l)
{
	Booknode *p;
	if (l.phead != NULL)
	{
		p = l.phead;
		l.phead = l.phead->pnext;
		delete p;
		if (l.phead == NULL)
			l.ptail = NULL;
		return 1;
	}
	return 0;
}
void search_tacgia(list l, char tacgia_key[30])
{
	Booknode *p;
	p = l.phead;
	while (p != NULL)
	{
		if (strcmp(p->info.tacgia, tacgia_key) == 0)
		{
			cout << "\n Ma Sach: " << p->info.masach;
			cout << "\n Ten Sach: " << p->info.tensach;
			cout << "\n Tac Gia: " << p->info.tacgia;
			cout << "\n NXB: " << p->info.nxb;
			cout << "\n Nam XB: " << p->info.namxb;
			cout << "\n Trang Thai: " << p->info.trangthai;
		}
		p = p->pnext;
	}
}
int RemoveAfterQ(list &l, Booknode *q)
{
	if (q != NULL&& q->pnext != NULL)
	{

		Booknode *p = q->pnext;
		q->pnext = p->pnext;
		if (p == l.ptail)
			l.ptail = q;

		delete p;
		return 1;

	}
	else
		return 0;
}
void xuat(list l)
{
	int i = 1;
	Booknode *R = l.phead;
	cout << "\n";
	if (R == NULL)
		cout << "\n\t Danh sach trong !";
	else
	{
		while (R != NULL)
		{
			cout << "\n ------------------------------------------";
			cout << "\n | Sach thu: " << i++ << "                             |";
			cout << "\n ------------------------------------------";
			cout << "\n Ma Sach: " << R->info.masach;
			cout << "\n Ten Sach: " << R->info.tensach;
			cout << "\n Tac Gia: " << R->info.tacgia;
			cout << "\n Nha Xuat Ban: " << R->info.nxb;
			cout << "\n Nam Xuat Ban: " << R->info.namxb;
			cout << "\n Trang Thai (0-Chua muon : 1-Da muon): " << R->info.trangthai;
			R = R->pnext;
			cout << "\n ------------------------------------------";
		}
	}
}
void selectionsort(list &L)
{
	Booknode *p, *q, *min;
	p = L.phead;
	Book temp;
	while (p != L.ptail)
	{
		min = p;
		q = p->pnext;
		while (q != NULL)
		{
			if (q->info.masach<min->info.masach)  min = q;
			q = q->pnext;
		}
		temp = p->info;
		p->info = min->info;
		min->info = temp;
		p = p->pnext;
	}
	xuat(L);
}

//QUAN LI PHIEU MUON
void phieu_nhap(PhieuMuon &a)
{
	Phieunode *p;
	cin.ignore();
	cout << "Ma Phieu:";
	cin.getline(a.maphieu, 8);
	cout << "Ho ten:";
	cin.getline(a.hoten, 50);
	cout << "so luong sach muon:";
	cin >> a.slsach;
}

void nhapphieu(list1 &l, int n)
{
	PhieuMuon x[100];
	int i = 1;
	Phieunode *p;
	for (int i = 0; i<n; i++)
	{
		cout << "Phieu muon thu " << i << " :" << endl;
		phieu_nhap(x[i]);
		p = getnode1(x[i]);
		addtail(l, p);
	}
}
void phieu_xuat(list1 &a)
{
	int i = 0;
	Phieunode *p = a.ahead;
	cout << "\n";
	if (p == NULL)
		cout << "\n\t Danh sach trong !";
	else
	{
		while (p != NULL)
		{
			cout << "phieu thu" << i++ << ":"<<endl;
			cout << "Ma Phieu:" << p->info.maphieu << endl;
			cout << "Ho Ten:" << p->info.hoten << endl;
			cout << "So luong sach:" << p->info.slsach << endl;
			p = p->pnext;
		}
	}
}
void createList1(list1 &l)
{
	l.ahead = NULL;
	l.atail = NULL;
}
void addtail(list1 &l, Phieunode *p)
{
	if (l.ahead == NULL)
	{
		l.ahead = l.atail = p;
	}
	else
	{
		l.atail->pnext = p;
		l.atail = p;
	}
}
Phieunode *getnode1(PhieuMuon &s)
{
	Phieunode *p;
	p = new Phieunode;
	if (p == NULL);
	p->info = s;
	p->pnext = NULL;
	return p;
}
void addhead(list1 &l, Phieunode *a)
{
	if (l.ahead == NULL) {
		l.ahead = a;
		l.atail = l.ahead;
	}
	else {
		a->pnext = l.ahead;
		l.ahead = a;
	}
}
void phieu_them(list1 &l,PhieuMuon &a)
{
	Phieunode *p;
	cin.ignore();
	cout << "Ma Phieu:";
	cin.getline(a.maphieu, 8);
	cout << "Ho ten:";
	cin.getline(a.hoten, 50);
	cout << "so luong sach muon:";
	cin >> a.slsach;
	p = getnode1(a);
	addhead(l,p);
}
int removeafterQ(list1 &l, Phieunode *q)
{
	if (q != NULL&& q->pnext != NULL)
	{

		Phieunode *p = q->pnext;
		q->pnext = p->pnext;
		if (p == l.atail)
			l.atail = q;

		delete p;	
		return 1;

	}
	else
		return 0;
}
int phieu_xoa(list1 &l)
{
	Phieunode *p;
	if (l.ahead != NULL)
	{
		p = l.ahead;
		l.ahead = l.ahead->pnext;
		delete p;
		if (l.ahead == NULL)
			l.atail = NULL;
		return 1;
	}
	return 0;
}
int removeX(list1 &l, char key[30])
{
	Phieunode *p, *q = NULL;
	p = l.ahead;
	if (p == NULL)
		return 0;
	while ((p != NULL) && (strcmp(p->info.maphieu, key) != 0)) // nếu p!=NULL và khi chưa phải là khóa key thì tiếp tục tìm ;lưu ý rằng vòng lặp này đưa con trỏ q tới nút kế tiếp nút có khóa key
	{

		q = p;
		p = p->pnext;

	}
	if (strcmp(l.ahead->info.maphieu, key) == 0) // vì dử dụng hàm xóa 1 nút đằng sau nút q thì phải xét nội dung của nút đầu trứoc,nếu trùng với khóa key thì tiến hành xóa nút đầu
	{
		phieu_xoa(l);
		return 1;
	}

	if (q != NULL) // còn nếu khác đồng thời phía trên tìm đc ví trí nút q thì tiến hnahf xóa nút kế tiếp nút q ,cũng chính là nút có khóa key
	{
		removeafterQ(l, q);
	}
	else
		return 1;

}
void phieu_hieu_chinh(list1 l, char key[30])
{
	Phieunode *p;
	PhieuMuon a;
	p = l.ahead;
		cout << "nhap ma phieu can hieu chinh!";
		cin >> key;
		while ((p != NULL))
		{
			if (strcmp(p->info.maphieu, key) == 0) {
				removeX(l, key);
				cin.ignore();
				cout << "Ma Phieu:";
				cin.getline(a.maphieu, 8);
				cout << "Ho ten:";
				cin.getline(a.hoten, 50);
				cout << "so luong sach muon:";
				cin >> a.slsach;
				p = getnode1(a);
				addhead(l, p);
			}
			p = p->pnext;
		}
		phieu_xuat(l);

}