void astri3(){
    printf("Menu 3\n\n");
    
    // Bikin programnya dibawah oke
	struct barang{
		char kode[100];
		char nama[100];
		float harga;
	};
	struct barang data;
	FILE *file;
	float total;
	
	file = fopen("data/database.txt", "r");
	while(!feof(file)){
		fscanf(file, "%[^#]#%[^#]#%f\n", &data.kode, &data.nama, &data.harga);fflush(stdin);
		total = total + data.harga;
	}
	printf("Total Produk = %2.f", total);
}
