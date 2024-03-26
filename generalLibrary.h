#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct algorithm{
	char name[20];
	long long int points;
};

void swap(long long int *n1, long long int *n2, long long int *calc) {
    long long int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
    *calc += 3;
}

void printArray(long long int arr[], const int length){
    printf("\n");
    for(int i = 0; i < length; i++) printf("%d |", arr[i]);
    printf("\n");
}

void randomArray(long long int array[], const int length, const int min, const int max){
    for(int i = 0; i < length; i++) array[i] = rand() % (max - min + 1) + min;
}

void initialize(long long int array[], const int length, long long int *heapOper) {
    for(int i = 0; i < length; i++) array[i] = 0;
    *heapOper = 0;
}

long long int avarage(long long int n1, long long int n2){
    return (n1+n2)/2;
}

void writeArrayIntoFile(char nomeFile[], long long int array[], const int len){
	FILE *file = fopen(nomeFile, "w+");
	for(int i = 0; i < len; i++) fprintf(file, "%d\n", array[i]);
	fclose(file);
}

void readArrayIntoFile(char nomeFile[], long long int array[], const int len){
	FILE *file = fopen(nomeFile, "r");
	long long int n;
	for(int i = 0; i < len; i++){
		fscanf(file, "%d", &n);
		array[i]=n;
	}
	fclose(file);
}

void finalPrettyPrint(algorithm array[], const int length, const int arrayLen, const int qntTest){
    printf("\n%d test per algoritmo con %d elementi", qntTest, arrayLen);
    for(int i = 0; i < length; i++){
		printf("\n=================================\n");
		printf("%-20s", array[i].name);
		printf("%10llu", array[i].points);
	}
}

void orderAlgorithm(algorithm array[], const int algTest){
	char help[20];
	long long int temp;
	
	for(int i = 0; i < algTest-1; i++){
		for(int j = i+1; j < algTest; j++){
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

void printUploadProgressBar(int progress){
	system("cls");
	
	printf("progress bar\n------------------\n");
	for(int i = 0; i < progress; i++) printf("|||");
	printf("\n------------------\n");
}
