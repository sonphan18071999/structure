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
	int sl;
};
struct n_DATE {
	int n_day;
	int n_month;
	int n_year;
};
typedef struct PhieuMuon {
	char maphieu[10];
	char masv[8];
	char hoten[50];
	n_DATE bill_ngaymuon;
};
typedef struct CTPM {
	char hoten[50];
	int mssv;
	int masach;
	char tensach[50];
	char trachua[50];
};

typedef struct Booknode {
	Book info;
	Booknode *pnext;
};
typedef struct Phieunode {
	PhieuMuon info;
	Phieunode *pnext;
};
typedef struct CTPMnode {
	CTPM info;
	CTPMnode *pnext;
};

typedef struct list {
	Booknode *phead;
	Booknode *ptail;
};
typedef struct list1 {
	Phieunode *ahead;
	Phieunode *atail;
};
typedef struct list2 {
	CTPMnode *bheah;
	CTPMnode *btail;
};

typedef Book LIST_BOOK[100];                    // Kieu LIST_BOOK la mang 100 cuon sach.
typedef PhieuMuon LIST_BILL[100];                    // Kieu LIST_BILL la mang 100 phieu muon.
typedef CTPM LIST_DETAIL[100];
LIST_BOOK lst_book;             // Bien lst_book la mang 50 cuon sach.
LIST_BILL lst_bill;             // Bien lst_bill la mang 50 phieu muon.
LIST_DETAIL lst_detail;         // Bien lst_detail la mang 50 chi tiet phieu muon.

//--------------------------------------------------

Phieunode *getnode1(PhieuMuon &s);
void phieu_load_file();
void phieu_save_file();
void phieu_nhap(PhieuMuon &a);
void phieu_xuat(list1 &a);
void nhapphieu(list1 &l);
void addhead(list1 &l, Phieunode *p);
void addtail(list1 &l, Phieunode *p);
void createList1(list1 &l);
void phieu_hieu_chinh(list1 l, char key[30]);
void phieu_them(list1 &l, PhieuMuon &a);
int phieu_xoa(list1 &l);
int removeX(list1 &l, char key[30]);
int removeAfterQ(list1 &l, Phieunode *q, char key[30]);
void tim_phieu(list1 &l, char key[50]);
int timphieu(list1 &l, char key[50]);

//-----------------------------------------------
CTPMnode *getnode2(CTPM &s);
void ctphieu_nhap();
void ctphieu_xuat();
void ctphieu_load_file();
void ctphieu_save_file();
//-----------------------------------------------
Booknode *getnode(Book &s);
int RemoveX(list &l, char key[30]);
void createList(list &l);
void AddHead(list &l, Booknode *p);
void AddTail(list &L, Booknode *p);
int RemoveHead(list &l);
void search_tacgia(list l, char tacgia_key[30]);
void sach_nhap(Book &a);
void xuat(list l);
void selectionsort(list &L);
int sach_tim(list &l,int key);
void sach_load_file();
void sach_save_file();
void nhap(list &l);
int RemoveHead(list &l);

void search_tacgia(list l, char tacgia_key[30]);
int RemoveAfterQ(list &l, Booknode *q, char key[30]);

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
	interface_book_manager();
	//interface_bill_manager();
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
	nhap(l);
	system("cls");
	cout << endl << endl;
	cout << "               +-------------------------------------------------+ \n";
	cout << "               |      GIAO DIEN QUAN LY SACH TRONG THU VIEN      | \n";
	cout << "               |-------------------------------------------------| \n";
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
		printf("\n\t Nhap SLS: "); scanf("%d", &s.sl);
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
		Sleep(1000);
		
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
void nhap(list &l)
{
	int i = 1;
	Booknode *p;
	

	cout << "Hay nhap tong so luong sach  : ";
	cin >> total_book;
	cout << endl;

	for (int i = 1; i <= total_book; i++) {
	nhap_ma:;
		cin.ignore();
		cout << ". Ma Sach: ";
		cin>>lst_book[i].masach;
		if (sach_tim(l, lst_book[i].masach) != 0) {
			cout << "   Ma Sach nay da ton tai. Hay nhap lai!";
			goto nhap_ma;
		}
		//cin.ignore();

		cout << "Sach thu " << i << " :" << endl;
		sach_nhap(lst_book[i]);
		p = getnode(lst_book[i]);
		AddTail(l, p);
	}
}
void sach_nhap(Book &a)
{
	fflush(stdin);
	cin.ignore();
	cout << "Nhap ten sach : ";
	cin.ignore();
	//fflush(stdin);
	cin.getline(a.tensach, 30);
	cout << "Nhap ten tac gia cua sach: ";
	//fflush(stdin);
	cin.ignore();
	cin.getline(a.tacgia, 50);
	//fflush(stdin);
	cout << "Nhap ten nxb: ";
	cin.getline(a.nxb, 100);
	//fflush(stdin);
	cout << "Nhap nam xuat ban:";
	cin >> a.namxb;
	cout << "SLS:";
	cin >> a.sl;
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
	Booknode *p, *q = NULL; p = l.phead;
	while ((p != NULL) && strcmp(p->info.tacgia, key) == 0) // while((p!=NULL)&&strcmp(p->info.tensach,key)!=0) ; nếu ko thì ngay khi bắt đầu nếu != từ khóa là out khỏi vòng lặp luôn rồi
	{
		q = p;
		p = p->pnext;
	}
	if (p == NULL)
		return 0;

	if (q != NULL)
		RemoveAfterQ(l, q, key); // hàm này là hàm xóa một nút đằng sau nút q ko phải là xóa nút q và cũng ko nhất thiết cần đưa khóa key vào
	else
		RemoveHead(l);
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
			cout << "\n SLS: " << p->info.sl;
		}
		p = p->pnext;
	}
}
int sach_tim(list &l, int key)
{
	Booknode *p;
	Booknode a;
	p = l.phead;
	while (p != NULL)
	{
		if (p->info.masach == key) {
			return 1;
		}
		p = p->pnext;
	}
	return 0;
}
int RemoveAfterQ(list &l, Booknode *q, char key[30])
{
	Booknode *p;
	if (q != NULL)
	{
		p = q->pnext;
		if (p != NULL)
		{
			if (p == l.ptail)
				l.ptail = q;
			q->pnext = p->pnext;
			delete p;
		}
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
			cout << "\n SLS: " << R->info.sl;
			R = R->pnext;
			cout << "\n ------------------------------------------";
		}
	}
}
void selectionsort(list &L)
{
	Booknode *p, *q, *min;
	p = L.phead;
    lst_book[i];
	while (p != L.ptail)
	{
		min = p;
		q = p->pnext;
		while (q != NULL)
		{
			if (q->info.masach < min->info.masach)  min = q;
			q = q->pnext;
		}
		lst_book[i] = p->info;
		p->info = min->info;
		min->info = lst_book[i];
		p = p->pnext;
	}
	xuat(L);
	
}

//----------------------------QUAN LI PHIEU MUON-----------------------------


void interface_bill_manager() {
begin:
	PhieuMuon s;
	list1 l;
	Phieunode *p;
	int x, chon;
	createList1(l);

	
	nhapphieu(l);
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
		removeX(l,key);
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
	case 5: {
		char x1[50];
		cout << "nhap phieu can tim:";
		cin >> x1;
		tim_phieu(l, x1);
		break;
	}

	case 6:
		//goto end;
		break;
	}
	/*goto begin;
	end:;*/
}

void phieu_nhap(PhieuMuon &a)
{

	Phieunode *p;
	//cin.ignore();
	cout << "Ma SV:";
	cin.getline(a.masv, 8);
	//cin.ignore();
	cout << "Ho ten:";
	cin.getline(a.hoten, 50);
	cout << ". Ngay Muon     : \n";
	cout << " Ngay "; cin >> a.bill_ngaymuon.n_day;
	cout << " thang: "; cin >> a.bill_ngaymuon.n_month;
	cout << " nam: "; cin >> a.bill_ngaymuon.n_year;
	cout << endl;
}
void nhapphieu(list1 &l)
{
	
	int i = 1;
	Phieunode *p;
	char ma_tam[50];

	cout << "Day la lan dang ki phieu muon dau tien. \n";
	cout << "Hay nhap tong so luong phieu muon se duoc dang ki : "; 
	cin >> total_bill;
	cout << endl;

	for (int i = 1; i <= total_bill; i++) {
	nhap_ma:;
		cin.ignore();
		cout << ". Ma Phieu: ";
		cin.getline(lst_bill[i].maphieu, 50);
		if (timphieu(l,lst_bill[i].maphieu) != 0) {
			cout << "   Ma Phieu nay da ton tai. Hay nhap lai!";
			goto nhap_ma;
		}
		//cin.ignore();
		
		cout << "Phieu muon thu " << i << " :" << endl;
		phieu_nhap(lst_bill[i]);
		p = getnode1(lst_bill[i]);
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
			cout << "phieu thu" << i++ << ":" << endl;
			cout << "Ma SV:" << p->info.masv << endl;
			cout << "Ho Ten:" << p->info.hoten << endl;
			cout << ". Ngay Muon     : \n";
			cout << " \tNgay " << p	->info.bill_ngaymuon.n_day;
			cout << " \tThang: " << p->info.bill_ngaymuon.n_month;
			cout << " \tNam: " << p->info.bill_ngaymuon.n_year;
			cout << endl;
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
nhap_ma:;
	cin.ignore();
	cout << ". Ma Phieu: ";
	cin.getline(lst_bill[i].maphieu, 50);
	if (timphieu(l, lst_bill[i].maphieu) != 0) {
		cout << "   Ma Phieu nay da ton tai. Hay nhap lai!";
		goto nhap_ma;
	}
	//cin.ignore();
	strcpy(lst_bill[i].masv, ma_tam);
	cout << "Phieu muon thu " << i << " :" << endl;
	phieu_nhap(lst_bill[i]);
	p = getnode1(lst_bill[i]);
	addtail(l, p);
}
int removeAfterQ(list1 &l, Phieunode *q, char key[30])
{
	Phieunode *p;
	if (q != NULL)
	{
		p = q->pnext;
		if (p != NULL)
		{
			if (p == l.atail)
				l.atail = q;
			q->pnext = p->pnext;
			delete p;
		}
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
	Phieunode *p, *q = NULL; p = l.ahead;
	while ((p != NULL) && strcmp(p->info.maphieu, key) == 0)
	{
		q = p;
		p = p->pnext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
		removeAfterQ(l, q, key);
	else
		phieu_xoa(l);
	return 1;
}
void phieu_hieu_chinh(list1 l, char key[30])
{
	Phieunode *p;
	PhieuMuon a;
	p = l.ahead;
	//cin.ignore();
	cout << "nhap ma phieu can hieu chinh!";
	cin.getline( lst_bill[i].maphieu,10);
	while ((p != NULL))
	{
		if (timphieu(l, lst_bill[i].maphieu) == 1) {
			removeX(l, key);
			phieu_nhap(lst_bill[i]);
			p = getnode1(lst_bill[i]);
			addhead(l, p);
			break;
		}
		p = p->pnext;
	}
	phieu_xuat(l);

}
void tim_phieu(list1 &l, char key[50])
{
	Phieunode *p;
	Phieunode a;
	p = l.ahead;
	while (p != NULL )
	{
		if (strcmp(p->info.maphieu, key) == 0) {
			cout << "Ma SV:" << p->info.masv << endl;
			cout << "Ho ten:" << p->info.hoten << endl;
			cout << ". Ngay Muon     : \n";
			cout << " \tNgay " << p->info.bill_ngaymuon.n_day;
			cout << " \tThang: " << p->info.bill_ngaymuon.n_month;
			cout << " \tNam: " << p->info.bill_ngaymuon.n_year;
			cout << endl;
		}
		p = p->pnext;
	}
}
int timphieu(list1 &l, char key[50])
{
	Phieunode *p;
	Phieunode a;
	p = l.ahead;
	while (p != NULL)
	{
		if (strcmp(p->info.maphieu, key) == 0) {
			return 1;
		}
		p = p->pnext;
	}
	return 0;
}


//-----------------------------Chi Tiet Phieu Muon----------------------------
CTPMnode *getnode2(CTPM &a)
{
	CTPMnode *p;
	p = new CTPMnode;
	if (p == NULL);
	p->info = a;
	p->pnext = NULL;
	return p;

}
void Createlist2(list2 &l)
{
	l.bheah = NULL;
	l.btail = NULL;
}
void AddHead(list2 &l, CTPMnode *p)
{
	if (p == NULL)
		l.bheah = l.btail = p;
	else {
		p->pnext = l.bheah;
		l.bheah = p;
	}
}
void ctphieu_nhap()
{
	CTPM x[100];
	list1 l;
	Phieunode *p;
	list s;
	Booknode *q;
	Book a[100];
	char sach_ma_tam[50];
	char phieu_ma_tam[50];
	char t;
	int total_tam;

muon:;
	cin.ignore();
	cout << ". So sach se muon : "; 
	cin >> total_tam;

	if (total + total_tam > 5) {
		cout << "- Ban chi co the muon toi da 5 cuon. \n";
		cout << "  Ban duoc phep muon them  " << 5 - total << "  cuon nua.";
		goto muon;
	}

	for (int i = 1; i <= total_tam; i++) {
		cin.ignore(1);
		cout << endl;
		cout << ". Nhap ma phieu : "; 
		cin.getline(phieu_ma_tam, 50);

		if (timphieu(l,phieu_ma_tam) == 0) {
			cout << "- Khong tim thay phieu muon cua ban.";
			break;
		}

	nhap_ma_sach:;
		int key;
		cin.ignore(1);
		cout << ". Nhap ma sach : "; 
		cin>>key;
		t = sach_tim(s, key);
		if (t == 0) {
			cout << ". Khong tim thay sach ban can.";
			cout << "  Ban muon muon sach khac (y/n) : "; 
			cin >> t;
			if (t == 'y' || t == 'Y')
				goto nhap_ma_sach;
			else
				break;
		}
		cin.ignore(1);
		cout << ". Tra / Chua : ";
		cin.getline(x[i].trachua, 50);

		if (strcmp(x[i].trachua, "chua") == 0)
			a[i].sl = a[i].sl - 1;
		else
			a[i].sl = a[i].sl + 1;
	}
}
//void ctphieu_xuat() {
//
//	CTPM *p;
//	char phieu_ma_tam[50];
//	//char t;
//	p = 0;
//
//	cin.ignore(1);
//	cout << ". Nhap ma phieu : ";
//	cin.getline(phieu_ma_tam, 50);
//	while (p != NULL)
//	{
//		if()
//	}
//}