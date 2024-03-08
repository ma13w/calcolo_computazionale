#include<stdio.h>
#include"selectionSort.h"

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int dim = 5, operazioni=0;
    selectionSort(arr, dim, &operazioni);
    printf("Array ordinato: \n");
    for(int i=0;i<5;i++) printf("%d-", arr[i]);
    return 0;
}
