#include <stdio.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

int partition(int arr[], int l, int h){
  int pivot = arr[l];
  int i = l, j = h;
  
  do{
    do{i++;}while(arr[i] <= pivot);
    do{j--;}while(arr[j] > pivot);
    
    if(i < j)
      swap(&arr[i], &arr[j]);
  }while(i < j);
  
  swap(&arr[l], &arr[j]);
  return j;
}

void quicksort(int arr[], int l, int h){
  int j;
  if(l < h){
    j = partition(arr, l, h);
    quicksort(arr, l, j);
    quicksort(arr, j+1, h);
  }
}

int main(){
  int arr[] = {3, 7, 9, 10, 8, 6, 1, 5, 2, 4, 32768};
  int n = 11;
  quicksort(arr, 0, 10);
  for (int i = 0; i < n-1; i++)
    printf("%d ",arr[i]);
  
  return 0;
}