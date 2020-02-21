void sindy2(){
    printf("Menu 2\n\n");
    
    // Bikin programnya dibawah oke
	struct barang{
		char kode[100];
		char nama[100];
		float harga;
	};
	struct barang data;
	FILE *file;
	int i=1;
	
	file = fopen("data/database.txt", "r");
	while(!feof(file)){
		fscanf(file, "%[^#]#%[^#]#%f\n", &data.kode, &data.nama, &data.harga);fflush(stdin);
		
		printf("\nProduk ke-%d\n", i);
		printf("Kode  : %s\n", data.kode);
		printf("Nama  : %s\n", data.nama);
		printf("Harga : %2.f\n", data.harga);
		i++;
	}
}
