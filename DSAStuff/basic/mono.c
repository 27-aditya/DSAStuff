#include<stdio.h>

int main()
{
  int len = 0, bread = 0;
  
  // Input values from the user
  scanf("%d", &len);
  scanf("%d", &bread);

  // Calculate area and perimeter
  int area = len * bread;
  int peri = 2 * (len + bread);

  // Print the calculated values
  printf("Area: %d\n", area);
  printf("Perimeter: %d\n", peri);

  return 0;
}
