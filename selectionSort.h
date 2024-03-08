

/*

	for(int i=0;i<dim-1;i++){
	...}
	operazioni+=2dim+2; (per ogni for)
*/	

//==============================================================================
void swap(int *xp, int *yp, int *operazioni) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    operazioni+=3;
}
//==============================================================================
void selectionSort(int arr[], int dim, int *operazioni) {
    int i, j, min_idx;
    operazioni+=3;

    // Attraversa tutti gli elementi dell'array
    operazioni+=(2*(dim-1)+2);
    for (i = 0; i < dim-1; i++) {
        // Trova l'elemento minimo nel rimanente array non ordinato
        min_idx = i;
        operazioni+=1;
        operazioni+=(2*(dim)+2);
        for (j = i+1; j < dim; j++){
        	operazioni+=1;
          	if (arr[j] < arr[min_idx]){
          		min_idx = j;
          		operazioni+=1;
			  }
		}	
        // Scambia l'elemento minimo trovato con il primo elemento
        swap(&arr[min_idx], &arr[i], &*operazioni);
        operazioni+=1;
    }
}
//==============================================================================
