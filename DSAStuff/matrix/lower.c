#include <stdio.h>
#include <stdlib.h>
// this implementation is for row major 
// as for column major put index as n*(j-1)+(j-2)(j-1)/2 + (i-j)
struct matrix
{
  int *a;
  int n;
};

void set(struct matrix *m,int i,int j,int x)
{
  if(i >= j){
    m->a[i*(i-1)/2+j-1] = x;
  }
}

int get(struct matrix m,int i,int j)
{
  if(i >= j)
    return m.a[i*(i-1)/2+j-1];
  else
    return 0;
}

void display(struct matrix m)
{
  int i,j;
  for(i=1;i<=m.n;i++)
  {
    for(j=1;j<=m.n;j++){
    if(i >= j)
      printf("%d ",m.a[i*(i-1)/2+j-1]);
    else
      printf("0 ");
    }
    printf("\n");
  }
}

int main(){
  struct matrix m;
  m.n = 4;
  m.a = (int *)malloc(sizeof(int)* m.n * (m.n + 1) / 2);
  int x;
  for (int i = 1; i <= m.n; i++){
    for (int j = 1; j <= m.n; j++){
      scanf("%d",&x);
      set(&m, i, j, x);
    }
  }
  printf("\n");
  display(m);
  return 0;
}