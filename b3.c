/*
 * Bai :
 */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  char TenHang[30];
	unsigned int DonGia;
	unsigned int SoLuong;
	unsigned long ThanhTien;
}
hang;

void sapxep (hang danhsach[], int n);
void nhap(hang danhsach[], int n);
void inMH(hang danhsach[], int n);

int main(void)
{
	int i, n;
	hang danhsach[100];
	printf("Nhap so luong hang :");
	scanf("%d", &n);
	
	nhap(danhsach, n);
	printf("Chua sap xep :\n\n");
	printf("                    SO LIEU BAN HANG\n");
	inMH(danhsach, n);
	
	sapxep(danhsach, n);
	printf("Da sap xep :\n\n");
	printf("                    SO LIEU BAN HANG\n");
	inMH(danhsach, n);


	getch();
	return 0;
}

void sapxep (hang danhsach[], int n)
{
	int i, j;
	hang tmp;
	
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (strcmpi(danhsach[i].TenHang, danhsach[j].TenHang) > 0)
			{
				tmp = danhsach[i];
				danhsach[i] = danhsach[j];
				danhsach[j] = tmp;
			}
}

void nhap(hang danhsach[], int n)
{
	int i;
	for(i = 0; i < n; i ++)
	{
		fflush(stdin);
		printf("Mat hang %d\n", i + 1);
		
		printf("Ten Hang              : "); 
		gets(danhsach[i].TenHang);
		
		printf("Don gia               : ");
		scanf("%d", &danhsach[i].DonGia);
		
		printf("So luong              : ");
		scanf("%d", &danhsach[i].SoLuong);
		fflush(stdin);
		
		danhsach[i].ThanhTien = danhsach[i].DonGia * danhsach[i].SoLuong;
		
		printf("\n\n");
	}
}

void inMH(hang danhsach[], int n)
{	
	int i;
	printf("STT Ten Hang       Don gia  So luong  Thanh tien\n");
	for (i = 0; i < n; i++)
		printf("%-4d%-15s%-9d%-10d%-10d\n", i+1, danhsach[i].TenHang, danhsach[i].DonGia, danhsach[i].SoLuong, danhsach[i].ThanhTien);
	printf("\n");
}
