void heapify(long long int arr[], const int n, long long int i, long long int *conta) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    *conta += 6;

    *conta += 2;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
        *conta+=1;
    }

    *conta += 2;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
        *conta+=1;
    }

    *conta+=1;
    if (largest != i) {
        swap(&arr[i], &arr[largest], conta);
        *conta+=1;
        heapify(arr, n, largest, conta);
        *conta+=1;
    }
}

void heapSort(long long int arr[], const int n, long long int *conta) {
	*conta += 1;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, conta);
        *conta += 1;
        
        *conta += 3;
    }
   

	*conta += 1;
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], conta);
        heapify(arr, i, 0, conta);
        *conta += 2;
        
        *conta += 3;
    }
}

