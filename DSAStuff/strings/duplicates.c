#include<stdio.h>

int main()
{
  char a[] = "finding";
  int h[26] = {0};
  int i;
  for(i = 0; a[i] != '\0'; i++)
  {
    h[a[i] - 97] += 1;
  }
  /*for(i = 0; i < 26; i++)
  {
    if (h[i] > 1)
    {                                         // method 2
      printf("%c ",i+97);
      printf("%d \n",h[i]);
    }
  }*/

  int j = 0, x = 0;
  for (int i = 0; a[i] != '\0'; i++)
  {
    x = 1;
    x = x << (a[i] - 97);
    if((x&j) > 0)
    {
      printf("%c ",a[i]);
    }
    else
    {
      j = x|j;
    }
  }
}