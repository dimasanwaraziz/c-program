#include <stdio.h>
#include <dirent.h>
#include "sindy1.h"
#include "sindy2.h"
#include "astri3.h"
#include "astri4.h"

char c;
int input;

int main()
{
	do{
        system("cls");
        printf("Pilih salah satu menu dibawah:\n");
        printf("1. Buat arsip beruntun\n");
        printf("2. Tampilkan arsip beruntun\n");
        printf("3. Hitung total produk\n");
        printf("4. Hitung rata-rata total produk\n");
        printf("5. exit\n\n");
        printf("Pilih menu = ");scanf("%d", &input);

        switch(input){
            case 1:
                system("cls");
                sindy1();
                c = getchar();
                getchar();
            break;
            case 2:
                system("cls");
                sindy2();
                c = getchar();
                getchar();
            break;
            case 3:
                system("cls");
                astri3();
                c = getchar();
                getchar();
            break;
            case 4:
                system("cls");
                astri4();
                c = getchar();
                getchar();
            break;
            case 5:
                printf("Keluar");
            break;
            default:
                printf("Input salah! Pilih nomor 1 - 5");
                c = getchar();
                getchar();
            break;
        }
    }while(input != 5);
    

    return 0;
}

