#include<stdio.h>

int main()
{
  char a[] = "How are you";
  int i = 0, ccount = 0, vcount = 0, words = 1;
  for (int i = 0; a[i] != '\0'; i++)
  {
    if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
    {
      vcount++;
    }
    if ((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122))
    {
      ccount++;
    }    
    if (a[i] == ' ' && a[i-1] != ' ')
    {
      words++;
    }
  }
  printf("%d ",vcount);
  printf("%d ",ccount);
  printf("%d ",words);
}