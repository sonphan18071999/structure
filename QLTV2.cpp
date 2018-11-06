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
int i, p1;
int info[10];


typedef struct Book {
	int masach;
	char tensach[30];
	char tacgia[30];
	char nxb[30];
	int namxb;
	int sl;
	char theloai[50];
};
struct n_DATE {
	int n_day;
	int n_month;
	int n_year;
};
typedef struct PhieuMuon {
	//char maphieu[10];
	char masv[8];
	char hoten[50];
	n_DATE bill_ngaymuon;
};
typedef struct CTPM {
	char hoten[50];
	char masv[8];
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
	CTPMnode *bhead;
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
void phieu_hieu_chinh(list1 l, char key[30]);
void phieu_them(list1 &l, PhieuMuon &a);
int removeHead(list1 &l);
int removeX(list1 &l, char key[30]);
int removeAfterQ(list1 &l, Phieunode *q);
void tim_phieu(list1 &l, char key[50]);
void createList1(list1 &l);
int timtensach(char ma_tam[]);


//-----------------------------------------------
CTPMnode *getnode2(CTPM &s);
void Createlist2(list2 &l);
int phieu_tim(char ma_tam[]);
void ctphieu_nhap(list2 &l);
void ctphieu_xuat(list2 l);
void addTail(list2 &l, CTPMnode *p);
void addHead(list2 &l, CTPMnode *p);
void ctphieu_load_file();
void ctphieu_save_file();


//-----------------------------------------------
Booknode *getnode(Book &s);
void nhap(list &l);
void sach_nhap(Book &a);
void createList(list &l);
void AddHead(list &l, Booknode *p);
void AddTail(list &L, Booknode *p);
void search_tacgia(list &l, char tacgia_key[30]);
void sach_nhap(Book &a);
void xuat(list l);
void selectionsort(list &L);
int sach_tim(int ma_tam);
int RemoveX(list &l, char key[30]);
int RemoveHead(list &l);
int RemoveAfterQ(list &l, Booknode *q);
void themsach(list &l);
void sach_load_file();
void sach_save_file();

//-----------------------------------------------
void theloai(list l);
void TK_SV_qua_han(list1 &l);          
int days_in_month(int md, int dd);       
//-----------------------------------------------



void file_info();
void interface_main();
void interface_book_manager();
void interface_bill_manager();
void interface_bill_detail_manager();

void main()                                                                                 
{               
	interface_main();
}                                                                                       
																						
void interface_book_manager() {

	Book s;
	list l;
	Booknode *p;
	int x, chon;
	char key[30];
	createList(l);
	int n;
	nhap(l);
begin:
	//system("cls");
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
	cout << "               |  7. Thong ke sach trong thu vien theo the loai  | \n";
	cout << "               |  8. Back.                                       | \n";
	cout << "               |                                                 | \n";
	cout << "               +-------------------------------------------------+ \n";

	
	

	scanf("%d", &chon);
	switch (chon)
	{
	case 1: {
		themsach(l);
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
		xuat(l);
		break;
	}
	case 4:
	{
		cout << "\n\t Nhap ten quyen sach can xoa : ";
		scanf("%s", &key);
		int t=RemoveX(l, key);
		if (t == 1) {
			cout << "xoa thanh cong!";
			xuat(l);
		}
		else cout << "khong tim thay!";
		
		
		break;
	}
	case 5:
	{
		char key1[30];
		cout << "nhap ten tac gia:";
		cin.ignore();
		cin.getline(key1, 30);
		search_tacgia(l, key1);
		break;
	}
	case 6:
	{
		selectionsort(l);
	}
	case 7: {
		theloai(l);
		break;
	}
	case 8:
	{
		goto end;
	}
	}

	goto begin;
end:;
}





void file_info() {
	FILE * f_b;
	info[0] = total_book;
	info[1] = total_bill;
	info[2] = total;
	f_b = fopen("file_info", "wb");
	fwrite(info, sizeof(info), 1, f_b);
	fclose(f_b);
}
void sach_load_file() {
	FILE * f_b;
	f_b = fopen("book_file", "rb");
	fread(lst_book, sizeof(lst_book), 1, f_b);
	fclose(f_b);
}
void sach_save_file() {
	FILE * f_b;
	f_b = fopen("book_file", "wb");
	fwrite(lst_book, sizeof(lst_book), 1, f_b);
	fclose(f_b);
}
void nhap(list &l)
{
	int i = 1;
	Booknode *p;
	int ma_tam;

	cout << "Hay nhap tong so luong sach  : ";
	cin >> total_book;
	cout << endl;

	for (int i = 1; i <= total_book; i++) {
	nhap_ma:;
		//cin.ignore();
		cout << ". Ma Sach: ";
		cin >> ma_tam;
		if (sach_tim(ma_tam) != 0) {
			cout << "   Ma Sach nay da ton tai. Hay nhap lai!";
			goto nhap_ma;
		}
		cout << "Sach thu " << i << " :" << endl;
		lst_book[i].masach = ma_tam;
		sach_nhap(lst_book[i]);
		p = getnode(lst_book[i]);
		AddTail(l, p);
	}
	sach_save_file();
	file_info();
}
void sach_nhap(Book &a)
{
	cin.ignore();
	cout << "Nhap ten sach : ";
	cin.getline(a.tensach, 30);
	cout << "Nhap ten tac gia cua sach: ";
	cin.getline(a.tacgia, 50);
	cout << "Nhap ten nxb: ";
	cin.getline(a.nxb, 100);
	cout << "Nhap nam xuat ban:";
	cin >> a.namxb;
	cout << "The loai:";
	cin.ignore();
	cin.getline(a.theloai, 50);
	cout << "SLS:";
	cin >> a.sl;
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

void themsach(list &l)
{
	int ma_tam;
	cout << endl;
	Booknode *p;
	Book s;
	//cin.ignore();

nhap_ma:;
	//cin.ignore();
	cout << ". Ma Sach: ";
	cin >> ma_tam;
	if (sach_tim(ma_tam) != 0) {
		cout << "   Ma Sach nay da ton tai. Hay nhap enter de nhap lai!";
		goto nhap_ma;
	}
	
	s.masach= ma_tam;
	printf("\n\t Nhap Ten Sach: "); scanf("%s", &s.tensach);
	printf("\n\t Nhap Ten Tac Gia: "); scanf("%s", &s.tacgia);
	printf("\n\t Nhap Ten NXB: "); scanf("%s", &s.nxb);
	printf("\n\t Nhap Nam Xuat Ban: "); scanf("%d", &s.namxb);
	printf("\n\t Nhap The Loai: "); scanf("%s", &s.theloai);
	printf("\n\t Nhap SLS: "); scanf("%d", &s.sl);
	p = getnode(s);
	AddHead(l, p);
	sach_save_file();
	file_info();

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
void search_tacgia(list &l, char tacgia_key[30])
{
	sach_load_file();
	Booknode *p;
	Booknode s;
	p = l.phead;
	while (p != NULL)
	{
		if (strcmp(p->info.tacgia, tacgia_key) == 0)
		{
			cout << "\n ------------------------------------------";
			cout << "\n | Sach thu: " << i++ << "                             |";
			cout << "\n ------------------------------------------";
			cout << "\n Ma Sach: " << p->info.masach;
			cout << "\n Ten Sach: " << p->info.tensach;
			cout << "\n Tac Gia: " << p->info.tacgia;
			cout << "\n NXB: " << p->info.nxb;
			cout << "\n Nam XB: " << p->info.namxb;
			cout << "\n The loai: " << p->info.theloai;
			cout << "\n SLS: " << p->info.sl;
			cout << "\n ------------------------------------------";
		}
		p = p->pnext;
	}
}

int sach_tim(int ma_tam)
{
	int jump = 1;
	while ((jump <= total_book) && (lst_book[jump].masach != ma_tam))
		jump++;
	if (jump > total_book)
		return 0;
	else
		return jump;
}

void xuat(list l)
{
	sach_load_file();
	
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
			cout << "\n The loai: " << R->info.theloai;
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

void phieu_load_file() {
	FILE *f_b;
	f_b = fopen("bill_file", "rb");
	fread(lst_bill, sizeof(lst_bill), 1, f_b);
	fclose(f_b);
}

void phieu_save_file() {
	FILE * f_b;
	f_b = fopen("bill_file", "wb");
	fwrite(lst_bill, sizeof(lst_bill), 1, f_b);
	fclose(f_b);
}

void interface_bill_manager() {

	PhieuMuon s;
	list1 l;
	Phieunode *p;
	int x, chon;
	createList1(l);

	
	nhapphieu(l);
	system("cls");
begin:
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
		system("cls");
		phieu_them(l, s);
		phieu_xuat(l);
		break; }
	case 2: {
		char key[30];
		cin.ignore();
		cout << "nhap ma phieu can xoa:";
		cin.getline(key, 30);
		int t=removeX(l,key);
		if (t == 1) {
			cout << "xoa thanh cong!";
			phieu_xuat(l);
		}else
		cout << "khong tim thay!";
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
		system("cls");
		char x1[50];
		cout << "nhap phieu can tim:";
		cin.ignore();
		cin.getline( x1,50);
		tim_phieu(l, x1);
		break;
	}

	case 6:
		goto end;
		break;
		
		
	}
	goto begin;
	end:;
}

void phieu_nhap(PhieuMuon &a)
{

	Phieunode *p;
	//cin.ignore();
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
	PhieuMuon a;
	char ma_tam[50];

	cout << "Day la lan dang ki phieu muon dau tien. \n";
	cout << "Hay nhap tong so luong phieu muon se duoc dang ki : "; 
	cin >> total_bill;
	cout << endl;

	for (int i = 1; i <= total_bill; i++) {
	nhap_ma:;
		cin.ignore();
		cout << ". Ma Phieu: ";
		cin.getline(ma_tam, 50);
		if (phieu_tim(ma_tam) != 0) {
			cout << "   Ma Phieu nay da ton tai. Hay enter de nhap lai!";
			goto nhap_ma;
		}
		//cin.ignore();
		
		cout << "Phieu muon thu " << i << " :" << endl;
		strcpy(lst_bill[i].masv, ma_tam);
		phieu_nhap(lst_bill[i]);
		p = getnode1(lst_bill[i]);
		addtail(l, p);
	}
	phieu_save_file();
	file_info();
}
void phieu_xuat(list1 &a)
{
	phieu_load_file();
	int i = 1;
	Phieunode *p = a.ahead;
	cout << "\n";
	if (p == NULL)
		cout << "\n\t Danh sach trong !";
	else
	{
		while (p != NULL)
		{
			cout << "\n ------------------------------------------";
			cout << "\n | Phieu thu: " << i++ << "                             |";
			cout << "\n ------------------------------------------";
			cout << "\n Ma SV:" << p->info.masv ;
			cout << "\n Ho Ten:" << p->info.hoten ;
			cout << "\n. Ngay Muon     : \n";
			cout << " \tNgay " << p	->info.bill_ngaymuon.n_day;
			cout << " \tThang: " << p->info.bill_ngaymuon.n_month;
			cout << " \tNam: " << p->info.bill_ngaymuon.n_year;
			cout << "\n ------------------------------------------";
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
	char ma_tam[50];
nhap_ma:;
	cin.ignore();
	cout << ". Ma SV: ";
	cin.getline(ma_tam, 50);
	if (phieu_tim(ma_tam) != 0) {
		cout << "   Ma SV nay da ton tai. Hay nhap lai!";
		goto nhap_ma;
	}
	//cin.ignore();
	strcpy(lst_bill[i].masv, ma_tam);
	cout << "Phieu muon thu " << i << " :" << endl;
	phieu_nhap(lst_bill[i]);
	p = getnode1(lst_bill[i]);
	addtail(l, p);
	phieu_save_file();
	file_info();
}
int removeAfterQ(list1 &l, Phieunode *q)
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
int removeHead(list1 &l)
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
	while ((p != NULL) && (strcmp(p->info.masv, key) != 0)) // nếu p!=NULL và khi chưa phải là khóa key thì tiếp tục tìm ;lưu ý rằng vòng lặp này đưa con trỏ q tới nút kế tiếp nút có khóa key
	{

		q = p;
		p = p->pnext;

	}
	if (strcmp(l.ahead->info.masv, key) == 0) // vì dử dụng hàm xóa 1 nút đằng sau nút q thì phải xét nội dung của nút đầu trứoc,nếu trùng với khóa key thì tiến hành xóa nút đầu
	{
		removeHead(l);
		return 1;
	}

	if (q != NULL) // còn nếu khác đồng thời phía trên tìm đc ví trí nút q thì tiến hnahf xóa nút kế tiếp nút q ,cũng chính là nút có khóa key
	{
		removeAfterQ(l, q);
	}
	else
		return 1;

}
void phieu_hieu_chinh(list1 l, char key[30])
{
	Phieunode *p;
	PhieuMuon a;
	p = l.ahead;
	//cin.ignore();
	cout << "nhap ma phieu can hieu chinh!";
	cin.getline(key,10);
	while ((p != NULL))
	{
		if (phieu_tim(key) == 1) {
			removeX(l, key);
			phieu_nhap(lst_bill[i]);
			p = getnode1(lst_bill[i]);
			addhead(l, p);
			break;
		}
		p = p->pnext;
	}
	phieu_save_file();
	
	phieu_xuat(l);

}
void tim_phieu(list1 &l, char key[50])
{
	phieu_load_file();
	Phieunode *p;
	Phieunode a;
	int i = 1;
	p = l.ahead;
	while (p != NULL )
	{
		if (strcmp(p->info.masv, key) == 0) {
			cout << "\n ------------------------------------------";
			cout << "\n | Phieu Muon thu: " << i++ << "                             |";
			cout << "\n ------------------------------------------";
			cout << "\n Ma SV:" << p->info.masv ;
			cout << "\n Ho ten:" << p->info.hoten ;
			cout << "\n. Ngay Muon     : \n";
			cout << " \tNgay: " << p->info.bill_ngaymuon.n_day;
			cout << " \tThang: " << p->info.bill_ngaymuon.n_month;
			cout << " \tNam: " << p->info.bill_ngaymuon.n_year;
			cout << "\n ------------------------------------------";
			cout << endl;
		}
		p = p->pnext;
	}
}


//-----------------------------Chi Tiet Phieu Muon----------------------------


void interface_bill_detail_manager() {
begin:
	//system("cls");
	list l1;
	list2 l;
	Createlist2(l);
	createList(l1);
	//ctphieu_nhap(l, l1);

	cout << endl << endl;
	cout << "               +-------------------------------------------------+ \n";
	cout << "               |     GIAO DIEN QUAN LY CHI TIET PHIEU MUON       | \n";
	cout << "               |-------------------------------------------------| \n";
	cout << "               |                                                 | \n";
	cout << "               |  1. Nhap Chi Tiet Phieu.                        | \n";
	cout << "               |                                                 | \n";
	cout << "               |  2. Xuat Chi Tiet Phieu.                        | \n";
	cout << "               |                                                 | \n";
	cout << "               |  3. Back.                                       | \n";
	cout << "               |                                                 | \n";
	cout << "               +-------------------------------------------------+ \n";

	char chon;
	bool k = true;

	do
	{
		if (k == false)
			cout << "Hay chon cong viec theo so tu 1 den 3 :";
		else
			cout << "Chon cong viec theo so: "; cin >> chon;
		k = false;
	} while ((chon < '1') || (chon > '3'));


	switch (chon) {
	case '1':  // system("cls");
	{
		ctphieu_nhap(l);
		break;
	}
	case '2':
		//system("cls");
		ctphieu_xuat(l);
		break;
	case '3':
		goto end;
		break;
	}
	goto begin;
end:;
}
void ctphieu_load_file() {
	FILE *f_b;
	f_b = fopen("bill_detail_file", "rb");
	fread(lst_detail, sizeof(lst_detail), 1, f_b);
	fclose(f_b);
}
void ctphieu_save_file() {
	FILE * f_b;
	f_b = fopen("bill_detail_file", "wb");
	fwrite(lst_detail, sizeof(lst_detail), 1, f_b);
	fclose(f_b);
}
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
	l.bhead = NULL;
	l.btail = NULL;
}
void addHead(list2 &l, CTPMnode *p)
{
	if (p == NULL)
		l.bhead = l.btail = p;
	else {
		p->pnext = l.bhead;
		l.bhead = p;
	}
}
int phieu_tim(char ma_tam[]) 
{
	int jump = 1;

	while ((jump <= total_bill) && (strcmp(lst_bill[jump].masv, ma_tam) != 0))
		jump++;

	if (jump > total_bill)
		return 0;
	else
		return jump;

}
int timtensach(char ma_tam[])
{
	int jump = 1;

	while ((jump <= total_book) && (strcmp(lst_book[jump].tensach, ma_tam) != 0))
		jump++;

	if (jump > total_book)
		return 0;
	else
		return jump;

}
void addTail(list2 &l, CTPMnode *p)
{
	if (l.bhead == NULL)
	{
		l.bhead = l.btail = p;
	}
	else
	{
		l.btail->pnext = p;
		l.btail = p;
	}
}
void ctphieu_nhap(list2 &l)
{
	Booknode *p;
	CTPMnode *k;
	int sach_ma_tam;
	char phieu_ma_tam[50];
	char t;
	int total_tam;
	int i = 0;
muon:;
	cin.ignore();
	cout << ". So sach se muon : "; 
	cin >> total_tam;

	if (total + total_tam > 5) {
		cout << "- Ban chi co the muon toi da 5 cuon. \n";
		cout << "  Ban duoc phep muon them  " << 5 - total << "  cuon nua.";
		goto muon;
	}

	for (int i = 1; i <= total_tam; i++)
	{{
		cin.ignore(1);
		cout << endl;
		cout << ". Nhap ma phieu : ";
		cin.getline(phieu_ma_tam, 50);

		if (phieu_tim(phieu_ma_tam) == 0) {
			cout << "- Khong tim thay phieu muon cua ban.";
			break;
		}

	nhap_ma_sach:;
		//cin.ignore(1);
		cout << ". Nhap Ma Sach : ";
		cin >> sach_ma_tam;
		t = sach_tim(sach_ma_tam);
		if (t == 0) {
			cout << ". Khong tim thay sach ban can.";
			cout << "  Ban muon muon sach khac (y/n) : ";
			cin >> t;
			if (t == 'y' || t == 'Y')
				goto nhap_ma_sach;
			else
				break;
		}
		strcpy(lst_detail[i].masv, phieu_ma_tam);
		lst_detail[i].masach = sach_ma_tam;
		strcpy(lst_detail[i].tensach, lst_book[p1].tensach);

		cout << strcpy(lst_detail[i].tensach, lst_book[p1].tensach);
		cin.ignore();
		cout << ". Tra / Chua : ";
		cin.getline(lst_detail[i].trachua, 10);
	}
		if (strcmp(lst_detail[i].trachua, "chua") == 0)
			lst_book[p1].sl = lst_book[p1].sl - 1;
		else
			lst_book[p1].sl = lst_book[p1].sl + 1;
		k = getnode2(lst_detail[i]);
		addTail(l, k);
		/*p = getnode(lst_book[p1]);
		AddTail(l1, p);*/
	
	}
	ctphieu_save_file();
	file_info();
}

void ctphieu_xuat(list2 l)
{
	ctphieu_load_file();
	
	char phieu_ma_tam[8];
	p1 = 0;
	cin.ignore();
	cout << ". Nhap ma phieu : ";
	cin.getline(phieu_ma_tam, 8);
	int i = 1;
	CTPMnode *p=l.bhead;
	if (p == NULL)
		cout << "\n\t Danh sach trong !";
	else {
		while (p != NULL)
		{
			if (strcmp(p->info.masv, phieu_ma_tam) == 0)
			{
				cout << "\n ------------------------------------------";
				cout << "\n | CTPM thu: " << i++ << "                             |";
				cout << "\n ------------------------------------------";
				cout << "\n Ma Sach:" << p->info.masach;
				cout << "\n Ten Sach:"<< p->info.tensach;
				cout << "\n Tra/Chua:"<< p->info.trachua << endl << endl;
			}
			p = p->pnext;
		}
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DINH NGHIA HAM THONG KE.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void interface_main() {

	//system("cls");
	list l;
	list1 l1;
	list2 l2;
	createList(l);
	createList1(l1);
	Createlist2(l2);
begin:
	cout << endl << endl;
	cout << "               +=================================================+ \n";
	cout << "               |         CHUONG TRINH QUAN LY THU VIEN           | \n";
	cout << "               |-------------------------------------------------| \n";
	cout << "               |                                                 | \n";
	cout << "               |  1. Quan ly sach trong Thu vien.                | \n";
	cout << "               |  2. Quan ly phieu ban doc  .                    | \n";
	cout << "               |  3. Quan ly Chi tiet phieu muon sach.           | \n";
	cout << "               |                                                 | \n";
	cout << "               |  4. Thong ke doc gia muon qua han               | \n";
	cout << "               |                                                 | \n";
	cout << "               |  5. Exit.                                       | \n";
	cout << "               |                                                 | \n";
	cout << "               +-------------------------------------------------+ \n";

	char chon;
	bool k = true;

	do
	{
		if (k == false)
			cout << "Hay chon cong viec theo so tu 1 den 3 :";
		else
			cout << "Chon cong viec theo so: "; cin >> chon;
		k = false;
	} while ((chon < '1') || (chon > '5'));



	switch (chon) {
	case '1':
		system("cls");
		interface_book_manager();
		break;
	case '2':
		system("cls");
		interface_bill_manager();
		break;
	case '3':
		system("cls");
		interface_bill_detail_manager();
		break;
	case '4':
		system("cls");
		theloai(l);
		break;
	case '5':
		system("cls");
		TK_SV_qua_han(l1);
		break;
	case '6':
		goto end;
		break;
	}
	goto begin;
end:;
}
void theloai(list l)
{
	Booknode *p;
	p = l.phead;
	char sach_theloai_tam[50];
	int p2 = 0;
	int i = 1;
	cin.ignore(1);
	cout << ". Nhap the loai muon thong ke: ";
	cin.getline(sach_theloai_tam, 50);
	cout << endl;
	if (p == NULL)
		cout << "Danh sach trong!";
	else
	{
		while (p != NULL)
		{
			if (strcmp(p->info.theloai, sach_theloai_tam) == 0) {
				cout << "\n ------------------------------------------";
				cout << "\n | Sach thu: " << i++ << "                             |";
				cout << "\n ------------------------------------------";
				cout << "\n Ma Sach:" << p->info.masach;
				cout << "\n Ten Sach:" << p->info.tensach;
				cout << "\n The Loai:" << p->info.theloai;
				cout << "\n So Luong:" << p->info.sl;
				cout << "\n ------------------------------------------";
				p2 = p2 + 1;
			}

			p = p->pnext;
		}
		cout << endl << "- Co " << p2 << " cuon sach co the loai : " << sach_theloai_tam;
		if (p2 == 0)
			cout << endl << "- Khong co sach nao thuoc the loai : " << sach_theloai_tam;
	}
}
void TK_SV_qua_han(list1 &l)
{
	SYSTEMTIME d;
	int n_d, n_m, n_y;
	int d_quahan;

	n_d = d.wDay;
	n_m = d.wMonth;
	n_y = d.wYear;
	Phieunode *p;
	cout << endl;
	cout << setw(15) << "So Phieu" << setw(15) << "Ten SV" << endl << endl;

	for (p=l.ahead ; p !=NULL; p=p->pnext) {
		if ((p->info.bill_ngaymuon.n_year == n_y) && (p->info.bill_ngaymuon.n_month == n_m))
			d_quahan = n_d - p->info.bill_ngaymuon.n_day;
		if ((p->info.bill_ngaymuon.n_year == n_y) && (p->info.bill_ngaymuon.n_month != n_m))
			d_quahan = n_d + days_in_month(n_m, n_d);
		if (d_quahan >= 30)
			cout << endl;
		cout << setw(15) << p->info.masv << setw(15) << p->info.masv << endl;
	}
}
int days_in_month(int md, int dd) 
{
	switch (md)
	{
	case '1':
		return (31 - dd);
	case '2':
		return (28 - dd);
	case '3':
		return (31 - dd);
	case '4':
		return (30 - dd);
	case '5':
		return (31 - dd);
	case '6':
		return (30 - dd);
	case '7':
		return (31 - dd);
	case '8':
		return (31 - dd);
	case '9':
		return (30 - dd);
	case '10':
		return (31 - dd);
	case '11':
		return (30 - dd);
	case '12':
		return (31 - dd);
	}
}