#include<stdio.h>

int main()
{
  int arr[5] = {1,3,6,7,8};
  int diff = arr[0] - 0; 
  for (int i = 0; i < 5; i++)
  {
    if (arr[i] - i != diff)
    {
      /*printf("%d\n",i + diff); single missing element
      break;*/
      while (arr[i] - i != diff)
      {
        printf("%d\n",i + diff);
        diff++;
      }
    }
  }
  return;
}