#include <stdio.h>
#include "header.h"


int main(){
	char c;
	int input;

	int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
	do{
        system("cls");
        printf("Pilih salah satu menu dibawah:\n");
        printf("1. Insertion\n");
        printf("2. Selection\n");
        printf("3. Bubble\n");
        printf("4. Quick Sort\n");
        printf("5. Merge Sort\n");
        printf("6. exit\n\n");
        printf("Pilih menu = ");scanf("%d", &input);

        switch(input){
            case 1:
                system("cls");
                insertion(arr, n);
                c = getchar();
                getchar();
            break;
            case 2:
                system("cls");
                selection(arr, n);
                c = getchar();
                getchar();
            break;
            case 3:
                system("cls");
                bubble();
                c = getchar();
                getchar();
            break;
            case 4:
                system("cls");
                quickSort();
                c = getchar();
                getchar();
            break;
            case 5:
                system("cls");
                mergeSort();
                c = getchar();
                getchar();
            break;
            case 6:
                printf("Keluar");
            break;
            default:
                printf("Input salah! Pilih nomor 1 - 6");
                c = getchar();
                getchar();
            break;
        }
    }while(input != 6);
    

    return 0;
}

