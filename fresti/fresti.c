#include<stdio.h>
#include<string.h>
#include<stdbool.h>

struct nodeDosen{
	int kodedosen;		
	char nama[300];	
	int totalsks;	
	struct nodeDosen *next;	
};

struct nodeDosen *head, *baru, *bantu, *bantu2;

//program inisialisasi
void inisialisasi(){
	head = (struct nodeDosen*)malloc(sizeof(struct nodeDosen));
	head = NULL;
}

//program tambah depan
void addawal(int kodedosen, char nama[300], float totalsks){
	baru = (struct nodeDosen*)malloc(sizeof(struct nodeDosen));
	baru->kodedosen = kodedosen;
	strcpy(baru->nama, nama);
	baru->totalsks = totalsks;
	if(head == NULL){
		head=baru;
		head->next = NULL;
	}else{
		baru->next = head;
		head = baru;
	}
}

//program tambah akhir
void addakhir(int kodedosen, char nama[300], float totalsks){
   	baru = (struct nodeDosen*)malloc(sizeof(struct nodeDosen));
   	baru -> kodedosen = kodedosen;
   	strcpy (baru -> nama, nama);
   	baru -> totalsks = totalsks;
   	if(head == NULL){
      	head=baru;		
      	head->next = NULL;  	
  	}else{
     	bantu = head;
    	while(bantu->next != NULL){
		bantu = bantu->next;
    }
      	bantu->next = baru;	
      	baru->next = NULL;	
  	}
}

//program tambah tengah
void addtengah(int kodedosen, char nama[300], float totalsks){
   	baru = (struct nodeDosen*)malloc(sizeof(struct nodeDosen));
   	baru -> kodedosen = kodedosen;
   	strcpy(baru->nama, nama);
   	baru->totalsks = totalsks;
   	if(head == NULL){
      	head=baru;		
      	head->next = NULL;  
   	}else{
      	if(baru->totalsks <= head->totalsks){ 
		baru->next = head;
		head = baru;
    }else{
        bantu = head;		
        while(baru->totalsks > bantu->totalsks){  
			if(bantu->next == NULL){
			   bantu->next = baru;	
			   baru->next = NULL;	
			}else if(baru->totalsks > bantu->totalsks && baru->totalsks < bantu->next->totalsks){
			   bantu2 = bantu->next; 
			   bantu->next = baru;	 
			   baru->next = bantu2;	 
			}
        bantu = bantu->next; 			
    	}
  	  }
	}
}

//program tampilkan
void tampilkanData(){
	if(head==NULL){
		printf("\nList Kosong\n");
	}
	else{
		bantu=head;
		while(bantu!=NULL){
			printf("\nKode Dosen : %d",bantu->kodedosen);
			printf("\nNama : %s",bantu->nama);
			printf("\nTotal SKS : %d\n",bantu->totalsks);
			bantu=bantu->next;
		}
	}
}

//program hapus awal
void hapusAwal(){
  	struct nodeDosen*hapus;			
  	if(head == NULL){			
     	printf("Data Kosong\n");
  	}else{
     	if(head->next == NULL){		
        head = NULL;
    	}else{
       	hapus = head;		
       	head = head->next;
      	hapus = NULL;
     	}
     	printf("Data berhasil dihapus\n");	
  	}
}

//program hapus tengah
void hapusTengah(int cari){
   	struct nodeDosen *hapus, *temp, *bantu;
   	bool found = false;
   	if(head == NULL){
      	printf("Data Kosong\n");
   	}else{
      	hapus = head;
      	if(hapus->kodedosen == cari){		
         	if(hapus->next == NULL){	
           	head = NULL;
        }else{			
           hapus = head;
           head = head->next;
           hapus = NULL;
        }
        
      	}else{
        while(hapus->next != NULL){			
            if(hapus->kodedosen == cari){		
                found = true;
                break;
            }
            temp = hapus;
            hapus = hapus->next;
            }            
            if(found){
                if(hapus->next == NULL){		
                    temp->next = NULL;
                    hapus = NULL;
                }else{
                    bantu = hapus->next;		
                    temp->next = bantu;
                    hapus = NULL;
                }
            }else{
            printf("Data tidak ditemukan\n");
         }
      }
   }
}

//program hapus akhir
void hapusAkhir(){
	struct nodeDosen*hapus, *temp;
   	if(head == NULL){
      	printf("Data Kosong\n");
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
      printf("Data berhasil dihapus\n");	
    }
}

//program mencari data tidak terurut
void searchDataTidakTerurut(int cari){
	if(head == NULL){
		printf("List Masih Kosong\n");
	}else{
		bantu = head;
		while(bantu->next != NULL && bantu->kodedosen != cari){
			bantu = bantu->next;
		}
		if(bantu->kodedosen == cari){
			printf("Data Ditemukan\n");
		}else{
			printf("Data Tidak Ditemukan\n");
		}
	}
}

int main(){
	int menu, kodedosen,totalsks,kode;
	char nama[300];
	inisialisasi();
	do{
	printf ("\n		>> MENU <<\n");
	printf ("================================================\n\n");
	printf ("1. Input data dosen di awal list\n");
	printf ("2. Input data dosen diantara dua simpul\n");
	printf ("3. Input data dosen di akhir simpul\n");
	printf ("4. Tampilkan data dosen\n");
	printf ("5. Hapus data dosen di awal list\n");
	printf ("6. Hapus data dosen diantara dua simpul\n");
	printf ("7. Hapus data dosen di akhir simpul\n");
	printf ("8. Pencarian data dosen tidak terurut\n");
	printf ("9. Exit\n\n");
	printf ("================================================\n");
	
	printf ("Input Menu :"); scanf ("%d", &menu);
	
	switch(menu){
		case 1:
			printf("Input Kode Dosen: ");scanf("%d", &kodedosen);
			printf("Input Nama: ");scanf("%s", &nama);
			printf("Input Total SKS: ");scanf("%d", &totalsks);
			addawal(kodedosen,nama,totalsks);
		break;
		
		case 2:
			printf("Input Kode Dosen: ");scanf("%d", &kodedosen);
			printf("Input Nama: ");scanf("%s", &nama);
			printf("Input Total SKS: ");scanf("%d", &totalsks);
			addtengah(kodedosen,nama,totalsks);
		break;
		
		case 3:
			printf("Input Kode Dosen: ");scanf("%d", &kodedosen);
			printf("Input Nama: ");scanf("%s", &nama);
			printf("Input Total SKS: ");scanf("%d", &totalsks);
			addakhir(kodedosen,nama,totalsks);
		break;
		
		case 4:
			tampilkanData();
		break;
		
		case 5:
			hapusAwal();
		break;
		
		case 6:
			printf("Masukan Kode Dosen : "); scanf("%d",&kode);
			hapusTengah(kode);
		break;
		
		case 7:
			hapusAkhir();
		break;
		
		case 8:
			printf("Masukan Kode Dosen : "); scanf("%d",&kode);
			searchDataTidakTerurut(kode);
		break;
		
		case 9:
			printf ("exitt");
		break;
		}
	}while (menu !=9);
}
