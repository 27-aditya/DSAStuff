#include <stdio.h>

void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void bubblesort(int arr[], int n){
  int i, j;
  int flag;
  for (i = 0; i < n-1; i++){
    flag = 0;
    for (j = 0; j < n-1-i; j++){
      if(arr[j] > arr[j+1]){
        swap(&arr[j], &arr[j+1]);
        flag = 1;
      }
    }
    if(flag == 0)
      break;
  }
  
}

int main(){
  int arr[] = {3, 7, 9, 10, 8, 6, 1, 5, 2, 4};
  int n = 10;
  bubblesort(arr, n);
  for (int i = 0; i < n; i++)
    printf("%d ",arr[i]);
  
  return 0;
}