void insertionSort(int array[], int dim, int *operation){
    int temp, j;
    for(int i=1; i<dim; i++){
        temp = array[i];
        (*operation)++;
        j = i-1;
        (*operation)++;
        while(j >= 0 && array[j] > temp){
            (*operation) += 2;
            array[j+1] = array[j];
            (*operation)++;
            j--;
            (*operation)++;
        }
        array[j+1] = temp; 
        (*operation)++;
    }
    *operation += 2*(dim)+2;
}

