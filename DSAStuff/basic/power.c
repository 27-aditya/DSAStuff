#include<stdio.h>

int pow(int m, int n)
{
  if(n == 0)
  {
    return 1;
  }
  return m*pow(m,n-1);
}

int pow1(int m, int n)
{
  if (n == 0)
  {
    return 1;
  }
  if (n%2 == 0)
  {
    return pow1(m*m, n/2);
  }
  else 
    return m*pow(m*m, (n-1)/2);
}

int main()
{
  int r;
  r = pow(2, 9);
  printf("%d",r);
}