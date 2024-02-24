#include <stdio.h>

void insert(int h[], int n){
  int temp, i = n;
  temp = h[n];
  while (i > 1 && temp > h[1/2]){
    h[i] = h[i/2];
    i = i/2;
  }
  h[i] = temp;
}

void createmaxheap(int h[]){
  for (int i = 2; i < 8; i++)
  {
    insert(h, i);
  }
}

int delete(int h[], int n){
  int i, j, x, val, temp;
  val = h[1];
  h[1] = h[n];
  h[n] = val;
  i = 1;
  j = 2*i;
  while(j < n-1){
    if(h[j+1] > h[j])
      j = j+1;
    if(h[i] < h[j]){
      temp = h[i];
      h[i] = h[j];
      h[j] = temp;
      i = j;
      j = 2*j;
    }
    else
      break;
  }
  return val;
}

void heapsort(int h[], int n){
  for (int i = n; i > 1; i--){
    delete(h, i);
  }
}

int main(){
  int h[] = {0,2,5,8,9,4,7,10};
  createmaxheap(h);
  //printf("%d ",delete(h, 7));
  heapsort(h, 7);
  for (int i = 0; i < 8; i++){
    printf("%d ",h[i]);
  }
  
  return 0;
}