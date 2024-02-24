#include<stdio.h>
int main()
{
    int *p;
    int arr[5] = {0,1,2,3,4};
    p = arr;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ",p[i]);
    }
    

}    