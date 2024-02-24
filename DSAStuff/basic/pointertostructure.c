#include<stdio.h>
#include<stdlib.h>

struct Rectangle
{
  int length;
  int breadth;
};

int main()
{
  struct Rectangle r = {10, 5};
  struct Rectangle *p;
  p = (struct Rectangle *)malloc(sizeof(struct Rectangle));


  p->breadth = 20;
  p->length = 30;

  printf("%d\n",r.breadth);
  printf("%d\n",r.length);
  printf("%d\n",p->breadth);
  printf("%d\n",p->length);
}
