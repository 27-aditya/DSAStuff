#include<stdio.h>

struct Rectangle
{
  int length;
  int breadth;
};

void info(struct Rectangle *r)
{
  r->length = 13;
  r->breadth = 1;
  printf("%d, %d ",r->length, r->breadth);
}

int main()
{
  struct Rectangle p = {12, 4};
  info(&p);
  printf("%d, %d ",p.length, p.breadth);
}
