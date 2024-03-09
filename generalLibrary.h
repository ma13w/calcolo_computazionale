#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct algorithm{
	char name[20];
	int points;
};

void swap(int *n1, int *n2, int *calc) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    *calc += 3;
}

void printArray(int arr[], int length){
    printf("\n");
    for(int i = 0; i < length; i++) printf("%d |", arr[i]);
    printf("\n");
}

void randomArray(int array[], int length, int min, int max){
    for(int i = 0; i < length; i++) array[i] = rand() % (max - min + 1) + min;
}

void initialize(int array[], int length, int *heapOper) {
    for(int i = 0; i < length; i++) array[i] = 0;
    *heapOper = 0;
}

int avarage(int array[], int length){
    int avarage = 0;
    for(int i = 0; i < length; i++) avarage += array[i];
    return avarage / length;
}

void finalPrettyPrint(algorithm array[], int length, int arrayLen, int qntTest){
    printf("\n%d test per algoritmo con %d elementi", qntTest, arrayLen);
    for(int i = 0; i < length; i++){
		printf("\n=================================\n");
		printf("%-20s", array[i].name);
		printf("%10d", array[i].points);
	}
}