#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
  int temp=*x;
  *x=*y;
  *y=temp;
}

void shellsort(int arr[],int n){
  int gap, i, j, temp;

  for(gap=n/2; gap>=1; gap/=2){
    for(i=gap; i<n; i++){
      temp = arr[i];
      j=i-gap;
      
      while(j>=0 && arr[j]>temp){
        arr[j+gap] = arr[j];
        j=j-gap;
      }
      
      arr[j+gap]=temp;
    }
  }
}

int main(){
  int arr[]={2, 7, 3, 9, 10, 1, 5, 4, 6, 8},n=10,i;

  shellsort(arr,n);
  for(i=0;i<10;i++)
    printf("%d ",arr[i]);
  printf("\n");
  
  return 0;
}