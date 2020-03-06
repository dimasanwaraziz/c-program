void sequential(int arr[], int n){
	printf("Menu 4 (Sequential Search)\n");
	int input, i, ketemu=0, pada=-1;
	printf("\nNilai Array = ");
    for(i=0; i < n; i++){
    	printf("%d, ", arr[i]);
	}
	printf("\nMasukkan nilai yang akan dicari = "); scanf("%d", &input);
	for(i=0; i < n; i++){
		if(input == arr[i]){
			ketemu=1;
			pada=i;
		}
	}
	
	if(ketemu==1 && pada != -1){
		printf("\nNilai ditemukan pada indeks ke-%d", pada);
	}else{
		printf("\nNilai tidak ditemukan");
	}
}

void binary(int arr[], int n){
	printf("Menu 5 (Binary Search)\n\n");
	int l=0, r=n-1, x, i, array[n], j, temp;
	int result=-1;
	
	printf("\nNilai Array = ");
    for(i=0; i < n; i++){
		array[i]=arr[i];
	}
	
	for (i = 0; i < n-1; i++)  {     
       for (j = 0; j < n-i-1; j++) { 
           if (array[j] > array[j+1]) {
              temp=array[j];
          		array[j]=array[j+1];
          		array[j+1]=temp;
           }
       }
    }
	
	for(i=0; i < n; i++){
    	printf("%d, ", array[i]);
	}
	
	printf("\nMasukkan nilai yang akan dicari = ");scanf("%d", &x);
	while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        // Check if x is present at mid 
        if (array[m] == x){
            result = m;
		}
  
        // If x greater, ignore left half 
        if (array[m] < x){
            l = m + 1; 
		} 
  
        // If x is smaller, ignore right half 
        else{
            r = m - 1; 
		}
    }
    
    if(result == -1){
    	printf("Nilai index tidak ditemukan");
	}else{
		printf("Nilai ditemukan pada indeks ke-%d", result);
	}
}
