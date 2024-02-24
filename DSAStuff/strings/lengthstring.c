#include<stdio.h>

int main()
{
  int i;
  char s[] = "zoro";
  for (i = 0; s[i] != '\0'; i++);
  printf("%d ",i);
}