#include<stdio.h>

int main()
{
  //int a[5] = {2,2,3,3,3};
  /*int lastduplicate = 0;
  for (int i = 0; i < 5; i++)
  {
    if (a[i] == a[i+1] && a[i] != lastduplicate)  //displaying duplicate elements  sc124
    {
      printf("duplicate %d\n",a[i]);
      lastduplicate = a[i];
    }
  }*/
  /*int j;
  for (int i = 0; i < 5; i++)
  {
    if (a[i] == a[i+1])
    {                                 // display and number of times appearance sc124
      j = i+1;
      while (a[j] == a[i]) j++;
      printf("%d time %d\n",a[i], j-i);
      i = j-1;
    }
  }*/
  /*int a[10] = {3, 6, 8, 8, 10, 12, 15, 15, 15, 20};
  int h[21] = {0};

  for (int i = 0; i < 10; i++)      // hashing sc125
  {
    h[a[i]]++;
  }
  for (int i = 0; i < 21; i++)
  {
    if(h[i] > 1)printf("%d %d\n",i , h[i]);
  }*/

  /*int a[10] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
  int j, count;
  for (int i = 0; i < 9; i++)
  {
    count = 1;
    if (a[i] != -1)                                      //sc126 in unsorted array
    {
      for (j = i+1; j < 10; j++)
      {
        if (a[i] == a[j])
        {
          count++;
          a[j] = -1;
        }
      }
      if(count > 1) 
        printf("%d, %d\n",a[i], count);
    }
  }*/
  /*
  int a[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};
  int h[17] = {0};

  for (int i = 0; i < 9; i++)                        //sc127 pairs of sum k
  {
    for (int j = i+1; j < 10; j++)
    {
      if(a[j] + a[i] == 10)
      {
        printf("%d, %d\n",a[i], a[j]);
      }
    }
  }
  
  for (int i = 0; i < 10; i++)
  {
    if (h[10-a[i]] != 0 && 10 - a[i] >= 0)
    {
      printf("%d, %d\n",a[i], 10-a[i]);           //hashing pairs
    }
    h[a[i]]++;
  }*/

  /*int a[10] = {1, 3, 4, 5, 6, 8, 9, 10, 12,14};
  int i = 0;
  int j = 10-1;                                //sc128 in sorted array
  while (i < j)
  {
    if(a[i] + a[j] == 10)
    {
      printf("%d %d\n",a[i], a[j]);
      i++;
      j--;
    }
    else if(a[i] + a[j] < 10)
    {
      i++;
    }
    else
      j--;
  }
  */
  /*
  int a[10] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
  int min = a[0];
  int max = a[0];
                                                       // sc129 find min and max in single scan
  for (int i = 1; i < 10; i++)
  {
    if(a[i] < min)
      min = a[i];
    else if(a[i] > max)
      max = a[i];
  }
  printf("%d %d",min, max);
  */
}