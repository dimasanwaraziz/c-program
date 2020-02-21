void astri4(){
    printf("Menu 4\n\n");
    
    // Bikin programnya dibawah oke
    struct barang{
		char kode[100];
		char nama[100];
		float harga;
	};
	struct barang data;
	FILE *file;
	float total;
	int hitungtotal=0;
	
	file = fopen("data/database.txt", "r");
	while(!feof(file)){
		fscanf(file, "%[^#]#%[^#]#%f\n", &data.kode, &data.nama, &data.harga);fflush(stdin);
		total = total + data.harga;
		if(data.kode){
			hitungtotal++;
		}
	}
	printf("Total Produk = %2.f", total/hitungtotal);
}
