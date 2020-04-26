void sindy1(){
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
}
