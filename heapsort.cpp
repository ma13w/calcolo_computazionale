#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void duplicatore(FILE *original_file, FILE *new_file);

int main(){
	char nomeFile[100];
	FILE *original_file, *new_file;
	char nomeFileCopia[100]={"_Copia"};
	
	printf("Inserisci il nome del file:");
	scanf("%s", &nomeFile);
	
	if(!strstr(nomeFile, ".txt"))  strcat(nomeFile, ".txt");
	original_file=fopen(file_nome, "r");
	
	if(original_file == NULL){
		printf("\nImpossibile aprire il file%s\n")
		return 1;
	}
	
	strcat(nomeFileCopia, nomeFile);
	new_file= fopen(nomeFileCopia, "w+");
	
	if(new_file == NULL){
		printf("\nImpossibile aprire il file%s\n")
		return 1;
	}
	
	duplicatore(original_file, new_file);
	
	printf("\nDuplicazione effettuata: %s", nomeFileCopia);
	
	fclose(original_file);
	fclose(new_file);
	return 0;
}

void duplicatore(FILE *original_file, FILE *new_file){
	char stringa[];
	while(!feof(original_file)){
		fscanf(original_file, "%c", &carattere);
		fprintf(new_file, "%c", &carattere);
	}
}
