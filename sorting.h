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

void bubble(int arr[], int n){
	printf("Menu 2 (Bubble)\n\n");
    
    int i, j, array[n], temp; 
    
    printf("Sebelum di urut = ");
	for(i=0; i < n; i++){
		array[i]=arr[i];
    	printf("%d, ", array[i]);
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
    printf("\nSetelah di urut = ");
    for(i=0; i < n; i++){
    	printf("%d, ", array[i]);
	} 
}

void minmax(int arr[], int n){
	printf("Menu 3 (Min / Max)\n\n");
	
	int i, temp, min=arr[0], max=0;
	printf("\nNilai Array = ");
    for(i=0; i < n; i++){
    	printf("%d, ", arr[i]);
    	if(arr[i] >= max){
    		max = arr[i];
		}else if(arr[i] <= min){
			min = arr[i];
		}
	}
	
	printf("\nNilai min = %d", min);
	printf("\nNilai max = %d", max);
	
	
	
}
