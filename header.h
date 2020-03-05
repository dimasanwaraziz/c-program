void insertion(int arr[], int n){
	printf("Menu 1 (Insertion)\n\n");
	
	int i, temp, j, array[n];  
	printf("nilai n = %d\n", n);
	
	printf("Sebelum di urut = ");
	for(i=0; i < n; i++){
		array[i]=arr[i];
    	printf("%d, ", array[i]);
	}
	
    for (i = 1; i < n; i++) { 
        temp = array[i]; 
        j = i - 1; 
        
        while (j >= 0 && array[j] > temp) { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = temp; 
    } 

    printf("\nSetelah di urut = ");
    for(i=0; i < n; i++){
    	printf("%d, ", array[i]);
	}
}

void selection(int arr[], int n){
	int i, j, min_idx, temp, array[n]; 
  	
  	printf("Sebelum di urut = ");
	for(i=0; i < n; i++){
		array[i]=arr[i];
    	printf("%d, ", array[i]);
	}
  
    for (i = 0; i < n-1; i++){ 
        min_idx = i; 
        for (j = i+1; j < n; j++) {
          if (array[j] < array[min_idx]) {
            min_idx = j; 
		  }
		}
  		temp=array[min_idx];
  		array[min_idx]=array[i];
  		array[i]=temp;
    }
	
	printf("\nSetelah di urut = ");
    for(i=0; i < n; i++){
    	printf("%d, ", array[i]);
	} 
}

void bubble(){
}

void quickSort(){
}

void mergeSort(){
}
