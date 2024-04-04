#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct algorithm{
	char name[20];
	long long int points[100];
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

void finalPrettyPrint(algorithm array[], const int length, const int arrayLen, const int qntTest, int state){
//    printf("\n%d test per algoritmo con %d elementi", qntTest, arrayLen);
	printf("\n%-20s", "Array size");
	for(int i = 10; i <= arrayLen; i*=10) printf("%15llu", i);
    for(int i = 0; i < length; i++){
    	printf("\n");
		for(int j = 0; j < 20+15*state; j++) printf("=");
		printf("\n");
		printf("%-20s", array[i].name);
		for(int k = 0; k < state; k++) printf("%15llu", array[i].points[k]);
	}
}

void finalPrettyPrintIntoFile(algorithm array[], const int length, const int arrayLen, const int qntTest, int state){
	FILE *fp = fopen("calcolo_computazionale_output.txt", "w+");
	fprintf(fp, "\n%-20s", "Array size");
	for(int i = 10; i <= arrayLen; i*=10) fprintf(fp, "%15llu", i);
    for(int i = 0; i < length; i++){
    	fprintf(fp, "%s", "\n");
		for(int j = 0; j < 20+15*state; j++) fprintf(fp, "%s", "=");
		fprintf(fp, "%s", "\n");
		fprintf(fp, "%-20s", array[i].name);
		for(int k = 0; k < state; k++) fprintf(fp, "%15llu", array[i].points[k]);
	}
	fclose(fp);
}

void printUploadProgressBar(int progress, int ARR_LENGTH, int ALGORITHM_QNT){
	int state = 0;
	for(int j = 10; j <= ARR_LENGTH; j*=10) state++;
	state *= ALGORITHM_QNT;
	
	system("cls");
	printf("progress bar\n");
	printf("\n");
	for(int i = 0; i < state; i++) printf("---");
	printf("\n");
	for(int i = 0; i < progress; i++) printf("===");
	printf("\n");
	for(int i = 0; i < state; i++) printf("---");
	printf("\n");
}
