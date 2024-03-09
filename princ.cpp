#include "generalLibrary.h"
#include "heapsort.h"
#include "insertionSort.h"
#include "merge.h"
#include "quicksort.h"
#include "selectionSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	printf("princ.cpp work!");

	const int ARR_LENGTH = 100;
	const int TEST_QNT = 10000;
	const int ALGORITHM_QNT = 5;

	algorithm finalResult[ALGORITHM_QNT];
	int array[ARR_LENGTH], avarageArray[TEST_QNT], operTemp;
    for(int i = 0; i < TEST_QNT; i++) avarageArray[i] = 0;

	srand(time(NULL));

	for(int i = 0; i < TEST_QNT; i++){
		initialize(array, ARR_LENGTH, &operTemp);
		randomArray(array, ARR_LENGTH, 0, 500);
		heapSort(array, ARR_LENGTH, &operTemp);
		avarageArray[i] = operTemp;
	}
	strcpy(finalResult[0].name, "Heap Sort");
	finalResult[0].points = avarage(avarageArray, TEST_QNT);

	for(int i = 0; i < TEST_QNT; i++){
		initialize(array, ARR_LENGTH, &operTemp);
		randomArray(array, ARR_LENGTH, 0, 500);
		insertionSort(array, ARR_LENGTH, &operTemp);
		avarageArray[i] = operTemp;
	}
	strcpy(finalResult[1].name, "Insertion Sort");
	finalResult[1].points = avarage(avarageArray, TEST_QNT);

	for(int i = 0; i < TEST_QNT; i++){
		initialize(array, ARR_LENGTH, &operTemp);
		randomArray(array, ARR_LENGTH, 0, 500);
		mergeSort(array, 0, ARR_LENGTH - 1);
		// mergeSort(array, 0, ARR_LENGTH - 1, &operTemp); ABDEL INSERISCI LE OPERAZIONI
		avarageArray[i] = operTemp;
	}
	strcpy(finalResult[2].name, "Merge Sort");
	finalResult[2].points = avarage(avarageArray, TEST_QNT);

	for(int i = 0; i < TEST_QNT; i++){
		initialize(array, ARR_LENGTH, &operTemp);
		randomArray(array, ARR_LENGTH, 0, 500);
		quickSort(array, 0, ARR_LENGTH-1, &operTemp);
		avarageArray[i] = operTemp;
	}
	strcpy(finalResult[3].name, "Quick Sort");
	finalResult[3].points = avarage(avarageArray, TEST_QNT);

	for(int i = 0; i < TEST_QNT; i++){
		initialize(array, ARR_LENGTH, &operTemp);
		randomArray(array, ARR_LENGTH, 0, 500);
		selectionSort(array, ARR_LENGTH, &operTemp);
		avarageArray[i] = operTemp;
	}
	strcpy(finalResult[4].name, "Selection Sort");
	finalResult[4].points = avarage(avarageArray, TEST_QNT);

	finalPrettyPrint(finalResult, ALGORITHM_QNT, ARR_LENGTH, TEST_QNT);

	return 0;
}
