#include<stdio.h>
void swap(char *a, char *b)
{
  char temp = *a;
  *a =  *b;
  *b = temp;
}

void perm1(char s[], int k)
{
  static int a[10];
  static char res[10];
  int i;
  if(s[k] == '\0')
  {
    res[k] = '\0';
    printf("%s ",res);
  }
  else
  {
    for (i = 0; s[i] != '\0'; i++)
    {
      if (a[i] == 0)
      {
        res[k] = s[i];
        a[i] = 1;
        perm1(s,k+1);
        a[i] = 0;
      }
    }
  }
}

void perm2(char s[],int l, int h)
{
  int i;
  if (l == h)
  {
    printf("%s ",s);
  }
  else
  {
    for ( i = l; i <= h; i++)
    {
      swap(&s[l], &s[i]);
      perm2(s,l+1,h);
      swap(&s[l], &s[i]);
    } 
  }
}

int main()
{
  char a[] = "abc";
  perm2(a, 0, 2);
}