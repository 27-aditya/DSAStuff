#include<stdio.h>

int main()
{
  char a[] = "python";
  /*char b[10];
  for (i = 0; a[i] != '\0'; i++);
  i = i-1;
  for (j = 0; i >= 0; i--,j++)
  {
    b[j] = a[i];
  }
  b[j] = '\0';
  printf("%s ",b);*/
  char t;
  int i,j;
  for (j = 0; a[j] != '\0'; j++);
  j = j-1;
  for (i = 0; i < j; i++,j--)
  {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  printf("%s",a);
}