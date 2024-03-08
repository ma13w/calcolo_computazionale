#include "insertionSort.h"
#include <stdio.h>

int main(){
    int array[] = {2,5,1,10,4,7,8,24};
    int oper = 0, size = 8;
    insertionSort(array, size, &oper);
    printf("size %d; ", size);
    for(int i = 0; i < size; i++) printf("%d ", array[i]);
    printf("\n");
    return 0;
}

