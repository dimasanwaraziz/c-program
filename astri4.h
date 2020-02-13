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
    printf("\nMasukkan nama file yang akan dihapus = ");fflush(stdin);gets(filename);
    char data[15]="data/";
	if(remove(strcat(data, filename)) == 0){
		printf("\nFile \"%s\" berhasil dihapus\n", filename);
	}else{
		printf("Gagal menghapus file / file tidak ada"); 
	}

}
