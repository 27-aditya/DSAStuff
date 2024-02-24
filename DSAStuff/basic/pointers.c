#include<stdio.h>

int main()
{
  int arr[5] = {0,1,2,3,4};
  int *p;
  p = arr;
  int n = 5;
  while (n>0)
  {
    printf("%d",p);
    n--;
  }
  
}