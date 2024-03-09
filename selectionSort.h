void selectionSort(int arr[], int dim, int *operazioni) {
    int i, j, min_idx;
    *operazioni+=3;

    *operazioni+=(2*(dim-1)+2);
    for (i = 0; i < dim-1; i++) {
        min_idx = i;
        *operazioni+=1;
        *operazioni+=(2*(dim)+2);
        for (j = i+1; j < dim; j++){
        	*operazioni+=1;
          	if (arr[j] < arr[min_idx]){
          		min_idx = j;
          		*operazioni+=1;
			  }
		}	
        swap(&arr[min_idx], &arr[i], operazioni);
        *operazioni+=1;
    }
}
