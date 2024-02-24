#include <stdio.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selectionsort(int arr[], int n){
  int i, j, k;
  for (i = 0; i < n-1; i++){
    for(j = k = i; j < n; j++){
      if(arr[j] < arr[k])
        k = j;
    }
    swap(&arr[i], &arr[k]);
  }
}

int main(){
  int arr[] = {3, 7, 9, 10, 8, 6, 1, 5, 2, 4};
  int n = 10;
  selectionsort(arr, n);
  for (int i = 0; i < n; i++)
    printf("%d ",arr[i]);
  
  return 0;
}