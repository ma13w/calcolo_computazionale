
void swap(int *a, int *b, int *conta) {
    int temp = *a;
    conta++;
    *a = *b;
    conta++;
    *b = temp;
    conta++;
}
 
void heapify(int arr[], int n, int i, int *conta) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if (left < n && arr[left] > arr[largest]){
    	largest = left;
    	conta++;
	}
 
    if (right < n && arr[right] > arr[largest]){
    	largest = right;
    	conta++;
	}
        
    if (largest != i) {
        swap(&arr[i], &arr[largest], conta);
        conta++;
        heapify(arr, n, largest, conta);
        conta++;
    }
}
 
void heapSort(int arr[], int n, int *conta) {
    for (int i = n / 2 - 1; i >= 0; i--){
    	heapify(arr, n, i, conta);
    	conta++;
	}
 
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i], conta);
        conta++;
        heapify(arr, i, 0, conta);
        conta++;
    }
}
