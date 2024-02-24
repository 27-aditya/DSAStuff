#include<stdio.h>
#include<stdlib.h>

int main()
{
  int a[5] = {1,2,3,4,5};
  int *p;
  p = (int *)malloc(5*sizeof(int));

  p[0] = 1;
  p[1] = 2;
  p[2] = 3;
  p[3] = 4;
  p[4] = 5;

  for (int i = 0; i < 5; i++)
  {
    printf("%d ",a[i]);
  }
  printf("\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%d ",p[i]);
  }
}