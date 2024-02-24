#include<stdio.h>

int area(int len, int bred)
{
  return len*bred;
}

int perimeter(int len, int bred)
{
  return 2*(len+bred);
}

int main()
{
  int length = 0, breadth = 0;
  int a, p;
  scanf("%d",&length);
  scanf("%d",&breadth);
  a = area(length,breadth);
  p = perimeter(length,breadth);

  printf("%d %d",a,p);
}