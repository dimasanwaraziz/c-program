void sequential(){
		char c;
	int input;
        system("cls");
        printf("Pilih salah satu menu dibawah:\n");
        printf("1. Buat File teks\n");
        printf("2. Tambah data file\n");
        printf("3. Tampilkan data file\n");
        printf("4. Hapus file teks\n");
        printf("Pilih menu = ");scanf("%d", &input);
    
        switch(input){
            case 1:
                system("cls");
                printf("Menu 1\n\n");
    
			    // Bikin programnya dibawah oke
			    char data[15]="data/";
			    char filename[15];
			    
			    printf("  File yang sudah ada:\n");
			    DIR *d;
			    struct dirent *dir;
			    d = opendir("data/");
			    if(d){
			    	while((dir = readdir(d)) != NULL){
						printf("  %s\n", dir->d_name);
					}
					closedir(d);
				}
			    
			    printf("\nMasukkan nama file yang akan dibuat = [0 untuk batal] ");fflush(stdin);gets(filename);
			    if(strcmp("0", filename) == 0){
			    	printf("\nbatal menambah file...");
				}else{
					FILE *sindy;
				    sindy = fopen(strcat(data, filename), "w");
				    if(sindy != NULL){
				        printf("File \"%s\" berhasil dibuat \n", filename);
				    }else{
				    	printf("File gagal dibuat \n");
					}
				    fclose(sindy);
				}
                c = getchar();
                getchar();
            break;
            case 2:
                system("cls");
                printf("Menu 2\n\n");
    
    // Bikin programnya dibawah oke
    FILE *sindy;
    FILE *check;
    FILE *write;
//    char data[15]="data/";
    char datanya[100];
    char modenya[100];
//    char filename[15];
    int input, mode;
    
    printf("  File yang sudah ada:\n");
//    DIR *d;
//    struct dirent *dir;
    d = opendir("data/");
    if(d){
    	while((dir = readdir(d)) != NULL){
			printf("  %s\n", dir->d_name);
		}
		closedir(d);
	}
    
    printf("\nMasukkan nama file yang akan di masukkan data = [0 untuk batal] ");fflush(stdin);gets(filename);
    if(strcmp("0", filename) == 0 || strcmp("", filename) == 0){
    	printf("\nbatal menambah file...");
	}else{
	    check = fopen(strcat(data, filename), "r");
	    if(check == NULL){
	    	printf("\nFile belum ada, apakah anda ingin membuatnya?\n1. buat\n0. batal\npilihan = [1/0] ");scanf("%d", &input);
	    	if(input == 0){
	    		printf("\nbatal memasukkan data ke file");
	    		fclose(check);
			}else if(input == 1){
				write = fopen(data, "w");
				printf("\nMasukkan kata yang akan dimasukkan ke dalam file = ");fflush(stdin);gets(datanya);
				fprintf(write, "%s", datanya);
				printf("Berhasil memasukkan kata \"%s\" kedalam file %s", datanya, filename);
				fclose(write);
			}else{
				printf("\ninput tidak valid");
			}
		}else{
			fclose(check);
			printf("\n1. write (replace)\n2. append (add)\npilih mode untuk menulis file = [1/2] ");scanf("%d", &mode);
			if(mode == 1){
				sindy = fopen(data, "w");
				printf("\nMasukkan kata yang akan dimasukkan ke dalam file = ");fflush(stdin);gets(datanya);
				fprintf(sindy, "%s\n", datanya);
				printf("Berhasil memasukkan kata \"%s\" kedalam file %s", datanya, filename);
				fclose(sindy);
			}else if(mode == 2){
				sindy = fopen(data, "a+");
				printf("\nMasukkan kata yang akan dimasukkan ke dalam file = ");fflush(stdin);gets(datanya);
				fprintf(sindy, "%s\n", datanya);
				printf("Berhasil memasukkan kata \"%s\" kedalam file %s", datanya, filename);
				fclose(sindy);
			}else{
				printf("\ninputan tidak valid");
			}
		}
	}
                c = getchar();
                getchar();
            break;
            case 3:
                system("cls");
                printf("Menu 3\n\n");
    
    // Bikin programnya dibawah oke
    FILE *fptr;
//    char data[15]="data/";
//    char filename[15];
    char ch;
    
    printf("  File yang sudah ada:\n");
//    DIR *d;
//    struct dirent *dir;
    d = opendir("data/");
    if(d){
    	while((dir = readdir(d)) != NULL){
    		if((dir->d_name) != "."){
    			printf("  %s\n", dir->d_name);
			}
		}
		closedir(d);
	}
 
    printf("\nEnter the filename to be opened = [0 untuk batal] ");fflush(stdin);gets(filename);
    if(strcmp("0", filename) == 0 || strcmp("", filename) == 0){
    	printf("batal membuka file");
	}else{
	    fptr = fopen(strcat(data, filename), "r");
	    if (fptr == NULL)
	    {
	        printf("Gagal membuka file / file tidak ada\n");
	    }else{
		    ch = fgetc(fptr);
		    printf("\n Isi yang ada di dalam file:");
		    printf("\n==========\n");
		    while (ch != EOF)
		    {
		        printf ("%c", ch);
		        ch = fgetc(fptr);
		    }
		    printf("==========");
		    fclose(fptr);
		}
	}
                c = getchar();
                getchar();
            break;
            case 4:
                system("cls");
                printf("Menu 4\n\n");
    
    // Bikin programnya dibawah oke
    printf("  File yang sudah ada:\n");
//    DIR *d;
//    struct dirent *dir;
    d = opendir("data/");
    if(d){
    	while((dir = readdir(d)) != NULL){
    		if((dir->d_name) != "."){
    			printf("  %s\n", dir->d_name);
			}
		}
		closedir(d);
	}
    
//	char filename[15];
    int inputan;
	FILE *astri;
    printf("\nMasukkan nama file yang akan dihapus = ");fflush(stdin);gets(filename);
//    char data[15]="data/";
    astri = fopen(strcat(data, filename), "r");
    if(astri == NULL){
		printf("Gagal menghapus file / file tidak ada"); 
	}else{
		fclose(astri);
		printf("\n1. hapus file\n2. hapus isi file\npilihan = [1/2] ");scanf("%d", &inputan);
		if(inputan == 1){
			if(remove(data) == 0){
				printf("\nFile \"%s\" berhasil dihapus\n", filename);
			}
		}else if(inputan == 2){
			astri = fopen(data, "w");
			fprintf(astri, "");
			fclose(astri);
			printf("\nberhasil menghapus isi file");
		}else{
			printf("\ninputan salah");
		}
	}
                c = getchar();
                getchar();
            break;
            case 5:
                printf("Keluar");
            break;
            default:
                printf("Input salah! Pilih nomor 1 - 4");
                c = getchar();
                getchar();
            break;
        }
}

void binary(int arr[], int n){
	printf("Menu 5 (Binary Search)\n\n");
	int l=0, r=n-1, x, i, array[n], j, temp;
	int result=-1;
	
	printf("\nNilai Array = ");
    for(i=0; i < n; i++){
		array[i]=arr[i];
	}
	
	for (i = 0; i < n-1; i++)  {     
       for (j = 0; j < n-i-1; j++) { 
           if (array[j] > array[j+1]) {
              temp=array[j];
          		array[j]=array[j+1];
          		array[j+1]=temp;
           }
       }
    }
	
	for(i=0; i < n; i++){
    	printf("%d, ", array[i]);
	}
	
	printf("\nMasukkan nilai yang akan dicari = ");scanf("%d", &x);
	while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (array[m] == x){
            result = m;
		}
  
        // If x greater, ignore left half 
        if (array[m] < x){
            l = m + 1; 
		} 
  
        // If x is smaller, ignore right half 
        else{
            r = m - 1; 
		}
    }
    
    if(result == -1){
    	printf("Nilai index tidak ditemukan");
	}else{
		printf("Nilai ditemukan pada indeks ke-%d", result);
	}
}
