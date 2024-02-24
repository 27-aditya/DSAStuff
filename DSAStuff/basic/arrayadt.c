#include<stdio.h>
#include<stdlib.h>

struct Array
{
  int *a;
  //int a[10];
  int size;
  int length;
};

void swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void display(struct Array arr)
{
  int i;
  printf("\nElements are \n");
  for (i = 0; i < arr.length; i++)
  {
    printf("%d ",arr.a[i]);
  }
  printf("\n");
}

void append(struct Array *arr, int x)
{
  if(arr->length < arr->size)
    {
      arr->a[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x)
{
  if(index >= 0 && index <= arr->length)
  {
    for (int i = arr->length; i > index; i--)
    {
      arr->a[i] = arr->a[i-1];
    }
    arr->a[index] = x;
    arr->length++;
  }
}

int delete(struct Array *arr, int index)
{
  if (index >= 0 && index < arr->length)
  {
    int x = arr->a[index];
    for (int i = index; i < arr->length; i++)
    {
      arr->a[i] = arr->a[i+1];
    }
    arr->length--;
    return x;
  }
  return 0;
}

int linearsearch(struct Array *arr, int key)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (key == arr->a[i])
    {
      swap(&arr->a[i],&arr->a[0]); // Move to front
      //swap(&arr->a[i],&arr->a[i-1]); // Transposition
      return i;  // just return statement normal linear search
    }
  }
  return -1;
}

int binarysearch(struct Array a,int key)
{
  int l,h;
  l = 0;
  h = a.length-1;
  int mid;

  while (l <= h)
  {
    mid = (l+h)/2;
    if(key == a.a[mid])
    {
      return mid;
    }
    else if(key < a.a[mid])
    {
      h = mid-1;
    }
    else
    {
      l = mid+1;
    }
  }
  return -1;
}

int rbinarysearch(int a[], int l, int h, int key)
{
  int mid;
  if (l <= h)
  {
    mid = (l+h)/2;
    if(key == a[mid])
    {
      return mid;
    }
    else if (key < a[mid])
    {
      return rbinarysearch(a, l, mid-1, key);
    }
    else
    {
      return rbinarysearch(a, mid+1, h, key);
    }
  }
  return -1;
}

int get(struct Array arr, int index)
{
  if(index >= 0 && index < arr.length)
  {
    return arr.a[index];
  }
}

void set(struct Array *arr, int index, int x)
{
  if(index >= 0 && index < arr->length)
  {
    arr->a[index] = x;
  }
}

int findmax(struct Array arr)
{
  int max = arr.a[0];
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.a[i] > max)
    {
      max = arr.a[i];
    }
    return max;
  }
}

int findmin(struct Array arr)
{
  int min = arr.a[0];
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.a[i] < min)
    {
      min = arr.a[i];
    }
    return min;
  }
}

int sum(struct Array arr)
{
  int sum = 0;
  for (int i = 0; i < arr.length; i++)
  {
    sum += arr.a[i];
  }
  return sum;
}

float avg(struct Array arr)
{
  return (float)sum(arr)/arr.length;
}

void reverse(struct Array *arr) 
{
  int *b;
  int i, j;
  b = (int *)malloc(arr->length*sizeof(int));

  for (i = arr->length-1, j = 0; i >= 0; i--,j++)
  {
    b[j] = arr->a[i];
  }
  for (int i = 0; i < arr->length; i++)
  {
    arr->a[i] = b[i];
  }
}

void reverse2(struct Array *arr)
{
  int temp, i, j;
  for (i = 0, j = arr->length-1; i < j; i++,j--)
  {
    temp = arr->a[i];
    arr->a[i] = arr->a[j];
    arr->a[j] = temp;
  }
}

void insertsort(struct Array *arr, int x)
{
  int i = arr->length-1;
  if(arr->length == arr->size)
    return;

  while (i >= 0 && x < arr->a[i])
  {
    arr->a[i+1] = arr->a[i];
    i--;
  }
  arr->a[i+1] = x;
  arr->length++;
}

int issorted(struct Array arr)
{
  for (int i = 0; i < arr.length-1; i++)
  {
    if (arr.a[i] > arr.a[i])
    {
      return 0;
    }
    return 1;
  }
}

void rearrange(struct Array *arr)
{
  int i = 0, j = arr->length-1;
  while (i < j)
  {
    while (arr->a[i] < 0)
    {
      i++;
    }
    while (arr->a[j] >= 0)
    {
      j--;
    }
    if(i < j)
    {
      swap(&arr->a[i], &arr->a[j]);
    }
  }
  
}

struct Array* merge(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->a[i] < arr2->a[j])
    {
      arr3->a[k++] = arr1->a[i++];
    }
    else
    {
      arr3->a[k++] = arr2->a[j++];
    }
  }

  for (; i < arr1->length; i++)
  {
    arr3->a[k++] = arr1->a[i];
  }

  for (; j < arr1->length; j++)
  {
    arr3->a[k++] = arr2->a[j];
  } 
  arr3->length = arr1->length + arr2->length;
  arr3->size = 20;
  return arr3;
}

struct Array* Union(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->a[i] < arr2->a[j])
    {
      arr3->a[k++] = arr1->a[i++];
    }
    else if(arr2->a[j] < arr1->a[i])
    {
      arr3->a[k++] = arr2->a[j++];
    }
    else
    {
      arr3->a[k++] = arr1->a[i++];
      j++;
    }
  }

  for (; i < arr1->length; i++)
  {
    arr3->a[k++] = arr1->a[i];
  }

  for (; j < arr1->length; j++)
  {
    arr3->a[k++] = arr2->a[j];
  } 
  arr3->length = k;
  arr3->size = 20;
  return arr3;
}

struct Array* intersection(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->a[i] < arr2->a[j])
    {
      i++;
    }
    else if(arr2->a[j] < arr1->a[i])
    {
      j++;
    }
    else if(arr1->a[i] == arr2->a[j]) 
    {
      arr3->a[k++] = arr1->a[i++];
      j++;
    }
  }

  arr3->length = k;
  arr3->size = 20;
  return arr3;
}

struct Array* difference(struct Array *arr1, struct Array *arr2)
{
  int i = 0, j = 0, k = 0;
  struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

  while (i < arr1->length && j < arr2->length)
  {
    if (arr1->a[i] < arr2->a[j])
    {
      arr3->a[k++] = arr1->a[i++];
    }
    else if(arr2->a[j] < arr1->a[i])
    {
      j++;
    }
    else
    {
      i++;
      j++;
    }
  }

  for (; i < arr1->length; i++)
  {
    arr3->a[k++] = arr1->a[i];
  }
 
  arr3->length = k;
  arr3->size = 20;
  return arr3;
}

int main()
{
  //struct Array arr = {{-1,2,3,-22,4,15,60,-4}, 20, 8};
  //struct Array arr1 = {{2, 3, 4, 5, 6}, 10, 5};
  //struct Array arr2 = {{1, 3, 5, 9, 10}, 10, 5};
  //struct Array *arr3;

  //arr.number = n;
  //append(&arr, 16);
  //insert(&arr, 12, 10);
  //printf("%d\n",linearsearch(&arr,6));
  //printf("%d\n",rbinarysearch(arr.a, 0, arr.length-1, 3));
  //reverse2(&arr);
  //insertsort(&arr,11);
  //printf("%d\n", issorted(arr));
  //rearrange(&arr);
  //arr3 = merge(&arr1, &arr2);
  //arr3 = Union(&arr1, &arr2);
  //arr3 = intersection(&arr1, &arr2);
  //arr3 = difference(&arr1, &arr2);
  //display(*arr3);
}