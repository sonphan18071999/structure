// Sách đã được mượn mấy cuốn.
// Sách đó có hay không
// Xử lý dữ liệu trong 1 cái file
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
using namespace std;

typedef struct Book {
	int masach;
	char tensach[30];
	char tacgia[30];
	char nxb[30];
	int namxb;
	int trangthai;
};
struct Booknode {
	Book info;
	Booknode *pnext;
};

struct list {
	Booknode *phead;
	Booknode *ptail;
};




Booknode *getnode(Book &s);
int main()
{
	Book s;
	list l;
	Booknode *p;
	int x, chon;
	char key[30];
	createList(l);
	do {
		system("cls");
		printf("\n\t ---------------------------------");
		printf("\n\t | CHUONG TRINH QUAN LY THU VIEN |");
		printf("\n\t ---------------------------------");
		printf("\n\t 1. Them 1 quyen sach vao dau danh sach ");
		printf("\n\t 2. Duyet danh sach ");
		printf("\n\t 3. Xoa 1 Phan Tu dau Danh Sach ");
		printf("\n\t 4. Xoa 1 Quyen Sach Theo Ten Tac Sach ");
		printf("\n\t 5. Seach 1 Quyen sach theo ten tac gia ");
		printf("\n\t 0. Thoat ");
		printf("\n\t # Chon (1->6 or 0 de thoat): ");
		cin >> chon;
		switch (chon)
		{
		case 1: {
			printf("\n\t Nhap Ma Sach: "); scanf("%d", &s.masach); fflush(stdin);
			printf("\n\t Nhap Ten Sach: "); scanf("%s", &s.tensach);
			printf("\n\t Nhap Ten Tac Gia: "); scanf("%s", &s.tacgia);
			printf("\n\t Nhap Ten NXB: "); scanf("%s", &s.tacgia);
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
			gets(key);
			RemoveX(l, key);

			cout << "\n\t Xoa Thanh Cong !";
			break;
		}
		case 5:
		{
			cout << "\n\t Nhap Ten Tac Gia : "; fflush(stdin);
			gets(key);
			search_tacgia(l, key);
			break;
		}
		}
		system("pause");
	} while (chon != 0);
	return 0;
}
void createList(Node &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
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