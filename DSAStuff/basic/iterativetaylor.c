#include <stdio.h>

double e(int x, int n)
{
  double s = 1;
  for (n > 0; n = n - 1;)
  {
    s = 1 + x *s/n;
  }
  return s;
}

int main()
{
  printf("%lf\n",e(1,10));
  return 0;
}