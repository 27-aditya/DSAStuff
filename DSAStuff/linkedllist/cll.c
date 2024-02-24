#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
}*head;

void create(int a[], int n)
{
  int i;
  struct node *t, *last;
  head = (struct node *)malloc(sizeof(struct node));
  head->data = a[0];
  head->next = head;
  last = head;
  for (int i = 1; i < n; i++)
  {
    t = (struct node *)malloc(sizeof(struct node));
    t->data = a[i];
    t->next = last->next;
    last->next = t;
    last = t;
  }
}

void display(struct node *p)
{
  do
  {
    printf("%d ",p->data);
    p = p->next;
  } while (p != head);
  
}

void rdisplay(struct node *p)
{
  static int flag = 0;
  if (p != head || flag == 0) 
  {
    flag = 1;
    printf("%d ",p->data);
    display(p->next);
  }
}

void insert(struct node *p, int index, int key)
{
  struct node *t;
  int i;
  t = (struct node *)malloc(sizeof(struct node));
  t->data = key;
  if(index == 0)
  {
    if (head == NULL)
    {
      head = t;
      head->next = head;
    }
    else
    {
      p = head;
      while (p->next != head)
      {
        p = p->next;
      }
      p->next = t;
      t->next = head;
      head = t;
    }
  }
  else
  {
    p = head;
    for (int i = 0; i < index-1; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

int length(struct node *p)
{
  int len = 0;
  do
  {
    len++;
    p = p->next;
  } while (p != head);
  return len;  
}

int delete(struct node *p, int index)
{
  struct node *q;
  int i, x;
  if (index == 1)
  {
    while (p->next != head)
      p = p->next;
    x = head->data;
    if (p == head)
    {
      free(head);
      head = NULL;
    }
    else
    {
      p->next = head->next;
      free(head);
      head = p->next;
    }
  }
  else
  {
    for (i = 0; i < index-2; i++)
      p = p->next;
    q = p->next;
    p->next = q->next;
    x = q->data;
    free(q);
  }
  return x;
}

int main()
{
  int a[] = {1,2,3,4,5};
  create(a,5);
  //insert(head, 1, 10);
  delete(head, 2);
  rdisplay(head);
}