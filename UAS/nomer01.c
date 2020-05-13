#include <stdio.h>
#include <stdlib.h>

void enter();

void menu01(int banyaknya){
	int satu = 0, kedua = 0, ketiga = 0; 
	for(int i = 0; i < banyaknya; i++){
		if(satu == 0){
			printf("%d ", satu + 1);
			satu = 1;
		}else{
			ketiga = satu;
			satu = satu + kedua;
			kedua = ketiga;
			printf("%d ", satu);
		}
	}
}

int menu02(int banyak){
	if(banyak == 0 || banyak == 1) return banyak;
	else return menu02(banyak - 1) + menu02(banyak - 2);
}

int main(){
	int input, n, pembantu_fibo = 1;
	do{
		system("clear");
		printf("1. Fibonacci non-rekursif\n");
		printf("2. Fibonacci with rekursif\n");
		printf("3. exit\n");
		printf("Masukkan inputan = ");scanf("%d", &input);

		switch(input){
			case 1:
				printf("Masukkan jumlah N = ");scanf("%d", &n);
				menu01(n); 
				enter();
				break;
			case 2:
				printf("Masukkan jumlah N = ");scanf("%d", &n);
				pembantu_fibo = 1;
				for(int i = 0; i < n; i++){
					printf("%d ", menu02(pembantu_fibo));
					pembantu_fibo++;
				}
				enter();
				break;
			case 3: printf("exit"); break;
		}
	}while(input != 3);
}

void enter(){
	char c;
	c = getchar();
	getchar();
}
