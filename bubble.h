void bubbleSort(long long int array[], int dim, long long int *oper){
	*oper+=1;
    int aiuto;
    
    *oper+=1;
    for(int i=0; i<dim-1; i++){ 
		*oper+=1;   	
       	for(int j=0; j<dim-i-1; j++){
       		*oper+=2; //condizione
         	if(array[j] > array[j+1]){
	            aiuto = array[j];
	            array[j] = array[j+1];
	            array[j+1] = aiuto;
	            
	            *oper+=5;//swap
        	}
        	*oper+=3;//for j
	   	}
	   *oper+=3;//for i
	}
}
