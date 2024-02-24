#include<stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node *lchild;
  struct node *rchild;
};

struct node *root = NULL;

struct queue{
  int front;
  int rear;
  int size;
  struct node **Q;
};

struct stack{
  int size;
  int top;
  struct node **s;
};

void create(struct queue *q, int size){
  q->size = size;
  q->front = q->rear = 0;//q->front = q->rear = -1; normal queue
  q->Q = (struct node **)malloc(q->size*sizeof(struct node *));
}

void enqueue(struct queue *q, struct node * x){
  if((q->rear+1)%q->size == q->front)
    printf("Queue is full\n");
  else{
    q->rear = (q->rear+1)%q->size;
    q->Q[q->rear] = x;
  }
}

struct node *dequeue(struct queue *q){
  struct node* x = NULL;
  if(q->rear == q->front)
    printf("Queue is empty\n");
  else{
    q->front = (q->front+1)%q->size;
    x = q->Q[q->front];
  }
  return x;
}

int isempty(struct queue q){
  return q.front == q.rear;
}

void stkcreate(struct stack *st, int size){
  st->size = size;
  st->top = -1;
  st->s = (struct node **)malloc(st->size*sizeof(struct node *));
}

void push(struct stack *st, struct node *x){
  if (st->top == st->size-1){
    printf("Stack Overflow\n");
  }
  else{
    st->top++;
    st->s[st->top] = x;
  }
}

struct node *pop(struct stack *st){
  struct node *x = NULL;
  if(st->top == -1){
    printf("Stack Underflow\n");
  }
  else{
    x = st->s[st->top];
    st->top--;
  }
  return x;
}


void createtree(){
  struct node *p,*t;
  int x;
  struct queue q;
  create(&q,100);

  printf("Enter the root value");
  scanf("%d",&x);
  root = (struct node *)malloc(sizeof(struct node));
  root->data = x;
  root->lchild = root->rchild = NULL;

  enqueue(&q, root);
  while(!isempty(q)){
    p = dequeue(&q);
    printf("Enter the left child value of %d",p->data);
    scanf("%d",&x);
    if (x != -1){
      t = (struct node *)malloc(sizeof(struct node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      enqueue(&q, t);
    }
    printf("Enter the right child value of %d",p->data);
    scanf("%d",&x);
    if (x != -1){
      t = (struct node *)malloc(sizeof(struct node));
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      enqueue(&q, t);
    }
  }
}

int stkisempty(struct stack st){
  if(st.top == -1)
    return 1;
  return 0;
}

int stkisfull(struct stack st){
  return st.top ==  st.size-1;
}

void preorder(struct node* root){
  if(root){
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void inorder(struct node* root){
  if(root){
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
  }
}

void postorder(struct node* root){
  if(root){
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
  }
}

void ipreorder(struct node *p){
  struct stack st;
  stkcreate(&st,100);
  
  while(p || !stkisempty(st)){
    if(p){
      printf("%d ",p->data);
      push(&st, p);
      p = p->lchild;
    }
    else{
      p = pop(&st);
      p = p->rchild;
    }
  }
}

void iinorder(struct node *p){
  struct stack st;
  stkcreate(&st,100);
  
  while(p || !stkisempty(st)){
    if(p){
      push(&st, p);
      p = p->lchild;
    }
    else{
      p = pop(&st);
      printf("%d ",p->data);
      p = p->rchild;
    }
  }
}

void levelorder(struct node *p){
  struct queue q;
  create(&q, 100);
  printf("%d ",p->data);
  enqueue(&q, p);
  while (!isempty(q)){
    p = dequeue(&q);
    if(p->lchild){
      printf("%d ",p->lchild->data);
      enqueue(&q, p->lchild);
    }
    if(p->rchild){
      printf("%d ",p->rchild->data);
      enqueue(&q, p->rchild);
    }
  }
}

int count(struct node *p){
  int x, y;
  if(p != NULL){
    x = count(p->lchild);
    y = count(p->rchild);
    return x+y+1;
  }
  return 0;
}

int height(struct node *p){
  int x, y;
  if(p != NULL){
    x = count(p->lchild);
    y = count(p->rchild);
    if (x > y){
      return x+1;
    }
    else{
      return y+1;
    }
  }
  return 0;
}

int main(){
  createtree();
  levelorder(root);
  printf("\n%d ",height(root));
  //inorder(root);
  //postorder(root);
}