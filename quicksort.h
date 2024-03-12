int partition(int arr[], int low, int high, int *calc) {
    int pivot = arr[high];
    int i = low - 1;
    *calc += 3;

    *calc += 1;
    for (int j = low; j <= high - 1; j++) {
		*calc += 2;
		
        *calc += 1;
        if (arr[j] <= pivot) {
            *calc += 2;
            i++;
            swap(&arr[i], &arr[j], calc);
        }
    }
    *calc += 1;

    *calc += 1;
    swap(&arr[i + 1], &arr[high], calc);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int *calc) {
    *calc += 1;
    if(high <= low) return;
    
    int p = partition(arr, low, high, calc);
    quickSort(arr, low, p - 1, calc);
    quickSort(arr, p + 1, high, calc);

    *calc += 3;
}
