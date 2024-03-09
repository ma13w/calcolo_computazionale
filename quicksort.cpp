#include "quicksort.h"
#include <stdio.h>

int main(){
	int array[10] = {0,9,8,7,6,5,4,3,2,1};
	int operazioni = 0;

	quickSort(array, 0, 10-1, &operazioni);

	for(int i = 0; i < 10; i++) printf("%d ", array[i]);
	printf("\n\nOperazioni: %d", operazioni);

	return 0;
}
