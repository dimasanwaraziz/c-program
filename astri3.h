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
 
    printf("\nEnter the filename to be opened = ");fflush(stdin);gets(filename);
    /*  open the file for reading */
    fptr = fopen(strcat(data, filename), "r");
    if (fptr == NULL){
        printf("Cannot open file \n");
    }
    
	char cacing[100];
    fgets(cacing, 100, (FILE*)fptr);
    printf("%s", cacing);
    fclose(fptr);
}
