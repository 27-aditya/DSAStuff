#include <stdio.h>
#include <stdlib.h>

int findmax(int arr[], int n){
  int max = -32768;
  for (int i = 0; i < n; i++){
    if(arr[i] > max)
      max = arr[i];
  }
  return max;
}

void countsort(int arr[], int n){
  int mx = findmax(arr, n);
  int *c;
  int i = 0;
  int j = 0;
  c = (int *)malloc(sizeof(int)*(mx+1));
  
  for(int i = 0; i < mx+1;i++)
    c[i] = 0;
  
  for(int i = 0; i < n; i++)
    c[arr[i]]++;
  while(i < mx+1){
    if(c[i] > 0){
      arr[j++] = i;
      c[i]--;
    }
    else
      i++;
  }
}

int main(){
  int arr[] = {3, 7, 9, 10, 8, 6, 1, 5, 2, 4};
  int n = 10;
  countsort(arr, n);
  for (int i = 0; i < n; i++)
    printf("%d ",arr[i]);
  
  return 0;
}