#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

void create(int a[], int n)
{
  int i;
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = a[0];
  first->next = NULL;
  last = first;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = NULL;
    last->next = t;
    last = t; 
  }
}

void create1(int a[], int n)
{
  int i;
  struct Node *t, *last;
  second = (struct Node *)malloc(sizeof(struct Node));
  second->data = a[0];
  second->next = NULL;
  last = second;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = NULL;
    last->next = t;
    last = t; 
  }
}

void create2(int a[], int n)
{
  int i;
  struct Node *t, *last;
  third = (struct Node *)malloc(sizeof(struct Node));
  third->data = a[0];
  third->next = NULL;
  last = third;
  for (i = 1; i < n; i++)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = a[i];
    t->next = NULL;
    last->next = t;
    last = t; 
  }
}

void display(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ",p->data);
    p = p->next;
  }
}

void rdisplay(struct Node *p)
{
  if(p != NULL)
  {
    printf("%d ", p->data);     // exchange the rcall and pf to reverse print the list.
    rdisplay(p->next);
  }
}

int count(struct Node *p)
{
  int l = 0;
  while(p)
  {
    l++;
    p = p->next;    
  }
  return l;
}

int rcount(struct Node *p)
{
  if(p == 0)
    return 0;
  else
    return rcount(p->next) + 1;
}

int sum(struct Node *p)
{
  int sum = 0;
  while (p)
  {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int rsum(struct Node *p)
{
  int sum = 0;
  if(p == NULL)
  {
    return 0;
  }
  else
  {
    return rsum(p->next)+p->data;
  }
}

int findmax(struct Node *p)
{
  int x = -32768;

  while (p)
  {
    if (p->data > x)
      x = p->data;
    p = p->next;
  }
  return x;
}

int rmax(struct Node *p)
{
  int x = -32768;
  if (p == NULL)
  {
    return x;
  }
  x = rmax(p -> next);
  return x > p->data ? x : p->data;
}

struct Node * search(struct Node *p, int key)
{
  while (p != NULL)
  {
    if (p->data == key)
    {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

struct Node * rsearch(struct Node *p, int key)
{
  if (p == NULL)
  {
    return NULL;
  }
  if(key == p->data)
  {
    return p;
  }
  return rsearch(p->next,key);
}

struct Node * mthsearch(struct Node *p, int key) 
{
  struct Node * q = NULL;
  while (p != NULL)
  {
    q = p;
    if (key == p->data)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    p = p->next;
  }
}

void insert(struct Node *p, int index, int x)
{
  if (index < 0 || index > count(p))
    return;
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  if(index == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {
    for (int i = 0; i < index-1; i++)
      p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

void sortedinsert(struct Node *p, int x)
{
  struct Node *t,*q = NULL;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;
  if(first == NULL)
  {
    first = t;
  }
  else
  {
    while (p && p->data < x)
    {
      q = p;
      p = p->next;
    }
    if(p == first)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t; 
    }
  }
}

int delete(struct Node *p, int index)
{
  struct Node *q = NULL;
  int x = -1;

  if (index < 0 || index > count(p))
    return -1;

  if(index == 1)
  {
    q = first;
    x = first->data;  
    first = first->next;
    free(q);
    return x;
  }
  else
  {
    q = NULL;
    for (int i = 0; i < index-1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }
}

int issorted(struct Node *p)
{
  struct Node *q = p;
  int x = -32768;
  while (q != NULL)
  {
    if (q->data < x)
      return -1;
    x = q->data;
    q = q->next;
  }
  return 1;
}

void deleteduplicatessorted(struct Node *p)
{
  struct Node *q = p->next;
  while (q != NULL)
  {
    if (p->data != q->data)
    {
      p = q;
      q = q->next;
    }
    else
    {
      p->next = q->next;
      free(q);
      q = p->next;
    }
  }
}

void emreverse(struct Node *p)
{
  int i = 0;
  int *a;
  a = (int *)malloc(sizeof(int)*count(p));
  struct Node *q;
  q = p;
  while (q != NULL)
  {
    a[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q != NULL)
  {
    q->data = a[i];
    q = q->next;
    i--;
  }
}

void spreverse(struct Node *p)
{
  struct Node *q = NULL;
  struct Node *r = NULL;
  while (p != NULL)
  {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  first = q;
}

void rreverse(struct Node *q, struct Node *p)
{
  if(p != NULL)
  {
    rreverse(p, p->next);
    p->next = q;
  }
  else
    first = q;
}

void concatenate(struct Node *p, struct Node *q)
{
  third = p;
  while (p->next != NULL)
  {
    p = p->next;
  }
  p->next = q;
}

void merge(struct Node *p, struct Node *q)
{
  struct Node *last;
  if (p->data < q->data)
  {
    third = last = p;
    p = p->next;
    third->next = NULL;
  }
  else
  {
    third = last = q;
    q = q->next;
    third->next = NULL;
  }
  while (p && q)
  {
    if (p->data < q->data)
    {
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    }
    else
    {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }  
  if(p)
    last->next = p;
  if(q)
    last->next = q;
}

int isloop(struct Node *p)
{
  struct Node *a, *b;
  a = b = p;
  do
  {
    a = a->next;
    b = b->next;
    b = b != NULL ? b->next : NULL;
  } while (a && b && a != b);
  if (a == b)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void middlenode(struct Node *p)
{
  struct Node *q = p;
  while (q)
  {
    q = q->next;
    if (q)
    {                                        // sc226 finding middle node of linked list
      q = q->next;
    }
    if (q)
    {
      p = p->next;
    }
  }
  printf("%d ",p->data);
}

int main()
{
  struct Node *t1, *t2;
  int arr[] = {1,2,3,4,5};
  create(arr,5);
  int arr1[] = {0,22,34,55,66};
  create1(arr1,5);

  //t1 = first->next->next;
  //t2 = first->next->next->next->next;
  //t2->next = t1; 
  //temp = rsearch(first, 14);
  //rdisplay(first);
  //printf("%d \n",rsearch(first, 14));

  //if (temp)
    //printf("found");
  //else  
    //printf("not found");
  
  //sortedinsert(first,5);
  //delete(first, 5);
  //printf("%d \n",issorted(first));
  //display(first);
  //rreverse(NULL, first);
  //concatenate(first,second);
  //merge(first, second);
  //printf("\n");
  //deleteduplicatessorted(first);
  //display(third);
  //printf("%d \n",isloop(first));
  //display(second);
  middlenode(first);
}