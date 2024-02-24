#include<stdio.h>

int add(int x1, int x2)
{
  int xs = x1 + x2;
  return xs;
}

int main()
{
  int n1 = 23, n2 = 5, sum;
  sum = add(n1, n2);
  printf("%d",sum);
}