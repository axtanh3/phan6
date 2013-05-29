/*
 * Bai :
 */

#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef struct
{
  char Hoten[29];
	unsigned int Tuoi;
	char DiaChi[100];
	unsigned int GioiTinh;
}
sinhvien;
void sapxep (sinhvien danhsach[], int n);
void nhap(sinhvien danhsach[], int n);
void inds(sinhvien danhsach[], int n);
void layten(char hoten[], char ten[]);

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
	sinhvien dsten[100];
	for (i = 0; i < n; i++)
		layten(danhsach[i].Hoten, dsten[i].Hoten);
	
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
			if (strcmpi(dsten[i].Hoten, dsten[j].Hoten) > 0)
			{
				tmp = danhsach[i];
				danhsach[i] = danhsach[j];
				danhsach[j] = tmp;
			}
			else if (strcmpi(dsten[i].Hoten, dsten[j].Hoten) == 0 && strcmpi(danhsach[i].Hoten, danhsach[j].Hoten) > 0)
			{
				tmp = danhsach[i];
				danhsach[i] = danhsach[j];
				danhsach[j] = tmp;
			}
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
		
		printf("Tuoi                : ");
		scanf("%d", &danhsach[i].Tuoi);
		
		do
		{
			printf("Gioi tinh(Nam-1/Nu-0)   : ");
			scanf("%d", &danhsach[i].GioiTinh);
		}
		while (danhsach[i].GioiTinh != 0 && danhsach[i].GioiTinh != 1);	

		printf("Dia chi             : ");
		gets(danhsach[i].DiaChi);
		
		printf("\n\n");
	}
}

void inds(sinhvien danhsach[], int n)
{	
	int i;
	printf("SV  Ho Ten                       Tuoi   Gioi tinh   Dia chi\n");
	for (i = 0; i < n; i++)
		printf("%-4d%-29s%-7d%-12s%-30s\n", i+1, danhsach[i].Hoten, danhsach[i].Tuoi, danhsach[i].GioiTinh == 1 ? "Nam" : "Nu", danhsach[i].DiaChi);
	printf("\n");
}

void layten(char hoten[], char ten[])
{
	int i, j, dem;
	j = dem = 0;
	for (i = strlen(hoten) - 1; i > -1 ; i--)
	{
		dem++;
		if (hoten[i] == ' ')
			break;
	}
	
	while (j < dem && i < strlen(hoten))
	{
		ten[j] = hoten[i+1];
		j++;
		i++;
	}
}
