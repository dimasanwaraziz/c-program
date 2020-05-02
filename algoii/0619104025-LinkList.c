#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Mahasiswa{
	int nim;
	char nama[30];
	float ipk;
};

struct Elemen{
	struct Mahasiswa mhs;
	struct Elemen *next;
};

struct List{
	struct Elemen *first;
};

 
	struct List L, M;
	int count = 0;

// Print list all element
void printAllElement(struct Elemen *L){
	int number=1;
	if(L == NULL){
		printf("Belum ada data yang dimasukkan");
	}else{
		printf("Ada %d data nih\n\n", count);
		do{
			printf("[%d] %d %s %.2f\n\n", number, L->mhs.nim, L->mhs.nama, L->mhs.ipk);
			L = L->next;
			number++;
		}while(L != NULL);
	}
}

// Bagian untuk add
void addFirst(int nim, char nama[], float ipk, struct Elemen *L){
	struct Elemen *B = (struct Elemen *)malloc(sizeof(struct Elemen));
	
	B->mhs.nim = nim;
	strcpy(B->mhs.nama, nama);
	B->mhs.ipk = ipk;
	
	
	if(L == NULL){
		L = B;
		L->next = NULL;
		//printf("%d\n", L->mhs.nim);
		//printf("%s\n", L->mhs.nama);
		//printf("%.2f\n", L->mhs.ipk);
		//printf("yes, is null");
		M.first = L;
		count++;
		//printf("%d\n", count);
	}else{
		B->next = L;
		L = B;
		//printf("%d", B->mhs.nim);
		//printf("%s", B->mhs.nama);
		//printf("%.2f", B->mhs.ipk);
		//printf("masuk ke else");
		M.first = L;
		count++;
	}
}
void addAfter(struct Elemen *prev, int nim, char nama[], float ipk, struct Elemen *L){
	struct Elemen *B = (struct Elemen *)malloc(sizeof(struct Elemen));
	
	B->mhs.nim = nim;
	strcpy(B->mhs.nama, nama);
	B->mhs.ipk = ipk;

	if(L == NULL){
		L = B;
		L->next = NULL;
		M.first = L;
		count++;
	}else{
		while(B->mhs.nim > L->mhs.nim){
			if(L->next == NULL){
				L->next = B;
				B->next = NULL;
			}else if(B->mhs.nim > L->mhs.nim && B->mhs.nim <= L->next->mhs.nim){
				prev = L->next;
				L->next = B;
				B->next = prev;
			}
			L = L->next;
		}
	}
}
void addLast(int nim, char nama[], float ipk, struct Elemen *L){
	struct Elemen *B = (struct Elemen *)malloc(sizeof(struct Elemen));
	
	B->mhs.nim = nim;
	strcpy(B->mhs.nama, nama);
	B->mhs.ipk = ipk;

	if(L == NULL){
		L = B;
		L->next = NULL;
		M.first = L;
		count++;
	}else{
		while(L->next != NULL){
			L = L->next;
		}
		L->next = B;
		count++;
	}
	
}

// Bagian untuk delete
void deleteFirst(struct List *L);
void deleteAfter(struct Elemen *prev, struct List *L);
void deleteLast(struct List *);

int main(){
	int input;
	char enterForContinue;
	int nim;
	char nama[30];
	float ipk;
	//struct Elemen *e = (struct Elemen *)malloc(sizeof(struct Elemen));
	L.first = NULL;
	
	do{
		system("clear");
		printf("Punya Dimas - 0619104025\n");
		printf("1. Tambah di awal\n");
		printf("2. Tambah di setelah\n");
		printf("3. Tambah di akhir\n");
		printf("4. Hapus di awal\n");
		printf("5. Hapus di setelah\n");
		printf("6. Hapus di akhir\n");
		printf("7. Tampilkan data\n");
		printf("8. exit\n");
		printf("Masukkan menu = ");scanf("%d", &input);
		
		if(input == 1 || input == 3 || input == 2){
			printf("[1/3] Masukkan NIM = ");scanf("%d", &nim);
			printf("[2/3] Masukkan Nama = ");scanf("%s", nama);
			printf("[3/3] Masukkan IPK = ");scanf("%f", &ipk);
		}
		
		
		switch(input){
			case 1: 
				if(count == 0)
					addFirst(nim, nama, ipk, L.first); 
				else
					addFirst(nim, nama, ipk, M.first); 
				break;
			case 2:
				if(count == 0)
					addAfter(L.first, nim, nama, ipk, L.first); 
				else
					addAfter(L.first, nim, nama, ipk, M.first); 
				break;
			case 3: 	
				if(count == 0)
					addLast(nim, nama, ipk, L.first); 
				else
					addLast(nim, nama, ipk, M.first); 
				break;
			case 4: break;
			case 5: break;
			case 6: break;
			case 7: printAllElement(M.first); enterForContinue = getchar(); getchar(); break;
			case 8: printf("exit"); break;
		}
	}while(input != 8);
}	
