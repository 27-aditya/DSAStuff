#include <stdio.h>

struct Rectangle
{
  int length;
  int breadth;
};

int main()
{
  struct Rectangle r1 = {3, 1};
  printf("%d",r1.length);
  printf("%d",r1.breadth);
}
