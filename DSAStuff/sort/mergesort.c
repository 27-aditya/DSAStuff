#include <stdio.h>

void merge(int arr[], int l, int mid, int h){
  int i, j, k;
  int b[100];
  i = l; j = mid+1; k = l;
  while(i <= mid && j <= h){
    if(arr[i] < arr[j])
      b[k++] = arr[i++];
    else 
      b[k++] = arr[j++];
  }
  for(;i <= mid; i++)
    b[k++] = arr[i];
  for(;j <= h; j++)
    b[k++] = arr[j];

  for(int a = l; a <= h; a++)
    arr[a] = b[a];
}

void imergersort(int arr[], int n){
  int p, i, l, mid, h;
  for(p = 1; p <= n; p = p*2){
    for(i = 0; i+p-1<n; i = i+p){
      l = i;
      h = i+p-1;
      mid = (l+h)/2;
      merge(arr, l, mid, h);
    }
  }
  if(p/2 < n)
    merge(arr, 0, p/2-1, n-1);
}

void rmergesort(int arr[], int l, int h){
  int mid;
  if(l < h){
    mid = (l+h)/2;
    rmergesort(arr, l, mid);
    rmergesort(arr, mid+1, h);
    merge(arr, l, mid, h);
  }
}

int main(){
  int arr[] = {3, 7, 9, 10, 8, 6, 1, 5, 2, 4};
  int n = 10;
  rmergesort(arr, 0, n-1);
  for (int i = 0; i < n; i++)
    printf("%d ",arr[i]);
  
  return 0;
}