#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct dosen{
    int kodeDosen, totalSks;
    char nama[100];
    struct dosen *next;
};

struct dosen *head = NULL;

void menu01(){
    struct dosen *baru;
    baru = (struct dosen*)malloc(sizeof(struct dosen));
    printf("[1/3] Masukkan kode Dosen = ");scanf("%d", &baru->kodeDosen);
    printf("[2/3] Masukkan nama Dosen = ");scanf("%s", baru->nama);
    printf("[3/3] Masukkan total SKS  = ");scanf("%d", &baru->totalSks);
    
    if(head == NULL){
        head = baru;
        head->next = NULL;
    }else{
        baru->next = head;
        head = baru;
    }
}

void menu02(){
    struct dosen *baru, *pembantu01, *pembantu02;
    baru = (struct dosen*)malloc(sizeof(struct dosen));
    printf("[1/3] Masukkan kode Dosen = ");scanf("%d", &baru->kodeDosen);
    printf("[2/3] Masukkan nama Dosen = ");scanf("%s", baru->nama);
    printf("[3/3] Masukkan total SKS  = ");scanf("%d", &baru->totalSks);
    
    if(head == NULL){
        head = baru;
        head->next = NULL;
    }else{
        if(baru->kodeDosen <= head->kodeDosen){
            baru->next = head;
            head = baru;
        }else{
            pembantu01 = head;
            while(baru->kodeDosen > pembantu01->kodeDosen){
                if(pembantu01->next == NULL){
                    pembantu01->next = baru;
                    baru->next = NULL;
                }else if(baru->kodeDosen > pembantu01->kodeDosen && baru->kodeDosen <= pembantu01->next->kodeDosen){
                    pembantu02 = pembantu01->next;
                    pembantu01->next = baru;
                    baru->next = pembantu02;
                }
                pembantu01 = pembantu01->next;
            }
        }
    }
}

void menu03(){
    struct dosen *baru, *pembantu;
    baru = (struct dosen*)malloc(sizeof(struct dosen));
    printf("[1/3] Masukkan kode Dosen = ");scanf("%d", &baru->kodeDosen);
    printf("[2/3] Masukkan nama Dosen = ");scanf("%s", baru->nama);
    printf("[3/3] Masukkan total SKS  = ");scanf("%d", &baru->totalSks);
    
    if(head == NULL){
        head = baru;
        head->next = NULL;
    }else{
        pembantu = head;
        while(pembantu->next != NULL){
            pembantu = pembantu->next;
        }
        pembantu->next = baru;
        baru->next = NULL;
    }
}

void menu04(){
	struct dosen *hapus;
	char enterUntukLanjut;

	if(head == NULL){
		printf("Data masih kosong");
		enterUntukLanjut = getchar();
		getchar();
	}else{
		if(head->next == NULL){
			head = NULL;
		}else{
			hapus = head;
			head = head->next;
			hapus = NULL;
		}
		printf("Data berhasil dihapus");
		enterUntukLanjut = getchar();
		getchar();
	}
}

void menu05(){
	struct dosen *hapus, *temp, *bantu;
	bool found = false;
	char enterUntukLanjut;
	int cari;

	printf("Masukkan Kode Dosen yang akan dihapus = ");scanf("%d", &cari);

	if(head == NULL){
		printf("Data masih kosong");
		enterUntukLanjut = getchar();
		getchar();
	}else{
		hapus = head;
		if(hapus->kodeDosen == cari){
			if(hapus->next == NULL){
				head = NULL;
			}else{
				hapus = head;
				head = head->next;
				hapus = NULL;
			}
		}else{
			while(hapus != NULL){
				if(hapus->kodeDosen == cari){
					found = true;
					break;
				}
				temp = hapus;
				hapus = hapus->next;
			}
			if(found == true){
				if(hapus->next == NULL){
					temp->next = NULL;
					hapus = NULL;
				}else{
					bantu = hapus->next;
					temp->next = bantu;
					hapus = NULL;
				}
			}else{
				printf("Data tidak ditemukan");
				enterUntukLanjut = getchar();
				getchar();
			}
		}
	}
}

void menu06(){
	struct dosen *hapus, *temp;
	char enterUntukLanjut;

	if(head == NULL){
		printf("Data masih kosong");
		enterUntukLanjut = getchar();
		getchar();
	}else{
		if(head->next == NULL){
			head = NULL;
		}else{
			hapus = head;
			while(hapus->next != NULL){
				temp = hapus;
				hapus = hapus->next;
			}
			temp->next = NULL;
			hapus = NULL;
		}
		printf("Data berhasil di hapus");
		enterUntukLanjut = getchar();
		getchar();
	}
}

void menu07(){
	struct dosen *bantu;
	int cari;
	char enterUntukLanjut;
	printf("Masukkan Kode Dosen yang akan dicari = ");scanf("%d", &cari);
	
	if(head == NULL){
		printf("Belum ada data");
		enterUntukLanjut = getchar();
		getchar();
	}else{
		bantu = head;
		while(bantu->next != NULL && bantu->kodeDosen != cari){
			bantu = bantu->next;
		}
		if(bantu->kodeDosen == cari){
			printf("Data ditemukan\n");
			printf("Kode Dosen = %d\n", bantu->kodeDosen);
			printf("Nama Dosen = %s\n", bantu->nama);
			printf("Jumlah SKS = %d", bantu->totalSks);
			enterUntukLanjut = getchar();
			getchar();
		}else{
			printf("Data tidak ditemukan");
			enterUntukLanjut = getchar();
			getchar();
		}
	}
}

void menu08(){
    struct dosen *tampilkan;
	int hitung=1; 
    tampilkan = head;
    
    if(tampilkan == NULL){
        printf("Belum ada data");
    }else{
        do{
			printf("[%d] %d %s %d\n\n", hitung, tampilkan->kodeDosen, tampilkan->nama, tampilkan->totalSks);
           // printf("Kode Dosen = %d\n", tampilkan->kodeDosen);
           // printf("Nama Dosen = %s\n", tampilkan->nama);
           // printf("Jumlah SKS = %d\n\n", tampilkan->totalSks);
            tampilkan = tampilkan->next;
			hitung++;
        }while(tampilkan != NULL);
    }
}

int main()
{
    int input;
    char enterUntukLanjut;
    do{
        system("cls");
        printf("1. Input data dosen di awal list\n");
        printf("2. Input data dosen di antara 2 simpul\n");
        printf("3. Input data dosen di akhir simpul\n");
        printf("4. Hapus data di awal list\n");
        printf("5. Hapus data di antara dua simpul\n");
        printf("6. Hapus data di akhir simpul\n");
        printf("7. Pencarian data tidak terurut\n");
        printf("8. Tampilkan semua data dosen\n");
        printf("9. exit\n");
        printf("Masukkan input = ");scanf("%d", &input);
        
        switch(input){
            case 1: menu01(); break;
            case 2: menu02(); break;
            case 3: menu03(); break;
            case 4: menu04(); break;
            case 5: menu05(); break;
            case 6: menu06(); break;
            case 7: menu07(); break;
            case 8: menu08(); enterUntukLanjut = getchar(); getchar(); break;
            case 9: printf("exit"); break;
        }
    }while(input != 9);
    return 0;
}
