#include<stdio.h>
void merge(int arr[], int l, int m, int r, int *oper) {
    int i, j, k;
    (*oper)+=3;
    int n1 = m - l + 1;
    (*oper)+=1;
    int n2 = r - m;
    (*oper)+=1;
 
    // Create temp arrays
    int L[n1], R[n2];
    (*oper)+=2;
    *oper += 2+n1*2;
    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
        (*oper)+=1;
    }
    *oper += 2+n1*2;
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
        (*oper)+=1; // Incrementa il conteggio delle operazioni
    }
 
    // Merge the temp arrays back into arr[l..r]
    i = 0;
    (*oper)++;
    j = 0;
    (*oper)++;
    k = l;
    (*oper)++;
    (*oper)+=2;
    while (i < n1 && j < n2) {
            (*oper)+=1;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            (*oper)++;
            i++;
            (*oper)++;
        } else {
            (*oper)+=2;
            arr[k] = R[j];
            j++;
        }
        k++;
        (*oper)++;
    }
 
    // Copy the remaining elements of L[], if there are any
    (*oper)+=1;
    while (i < n1) {
        
        arr[k] = L[i];
        (*oper)+=1;
        i++;
        (*oper)+=1;
        k++;
        (*oper)++; // Incrementa il conteggio delle operazioni
    }
 
    // Copy the remaining elements of R[], if there are any
    (*oper)+=1;
    while (j < n2) {
        
        arr[k] = R[j];
        (*oper)+=1;
        j++;
        (*oper)+=1;
        k++;
        (*oper)++; // Incrementa il conteggio delle operazioni
    }
}

// l è l'indice sinistro e r è l'indice destro del sotto-array di arr da ordinare
void mergeSort(int arr[], int l, int r, int *oper) {
    (*oper)++;
    if (l < r) {
         // Incrementa il conteggio delle operazioni
        
        int m = l + (r - l) / 2;
        (*oper)++; // Incrementa il conteggio delle operazioni
 
        // Ordina la prima e la seconda metà
        mergeSort(arr, l, m, oper);
        (*oper)+=1;
        mergeSort(arr, m + 1, r, oper);
        (*oper)+=1;
        merge(arr, l, m, r, oper);
        (*oper)++; // Incrementa il conteggio delle operazioni
    }
}