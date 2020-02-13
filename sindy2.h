void sindy2(){
    printf("Menu 2\n\n");
    
    // Bikin programnya dibawah oke
    FILE *sindy;
    char data[15]="data/";
    char datanya[100];
    char filename[15];
    
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
    
    printf("\nMasukkan nama file yang akan di masukkan data = ");fflush(stdin);gets(filename);
    sindy = fopen(strcat(data, filename), "w");
    if(sindy == NULL){
    	printf("File tidak ada");
	}
	printf("Masukkan kata yang akan dimasukkan ke dalam file = ");fflush(stdin);gets(datanya);
	fprintf(sindy, "%s", datanya);
	printf("Berhasil memasukkan kata \"%s\" kedalam file %s", datanya, filename);
	fclose(sindy);
}
