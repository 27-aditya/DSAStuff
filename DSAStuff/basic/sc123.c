#include<stdio.h>

int main()
{
  int arr1[11] = {0};
  int arr[7] = {2,4,5,7,8,10,1};
  
  for (int i = 0; i < 7; i++)
  {
    arr1[arr[i]]++;
  }
  for (int i = 1; i < 11; i++)
  {
    if (arr1[i] == 0)
    {
      printf("%d\n",i);
    }
  }
}