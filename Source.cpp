// QLTV2.cpp : Defines the entry point for the console application.

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
typedef struct Booknode {
	Book info;
	Booknode *pnext;
};

typedef struct list {
	Booknode *phead;
	Booknode *ptail;
};

Booknode *getnode(Book &s);
int RemoveX(list &l, char key[30]);
void createList(list &l);
void AddHead(list &l, Booknode *p);
int RemoveHead(list &l);
void search_tacgia(list l, char tacgia_key[30]);
int RemoveAfterQ(list &l, Booknode *q);
void xuat(list l);
void interface_bill_manager();

void phieu_load_file();
void phieu_save_file();
void phieu_nhap();
void phieu_xuat();
void phieu_them();
void phieu_xoa();
int  phieu_tim(char ma_tam[]);
void phieu_hieu_chinh();
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
void sach_xuat();
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

struct BOOK {
	char b_ma[50];
	char b_tensach[50];
	char b_tacgia[50];
	char b_theloai[50];
	char b_nhaXB[50];
	int b_soluong;
};
struct n_DATE {
	int n_day;
	int n_month;
	int n_year;
};
struct BILL {
	char bill_tenSV[50];
	char bill_maSV[50];
	n_DATE bill_ngaymuon;
};

struct BILL_DETAIL {
	char detail_maSV[50];
	char detail_maSach[50];
	char detail_tenSach[50];
	char b_trachua[50];             // Tinh trang tra hay chua.
	char b_moi_cu[50];              // Tinh trang moi hay cu.
};

typedef BOOK LIST_BOOK[100];                    // Kieu LIST_BOOK la mang 100 cuon sach.
typedef BILL LIST_BILL[100];                    // Kieu LIST_BILL la mang 100 phieu muon.
typedef BILL_DETAIL LIST_DETAIL[100];
LIST_BOOK lst_book;             // Bien lst_book la mang 50 cuon sach.
LIST_BILL lst_bill;             // Bien lst_bill la mang 50 phieu muon.
LIST_DETAIL lst_detail;         // Bien lst_detail la mang 50 chi tiet phieu muon.


void file_info();
void interface_main();
void interface_book_manager();
void interface_bill_detail_manager();

void main()
{
	interface_book_manager();
	interface_bill_manager();

}

void interface_book_manager() {
begin:

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

	Book s;
	list l;
	Booknode *p;
	int x, chon;
	char key[30];
	createList(l);


	scanf("%d", &chon);
	switch (chon)
	{
	case 0:
	{
		int n;
		cout << "nhap so luong sach:";
		cin >> n;
		nhap(l, n);
		break;
	}
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
	}

	goto begin;
end:;
}


void nhap(list &l, int n)
{
	Book x[100];
	Booknode *p;
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap dau sach thu " << i << " :" << endl;
		sach_nhap(x[i]);
		p = getnode(x[i]);
		AddTail(l, p);
	}

}
void sach_nhap(Book &a)
{
	cout << "Nhap ma sach: ";
	cin >> a.masach;
	cout << "Nhap ten sach : ";
	cin.ignore();
	cin.getline(a.tensach, 9);
	cout << "Nhap ten tac gia cua sach: ";
	cin.ignore();
	cin.getline(a.tacgia, 50);
	cout << "Nhap ten nxb: ";
	cin.getline(a.nxb, 100);
	cout << "Nhap nam xuat ban:";
	cin >> a.namxb;
	cout << "Nhap ten tac gia cua sach: ";
	cin.ignore();
	cout << endl;
}
void sach_xuat(Book a)
{
	cout << endl;
	cout << "Ma sach la: " << a.masach << endl;
	cout << "Ten sach la : " << a.tensach << endl;
	cout << "Ten tac gia cua sach: " << a.tacgia << endl;
	cout << "Ten nxb la: " << a.nxb << endl;
	cout << "Ma nam xuat ban: " << a.namxb << endl;
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
	if (q != NULL && q->pnext != NULL)
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
void phieu_nhap() {
	char ma_tam[50];

	cout << "Day la lan dang ki phieu muon dau tien. \n";
	cout << "Hay nhap tong so luong phieu muon se duoc dang ki : "; cin >> total_bill;
	cout << endl;

	for (int i = 1; i <= total_bill; i++) {
	nhap_ma:;
		cin.ignore();
		cout << ". Ma Phieu: "; cin.getline(ma_tam, 50);

		if (phieu_tim(ma_tam) != 0) {
			cout << "   Ma Phieu nay da ton tai. Hay nhap lai!";
			goto nhap_ma;
		}

		//cin.ignore();
		strcpy(lst_bill[i].bill_maSV, ma_tam);
		cout << ". Ten Sinh Vien : "; cin.getline(lst_bill[i].bill_tenSV, 50);

		cout << ". Ngay Muon     : \n";
		cout << " \tNgay "; cin >> lst_bill[i].bill_ngaymuon.n_day;
		cout << " \tThang: "; cin >> lst_bill[i].bill_ngaymuon.n_month;
		cout << " \tNam: "; cin >> lst_bill[i].bill_ngaymuon.n_year;
		cout << endl;
	}
	phieu_save_file();
	file_info();
}
void interface_bill_manager() {
begin:
	system("cls");
	cout << endl << endl;
	cout << "               +-------------------------------------------------+ \n";
	cout << "               |      GIAO DIEN QUAN LY PHIEU MUON SACH          | \n";
	cout << "               |-------------------------------------------------| \n";
	cout << "               |                                                 | \n";
	cout << "               |  1. Nhap Phieu.                                 | \n";
	cout << "               |  2. Them Phieu.                                 | \n";
	cout << "               |  3. Xoa Phieu.                                  | \n";
	cout << "               |                                                 | \n";
	cout << "               |  4. Xuat Phieu.                                 | \n";
	cout << "               |  5. Hieu chinh Phieu.                           | \n";
	cout << "               |  6. Tim Phieu.                                  | \n";
	cout << "               |                                                 | \n";
	cout << "               |  7. Back.                                       | \n";
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
	} while ((chon < '1') || (chon > '7'));


	switch (chon) {
	case '1':   system("cls");
		phieu_nhap();
		break;
	case '2':
		system("cls");
		phieu_them();
		break;
	case '3':
		phieu_xoa();
		break;
	case '4':
		system("cls");
		phieu_xuat();
		break;
	case '5':
		system("cls");
		phieu_hieu_chinh();
		break;
	case '6':
		cin.ignore();
		cout << "Nhap ma phieu (Ma SV) can tim : "; cin.getline(ma_tam, 50);

		i = phieu_tim(ma_tam);

		if (i == 0)
			cout << "- Khong tim thay phieu co ma so tren. ";
		else {
			cout << "\nDa tim thay phieu: \n";
			cout << setw(15) << ".Ma Phieu/ Ma SV" << setw(15) << "Ten SV" << endl << endl;
			cout << setw(15) << lst_bill[i].bill_maSV << setw(15) << lst_bill[i].bill_tenSV;
			cout << endl;
		}
		break;
	case '7':
		goto end;
		break;
	}
	goto begin;
end:;
}

void phieu_them() 
{
	char ma_tam[50];

	total_bill = total_bill + 1;

nhap_ma:;
	cin.ignore();
	cout << ". Ma Phieu: "; cin.getline(ma_tam, 50);

	if (phieu_tim(ma_tam) != 0) {
		cout << "   Ma sach da ton tai. Hay nhap lai!";
		goto nhap_ma;
	}

	//cin.ignore();
	strcpy(lst_bill[i].bill_maSV, ma_tam);
	cout << ". Ten Sinh Vien : "; cin.getline(lst_bill[i].bill_tenSV, 50);

	cout << ". Ngay Muon     : \n";
	cout << " Ngay "; cin >> lst_bill[i].bill_ngaymuon.n_day;
	cout << " thang: "; cin >> lst_bill[i].bill_ngaymuon.n_month;
	cout << " nam: "; cin >> lst_bill[i].bill_ngaymuon.n_year;
	cout << endl;

	phieu_save_file();
	file_info();
}

void phieu_xoa() {
	char ma_tam[50];

	cin.ignore();
	cout << "Nhap ma phieu can xoa : "; cin.getline(ma_tam, 50);

	i = phieu_tim(ma_tam);

	if (i == 0)
		cout << "- Khong tim thay phieu co ma so tren. ";
	else {
		for (int j = i; j <= total_bill; j++)
			lst_bill[j] = lst_bill[j + 1];

		total_bill = total_bill - 1;
		cout << "- Da xoa.";
	}
	phieu_save_file();
	file_info();
}

void phieu_xuat() {
	phieu_load_file();

	cout << "\n                      DANH SACH PHIEU MUON           \n \n";
	cout << setw(15) << ".Ma Phieu/ Ma SV" << setw(15) << "Ten SV" << endl << endl;
	for (int i = 1; i <= total_bill; i++) {
		cout << setw(15) << lst_bill[i].bill_maSV << setw(15) << lst_bill[i].bill_tenSV;
		cout << endl;
	}
}



void phieu_hieu_chinh() {
	char ma_tam[50];

	cin.ignore();
	cout << "Nhap ma phieu can hieu chinh : "; cin.getline(ma_tam, 50);

	i = phieu_tim(ma_tam);

	if (i == 0)
		cout << "- Khong tim thay phieu co ma so tren. ";
	else {
		//cin.ignore();
		cout << ". Ma phieu/Ma SV: "; cin.getline(lst_bill[i].bill_maSV, 50);
		cout << ". Ten Sinh Vien : "; cin.getline(lst_bill[i].bill_tenSV, 50);

		cout << ". Ngay Muon     : \n";
		cout << " Ngay "; cin >> lst_bill[i].bill_ngaymuon.n_day;
		cout << " thang: "; cin >> lst_bill[i].bill_ngaymuon.n_month;
		cout << " nam: "; cin >> lst_bill[i].bill_ngaymuon.n_year;
		cout << endl;
	}
	phieu_save_file();
}

