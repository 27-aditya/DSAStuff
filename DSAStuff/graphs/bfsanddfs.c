#include <stdio.h>
#include <stdlib.h>

struct queue{
  int front;
  int rear;
  int size;
  int *Q;
};

void create(struct queue *q, int size){
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (int *)malloc(q->size*sizeof(int));
}

void enqueue(struct queue *q, int x){
  if((q->rear+1)%q->size == q->front)
    printf("Queue is full\n");
  else{
    q->rear = (q->rear+1)%q->size;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct queue *q){
  int x = -1;
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

void bfs(int g[][7], int start, int n){
  int i = start;
  int j;
  struct queue q;
  create(&q, n);
  int visited[7] = {0};

  printf("%d ",i);
  visited[i] = 1;
  enqueue(&q,i);

  while (!isempty(q)){
    i = dequeue(&q);
    for(j = 1; j < n; j++){
      if(g[i][j] == 1 && visited[j] == 0){
        printf("%d ",j);
        visited[j] = 1;
        enqueue(&q, j);
      }
    }
  }
}

void dfs(int g[][7], int start, int n){
  int i = start;
  int j;
  static int visited[7] = {0};
  if(visited[i] == 0){
    printf("%d ",i);
    visited[i] = 1;
    for(j = 1; j < n; j++){
      if(g[i][j] == 1 && visited[j] == 0)
        dfs(g, j, n);
    }
  }
}

int main(){
  int g[7][7] =  {{0,0,0,0,0,0,0},          //           1
                  {0,0,1,1,0,0,0},          //          / /
                  {0,1,0,0,1,0,0},          //         2   3
                  {0,1,0,0,1,0,0},          //           /
                  {0,0,1,1,0,1,1},          //           4
                  {0,0,0,0,1,0,0},          //          /  /
                  {0,0,0,0,1,0,0}};         //          5   6

  bfs(g, 1, 7);
  printf("\n");
  dfs(g, 1, 7);
  return 0;
}