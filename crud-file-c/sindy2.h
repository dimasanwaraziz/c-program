void sindy2(){
    printf("Menu 2\n\n");
    
    // Bikin programnya dibawah oke
    FILE *sindy;
    FILE *check;
    FILE *write;
    char data[15]="data/";
    char datanya[100];
    char modenya[100];
    char filename[15];
    int input, mode;
    
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
    
    printf("\nMasukkan nama file yang akan di masukkan data = [0 untuk batal] ");fflush(stdin);fgets(filename, 100, stdin);
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
}
