#include<stdio.h>
#define size 10

int hash(int key){
  return key%size;
}

int probe(int a[], int key){
  int index = hash(key);
  int i = 0;
  while (a[(index+i)%size] != 0){
    i++;
  }
  return (index+i)%size;
}

void insert(int ht[], int key){
  int index = hash(key);

  if(ht[index] != 0){
    index = probe(ht, key);
  }
  ht[index] = key;
}

int search(int a[], int key){
  int index = hash(key);
  int i =0;
  while (a[(index+i)%size] != key){
    i++;
  }
  return (index+i)%size;
}

int main(){
  int ht[10] = {0};
  insert(ht, 12);
  insert(ht, 25);
  insert(ht, 35);
  insert(ht, 26);

  printf("%d ",search(ht, 25));
}