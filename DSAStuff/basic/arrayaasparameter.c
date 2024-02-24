#include<stdio.h>

int * fun(int *arr, int n)
{
  
  for (int i = 0; i < n; i++)
  {
    arr[i] = 0; 
  }
}

int main()
{
  int x[5] = {0,1,2,3,4};
  int *p;
  p = x;
  for (int i = 0; i < 5; i++)
  {
    printf("%d ",x[i]);
  }
  printf("\n");
  fun(x, 5);
  for (int i = 0; i < 5; i++)
  {
    printf("%d ",x[i]);
  }
  
}
