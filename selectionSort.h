void selectionSort(long long int arr[], int dim, long long int *operazioni) {
    int i, j, min_idx;
    *operazioni+=3;

    *operazioni+=1; //init i
    for (i = 0; i < dim-1; i++) {
    	*operazioni+=1; //end for
    	
        min_idx = i; *operazioni+=1;
        
        *operazioni+=1; //init j
        for (j = i+1; j < dim; j++){
        	*operazioni+=1; //end for
        	
        	*operazioni+=1;
          	if (arr[j] < arr[min_idx]){
          		min_idx = j; *operazioni+=1;
			}
			
			*operazioni+=1; //increase j
        	*operazioni+=1; //go up
		}
        swap(&arr[min_idx], &arr[i], operazioni); *operazioni+=1;
        
        *operazioni+=1; //increase i
        *operazioni+=1; //go up
    }
}
