#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

void sortedinsert(struct Node **H,int x)
{
  struct Node *t,*q=NULL,*p=*H;

  t=(struct Node*)malloc(sizeof(struct Node));
  t->data=x;
  t->next=NULL;

  if(*H==NULL)
    *H=t;
  else{
    while(p && p->data<x){
      q=p;
      p=p->next;
    }
    if(p==*H){
      t->next=*H;
      *H=t;
    }
    else{
      t->next=q->next;
      q->next=t;
    }
  }
}
struct Node *search(struct Node *p,int key)
{
  while(p!=NULL){
    if(key==p->data){
      return p;
    }
    p=p->next;
  }
  return NULL;
}

int hash(int key){
  return key%10;
}

void insert(struct Node *ht[], int key){
  int index = hash(key);
  sortedinsert(&ht[index], key);
}

int main(){
  struct Node *ht[10];
  struct Node *temp;
  for (int i = 0; i < 10; i++){
    ht[i] = NULL;
  }
  insert(ht, 12);
  insert(ht, 22);
  insert(ht, 42);
  temp = search(ht[hash(22)], 22);
  printf("%d ",temp->data);
}