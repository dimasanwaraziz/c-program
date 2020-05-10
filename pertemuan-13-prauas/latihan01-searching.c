#include <stdio.h>

int main(){
	int menu;
	do{
		printf("Latihan 1 - Searching\n\n");
		printf("Dimas Anwar Aziz | 0619104025\n");
		printf("1. Sequentian Search tanpa var Logika\n");
		printf("2. Sequential Search dengan var logika\n");
		printf("3. Sentinel Search\n");
		printf("4. exi\nt");
		printf("Masukkan menu = ");scanf("%d", &menu);
		
		switch(menu){
			case 1: menu01(); break;
			case 2: menu02(); break;
			case 3: menu03(); break;
			case 4: printf("exit"); break;
		}
	}while(menu != 4);
}
