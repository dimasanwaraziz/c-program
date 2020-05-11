#include <stdio.h>

void menu01(int deret){
	int var01=0, var02=1, temp;
	if(deret == 1) printf("%d", var01); else
	printf("%d, ", var02);
	for(int i=0; i < deret-1; i++){
		temp = var02;
		var02 = var02 + var01;
		var01 = temp;
		printf("%d, ", var02);
	}
	printf("\n");
}

int menu02(int deret){
	if(deret == 0 || deret == 1) return deret;
	else return( menu02(deret-1) + menu02(deret-2) );
}

int main(){
	int input, deret, j = 1;
	do{
		printf("1. Deret Fibonaci Non Rekursif\n");
		printf("2. Deret Fibonaci Rekursif\n");
		printf("3. Exit\n");
		printf("Pilih Menu = ");scanf("%d", &input);
		printf("Masukkan deret = ");scanf("%d", &deret);
		
		switch(input){
			case 1: menu01(deret); break;
			case 2: 
				for(int i=1; i<=deret; i++){ 
					printf("%d", menu02(j) );
					if(i == deret) printf("."); else printf(", "); 
					j++;
				}
				printf("\n");
				break;
			case 3: printf("exit"); break;
		}
	}while(input != 3);
}
