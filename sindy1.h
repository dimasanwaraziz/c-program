void sindy1(){
    printf("Menu 1\n\n");
    
    // Bikin programnya dibawah oke
    struct barang{
		char kode[100];
	    char nama[100];
	    float harga;
	};

	struct barang data;
	char inputlagi;
    FILE *file;
    
    file = fopen("data/database.txt", "w");
    while(inputlagi != 'n'){
		printf("\nMasukkan data berikut\n");
		printf("Kode  : ");fflush(stdin);gets(data.kode);
		printf("Nama  : ");fflush(stdin);gets(data.nama);
		printf("Harga : ");
		while(scanf("%f", &data.harga) == 0){
			printf("Harga harus angka!\nHarga : ");
			scanf("%*s");
		}
		
		fprintf(file, "%s#%s#%2.f\n", data.kode, data.nama, data.harga);
		printf("\nKode  : %s\nNama  : %s\nHarga : %2.f", data.kode, data.nama, data.harga);
		printf("\ninput lagi? [y/n] ");scanf("%s", &inputlagi);
	}
	fclose(file);
}
