#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
}*first = NULL;

void create(int arr[], int n)
{
  struct node *t, *last;
  int i;

  first = (struct node *)malloc(sizeof(struct node));
  first->data = arr[0];
  first->prev = first->next = NULL;
  last = first;
  
  for (i = 1; i < n; i++)
  {
    t = (struct node *)malloc(sizeof(struct node));
    t->data = arr[i];
    t->next = last->next;
    t->prev = last;
    last->next = t;
    last = t;
  }
}

void display(struct node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}

int length(struct node *p)
{
  int len = 0;
  while (p)
  {
    len++;
    p = p->next;
  }
  return len;
}

void insert(struct node *p, int index, int key)
{
  struct node *t;
  int i;

  if (index < 0 || index > length(p))
    return;  
  t = (struct node *)malloc(sizeof(struct node));
  t->data = key;


  if (index == 0)
  {
    t->prev = NULL;
    t->next = first;
    first->prev = t;
    first = t;
  }
  else
  {
    for (i = 0; i < index-1; i++)
      p = p->next;
    t->prev = p;
    t->next = p->next;
    if(p->next) p->next->prev = t;
    p->next = t;
  }
}

int delete(struct node *p, int index)
{
  struct node *q;
  int x;
  if(index < 1 || index > length(p))
    return -1;

  if(index == 1)
  {
    q = p;
    p = p->next;
    if(p) p->prev = NULL;
    x = p->data;
    free(p);
  }
  else
  {
    for (int i = 0; i < index-1; i++)
      p = p->next;
    p->prev->next = p->next;
    if (p->next)
    {
      p->next->prev = p->prev;
    }
    x = p->data;
    free(p); 
  }
  return x;
}

void reverse(struct node *p)
{
  struct node *temp;
  while (p)
  {
    temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;
    if (p != NULL && p->next == NULL)
      first = p;
  }
  
}

int main()
{
  int a[5] = {1,2,3,4,5};
  create(a, 5);
  //insert(first, 3, 0);
  //delete(first, 2);
  reverse(first);
  display(first);
  return 0;
}