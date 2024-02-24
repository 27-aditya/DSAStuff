#include<stdio.h>
#include<stdlib.h>

int main()
{
  int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  int *b[3];
  int **c;

  b[0] = (int *)malloc(4*sizeof(int));
  b[1] = (int *)malloc(4*sizeof(int));
  b[2] = (int *)malloc(4*sizeof(int));

  c = (int **)malloc(3*sizeof(int *));
  c[0] = (int *)malloc(4*sizeof(int));
  c[1] = (int *)malloc(4*sizeof(int));
  c[2] = (int *)malloc(4*sizeof(int));

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      c[i][j] = a[i][j];
    }
    //printf("\n");
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%d ",c[i][j]);
    }
    printf("\n");
  }
}