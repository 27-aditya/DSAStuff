#include<stdio.h>

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int main()
{
  int n1 = 10, n2 = 11;
  swap(&n1, &n2);
  printf("%d , %d", n1, n2);
}