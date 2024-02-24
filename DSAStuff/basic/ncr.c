#include<stdio.h>

int ncr(int n, int r)
{
  if (r == 0 || n == r)
  {
    return 1;
  }
  return ncr(n-1, r-1)+ ncr(n-1, r);
}

int main()
{
  printf("%d \n", ncr(4,3));
}