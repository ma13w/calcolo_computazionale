void merge(long long int a[], int p, int q, int r, long long int *conta) {
  int i, j, k=0, b[r];
  i = p;
  j = q+1;
  *conta+=8;
	
  *conta+=2;
  while (i<=q && j<=r) {
  	*conta+=3;
  	
  	*conta+=1;
    if (a[i]<a[j]) {
      b[k] = a[i];
      i++;
      *conta+=2;
    } else {
      b[k] = a[j];
      j++;
      *conta+=2;
    }
    k++; *conta+=1;
  }
  
  *conta+=1;
  while (i <= q) {
  	*conta+=2;
  	
  	*conta+=3;
    b[k] = a[i];
    i++;
    k++;
  }
  
  *conta+=1;
  while (j <= r) {
  	*conta+=2;
  	
  	*conta+=3;
    b[k] = a[j];
    j++;
    k++;
  }
  
  *conta+=1;
  for (k=p; k<=r; k++){
  	*conta+=3;
  	
  	*conta+=2;
    a[k] = b[k-p];
  }
    
  return;
}

void mergeSort(long long int a[], int p, int r, long long int *conta) {
  int q;
  *conta+=1;
  
  *conta+=1;
  if (p < r) {
    q = (p+r)/2; *conta+=3;
    mergeSort(a, p, q, conta); *conta+=1;
    mergeSort(a, q+1, r, conta); *conta+=2;
    merge(a, p, q, r, conta); *conta+=1;
  }
  
  return; 
}
