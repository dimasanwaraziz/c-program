void astri3(){
    printf("Menu 3\n\n");
    
    // Bikin programnya dibawah oke
    FILE *fptr;
    char data[15]="data/";
    char filename[15];
    char ch;
    
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
}
