/*
 * Bai :
 */

#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
  char Hoten[29];
	unsigned int diemTB;
}
sinhvien;

void sapxep (sinhvien danhsach[], int n);
void nhap(sinhvien danhsach[], int n);
void inds(sinhvien danhsach[], int n);

int main(void)
{
	int i, n;
	sinhvien danhsach[100];
	printf("Nhap so luong sinh vien :");
	scanf("%d", &n);
	
	nhap(danhsach, n);
	printf("Chua sap xep :\n\n");
	inds(danhsach, n);
	
	sapxep(danhsach, n);
	printf("Da sap xep :\n\n");
	inds(danhsach, n);


	getch();
	return 0;
}

void sapxep (sinhvien danhsach[], int n)
{
	int i, j;
	sinhvien tmp;
	
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (danhsach[i].diemTB < danhsach[j].diemTB)
			{
				tmp = danhsach[i];
				danhsach[i] = danhsach[j];
				danhsach[j] = tmp;
			}
}

void nhap(sinhvien danhsach[], int n)
{
	int i;
	for(i = 0; i < n; i ++)
	{
		fflush(stdin);
		printf("Sinh vien %d\n", i + 1);
		
		printf("Ho ten              : "); 
		gets(danhsach[i].Hoten);
		fflush(stdin);
		
		printf("Diem TB             : ");
		scanf("%d", &danhsach[i].diemTB);
		
		printf("\n\n");
	}
}

void inds(sinhvien danhsach[], int n)
{	
	int i;
	printf("SV  Ho Ten                       Diem trung binh\n");
	for (i = 0; i < n; i++)
		printf("%-4d%-29s%-15d\n", i+1, danhsach[i].Hoten, danhsach[i].diemTB);
	printf("\n");
}
