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
/*
quick sort & heap sort: 6907.755279 
*/
int main(){
	printf("princ.cpp work!");

	const int ARR_LENGTH = 100000;
	const int TEST_QNT = 1;
	const int ALGORITHM_QNT = 5;
	const int MIN_VALUE = 0;
	const int MAX_VALUE = 500;

	algorithm finalResult[ALGORITHM_QNT];
	long long int array[ARR_LENGTH], avarageArray[TEST_QNT], operTemp, operTempTemp;
	int progress = 0;
    for(int i = 0; i < TEST_QNT; i++) avarageArray[i] = 0; 

	srand(time(NULL));

	for(int i = 0; i < TEST_QNT; i++){		
		initialize(array, ARR_LENGTH, &operTemp);
		randomArray(array, ARR_LENGTH, MIN_VALUE, MAX_VALUE);
		writeArrayIntoFile("arrayToSort.txt", array, ARR_LENGTH);
		progress++;
		printUploadProgressBar(progress/TEST_QNT);
		
		initialize(array, ARR_LENGTH, &operTemp);
		readArrayIntoFile("arrayToSort.txt", array, ARR_LENGTH);
		heapSort(array, ARR_LENGTH, &operTemp);
		if(i==0) operTempTemp = operTemp;
		else operTempTemp = avarage(finalResult[0].points, operTemp);
		finalResult[0].points = operTempTemp;
		progress++;
		printUploadProgressBar(progress/TEST_QNT);
		
		initialize(array, ARR_LENGTH, &operTemp);
		readArrayIntoFile("arrayToSort.txt", array, ARR_LENGTH);
		insertionSort(array, ARR_LENGTH, &operTemp);
		if(i==0) operTempTemp = operTemp;
		else operTempTemp = avarage(finalResult[1].points, operTemp);
		finalResult[1].points = operTempTemp;
		progress++;
		printUploadProgressBar(progress/TEST_QNT);
		
		initialize(array, ARR_LENGTH, &operTemp);
		readArrayIntoFile("arrayToSort.txt", array, ARR_LENGTH);
		mergeSort(array, 0, ARR_LENGTH - 1, &operTemp);
		if(i==0) operTempTemp = operTemp;
		else operTempTemp = avarage(finalResult[2].points, operTemp);
		finalResult[2].points = operTempTemp;
		progress++;
		printUploadProgressBar(progress/TEST_QNT);
		
		initialize(array, ARR_LENGTH, &operTemp);
		readArrayIntoFile("arrayToSort.txt", array, ARR_LENGTH);
		quickSort(array, 0, ARR_LENGTH-1, &operTemp);
		if(i==0) operTempTemp = operTemp;
		else operTempTemp = avarage(finalResult[3].points, operTemp);
		finalResult[3].points = operTempTemp;
		progress++;
		printUploadProgressBar(progress/TEST_QNT);
		
		initialize(array, ARR_LENGTH, &operTemp);
		readArrayIntoFile("arrayToSort.txt", array, ARR_LENGTH);
		selectionSort(array, ARR_LENGTH, &operTemp);
		if(i==0) operTempTemp = operTemp;
		else operTempTemp = avarage(finalResult[4].points, operTemp);
		finalResult[4].points = operTempTemp;
		progress++;
		printUploadProgressBar(progress/TEST_QNT);
	}
	
	strcpy(finalResult[0].name, "Heap Sort");
	strcpy(finalResult[1].name, "Insertion Sort");
	strcpy(finalResult[2].name, "Merge Sort");
	strcpy(finalResult[3].name, "Quick Sort");
	strcpy(finalResult[4].name, "Selection Sort");

	//printArray(array, ARR_LENGTH);
	orderAlgorithm(finalResult, ALGORITHM_QNT);
	finalPrettyPrint(finalResult, ALGORITHM_QNT, ARR_LENGTH, TEST_QNT);

	return 0;
}
