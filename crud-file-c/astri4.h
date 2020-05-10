void astri4(){
    printf("Menu 4\n\n");
    
    // Bikin programnya dibawah oke
    printf("  File yang sudah ada:\n");
    DIR *d;
    struct dirent *dir;
    d = opendir("data/");
    if(d){
    	while((dir = readdir(d)) != NULL){
    		if((dir->d_name) != "."){
    			printf("  %s\n", dir->d_name);
			}
		}
		closedir(d);
	}
    
	char filename[15];
    int inputan;
	FILE *astri;
    printf("\nMasukkan nama file yang akan dihapus = ");fflush(stdin);gets(filename);
    char data[15]="data/";
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

}
