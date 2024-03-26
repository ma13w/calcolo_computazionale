void insertionSort(long long int array[], const int dim, long long int *operation){
    int temp, j;
    *operation+=2;
    
    *operation+=1;
    for(int i=1; i<dim; i++){
        temp = array[i];
        *operation+=1;
        
        j = i-1;
        *operation+=1;
        
        *operation += 2;
        while(j >= 0 && array[j] > temp){
            *operation += 2;
            
            array[j+1] = array[j];
            *operation+=2;
            j--;
            *operation+=1;
        }
        array[j+1] = temp; 
        *operation+=2;
    }
}

