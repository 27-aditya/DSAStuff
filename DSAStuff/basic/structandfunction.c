#include<stdio.h>
struct Rectangle
{
  int length;
  int breadth;
};

void initialise(struct Rectangle *r, int l, int b)
{
  r->length = l;
  r->breadth = b;
}

int area(struct Rectangle r)
{
  return r.length*r.breadth;
}

int perimeter(struct Rectangle r)
{
  return 2*(r.length+r.breadth);
}

int main()
{
  struct Rectangle r;
  int l = 0, b = 0;
  int a, p;
  scanf("%d",&l);
  scanf("%d",&b);
  initialise(&r, l, b);
  a = area(r);
  p = perimeter(r);

  printf("%d %d",a,p);
}