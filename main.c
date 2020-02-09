/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "sindy1.h"
#include "sindy2.h"
#include "astri3.h"
#include "astri4.h"

char c;
int input;

int main()
{
    do{
        system("clear");
        printf("Pilih salah satu menu dibawah:\n");
        printf("1. Buat File teks\n");
        printf("2. Tambah data file\n");
        printf("3. Tampilkan data file\n");
        printf("4. Hapus file teks\n");
        printf("5. exit\n\n");
        printf("Pilih menu = ");scanf("%d", &input);
    
        switch(input){
            case 1:
                sindy1();
                c = getchar();
                getchar();
            break;
            case 2:
                sindy2();
                c = getchar();
                getchar();
            break;
            case 3:
                astri3();
                c = getchar();
                getchar();
            break;
            case 4:
                astri4();
                c = getchar();
                getchar();
            break;
            case 5:
                printf("Keluar");
                c = getchar();
                getchar();
            break;
            default:
                printf("Input salah! Pilih nomor 1 - 5");
                c = getchar();
                getchar();
        }
    }while(input != 5);
    

    return 0;
}
