void quickSort(int arr[], int low, int high, int *calcolo) {
    if (low < high) {
        int p = partition(arr, low, high, calcolo);

        quickSort(arr, low, p - 1, calcolo);
        quickSort(arr, p + 1, high, calcolo);
    }
}

int partition(int arr[], int low, int high, int *calcolo) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j], calcolo);
        }
    }
    swap(&arr[i + 1], &arr[high], calcolo);
    return i + 1;
}

void swap(int *n1, int *n2, int *calcolo) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    *calcolo += 3;
}
