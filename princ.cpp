#include "generalLibrary.h"
#include "heapsort.h"
#include "insertionSort.h"
#include "merge.h"
#include "quicksort.h"
#include "selectionSort.h"
#include "bubble.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
	printf("princ.cpp work!");

	const int ARR_LENGTH = 10000; // max value 10.000 -> buffer overflow
	const int TEST_QNT = 3; // quantità di test - media tra i test fatti
	const int ALGORITHM_QNT = 6; // quantità algoritmi
	const int MIN_VALUE = 0; // valore minimo nel caricamento dell'array
	const int MAX_VALUE = 5000; // valore massimo nel caricamento dell'array

	algorithm finalResult[ALGORITHM_QNT];
	long long int array[ARR_LENGTH], avarageArray[TEST_QNT], operTemp, operTempTemp;
	int progress = 0, state = 0;
	
    for(int i = 0; i < TEST_QNT; i++) avarageArray[i] = 0; 

	srand(time(NULL));
	for(int j = 10; j <= ARR_LENGTH; j*=10){
		for(int i = 0; i < TEST_QNT; i++){		
			initialize(array, j, &operTemp);
			randomArray(array, j, MIN_VALUE, MAX_VALUE);
			writeArrayIntoFile("arrayToSort.txt", array, j);
			
			printf("\nheapSort");
			initialize(array, j, &operTemp);
			readArrayIntoFile("arrayToSort.txt", array, j);
			heapSort(array, j, &operTemp);
			if(i==0) operTempTemp = operTemp;
			else operTempTemp = avarage(finalResult[0].points[state], operTemp);
			finalResult[0].points[state] = operTempTemp;
			progress++;
			printUploadProgressBar(progress/TEST_QNT, ARR_LENGTH, ALGORITHM_QNT);
			
			printf("\ninsertionSort");
			initialize(array, j, &operTemp);
			readArrayIntoFile("arrayToSort.txt", array, j);
			insertionSort(array, j, &operTemp);
			if(i==0) operTempTemp = operTemp;
			else operTempTemp = avarage(finalResult[1].points[state], operTemp);
			finalResult[1].points[state] = operTempTemp;
			progress++;
			printUploadProgressBar(progress/TEST_QNT, ARR_LENGTH, ALGORITHM_QNT);
			
			printf("\nmergeSort");
			initialize(array, j, &operTemp);
			readArrayIntoFile("arrayToSort.txt", array, j);
			mergeSort(array, 0, j - 1, &operTemp);
			if(i==0) operTempTemp = operTemp;
			else operTempTemp = avarage(finalResult[2].points[state], operTemp);
			finalResult[2].points[state] = operTempTemp;
			progress++;
			printUploadProgressBar(progress/TEST_QNT, ARR_LENGTH, ALGORITHM_QNT);
			
			printf("\n%s", "quickSort");
			initialize(array, j, &operTemp);
			readArrayIntoFile("arrayToSort.txt", array, j);
			quickSort(array, 0, j-1, &operTemp);
			if(i==0) operTempTemp = operTemp;
			else operTempTemp = avarage(finalResult[3].points[state], operTemp);
			finalResult[3].points[state] = operTempTemp;
			progress++;
			printUploadProgressBar(progress/TEST_QNT, ARR_LENGTH, ALGORITHM_QNT);
			
			printf("\n%s", "selectionSort");
			initialize(array, j, &operTemp);
			readArrayIntoFile("arrayToSort.txt", array, j);
			selectionSort(array, j, &operTemp);
			if(i==0) operTempTemp = operTemp;
			else operTempTemp = avarage(finalResult[4].points[state], operTemp);
			finalResult[4].points[state] = operTempTemp;
			progress++;
			printUploadProgressBar(progress/TEST_QNT, ARR_LENGTH, ALGORITHM_QNT);
			
			printf("\n%s", "bubbleSort");
			initialize(array, j, &operTemp);
			readArrayIntoFile("arrayToSort.txt", array, j);
			bubbleSort(array, j, &operTemp);
			if(i==0) operTempTemp = operTemp;
			else operTempTemp = avarage(finalResult[5].points[state], operTemp);
			finalResult[5].points[state] = operTempTemp;
			progress++;
			printUploadProgressBar(progress/TEST_QNT, ARR_LENGTH, ALGORITHM_QNT);
		}
		
		state++;
	}
	
	strcpy(finalResult[0].name, "Heap Sort");
	strcpy(finalResult[1].name, "Insertion Sort");
	strcpy(finalResult[2].name, "Merge Sort");
	strcpy(finalResult[3].name, "Quick Sort");
	strcpy(finalResult[4].name, "Selection Sort");
	strcpy(finalResult[5].name, "Bubble Sort");
	
	finalPrettyPrint(finalResult, ALGORITHM_QNT, ARR_LENGTH, TEST_QNT, state);
	finalPrettyPrintIntoFile(finalResult, ALGORITHM_QNT, ARR_LENGTH, TEST_QNT, state);

	return 0;
}
