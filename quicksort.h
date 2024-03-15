int partition(int arr[], int low, int high, int *calc) {
    int pivot = arr[high];
    int i = low - 1;
    *calc += 4;

    *calc += 1; //init j
    for (int j = low; j <= high - 1; j++) {
		*calc+=1; //end for
		
        *calc += 1; //check if
        if (arr[j] <= pivot) {
            *calc += 2;
            i++;
            swap(&arr[i], &arr[j], calc);
        }
        
        *calc+=1; //increase j
        *calc+=1; //go up
    }

    swap(&arr[i + 1], &arr[high], calc); *calc += 1;
    *calc += 1; //return
    return i + 1;
}

void quickSort(int arr[], int low, int high, int *calc) {
    *calc += 1; // check if
    if(high <= low) {
    	*calc += 1; //return
		return;
	}
    
    int p = partition(arr, low, high, calc);
    quickSort(arr, low, p - 1, calc);
    quickSort(arr, p + 1, high, calc);

    *calc += 3;
}
