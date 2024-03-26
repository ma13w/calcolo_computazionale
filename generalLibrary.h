#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

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

void randomArray(int array[], int length, const int min, const int max){
    for(int i = 0; i < length; i++) array[i] = rand() % (max - min + 1) + min;
}

void initialize(int array[], int length, int *heapOper) {
    for(int i = 0; i < length; i++) array[i] = 0;
    *heapOper = 0;
}

int avarage(int n1, int n2){
    return (n1+n2)/2;
}

void writeArrayIntoFile(char nomeFile[], int array[], int len){
	FILE *file = fopen(nomeFile, "w+");
	for(int i = 0; i < len; i++) fprintf(file, "%d\n", array[i]);
	fclose(file);
}

void readArrayIntoFile(char nomeFile[], int array[], int len){
	FILE *file = fopen(nomeFile, "r");
	int n;
	for(int i = 0; i < len; i++){
		fscanf(file, "%d", &n);
		array[i]=n;
	}
	fclose(file);
}

void finalPrettyPrint(algorithm array[], int length, int arrayLen, int qntTest){
    printf("\n%d test per algoritmo con %d elementi", qntTest, arrayLen);
    for(int i = 0; i < length; i++){
		printf("\n=================================\n");
		printf("%-20s", array[i].name);
		printf("%10d", array[i].points);
	}
}

void orderAlgorithm(algorithm array[], int qntTest){
	char help[20];
	long int temp;
	
	for(int i = 0; i < qntTest; i++){
		for(int j = 0; j < qntTest; j++){
			if(array[i].points > array[j].points){
				temp = array[i].points;
				array[i].points = array[j].points;
				array[j].points = temp;
				
				strcpy(help, array[i].name);
				strcpy(array[i].name, array[j].name);
				strcpy(array[j].name, help);
			}
		}
	}
}
