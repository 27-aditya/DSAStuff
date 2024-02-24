#include<stdio.h>

int main()
{
  /*char a[] = "Painter";
  char b[] = "Painting";

  int i,j;
  for(i=0,j=0; a[i] != '\0', b[j] != '\0'; i++,j++)
  {
    if (a[i] != b[j])
    {
      break;
    }
    if (a[i] = b[j])
    {
      printf("equal ");
    }
    else if(a[i] > b[j])
    {
      printf("bigger ");
    }
    else
    {
      printf("smaller ");
    }
  }*/
  char a[] = "madam";
  int i,j;
  for (i = 0; a[i] !='\0'; i++);
  i = i - 1;
  for (j = 0; j <= i; j++,i--)
  {
    if(a[i] != a[j])
    {
      printf("not ");
    }
    else
      printf("yes");
  }
}