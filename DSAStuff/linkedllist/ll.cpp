#include<iostream>

class Node
{
public:
  int data;
  Node *next;
};

class linkedlist
{
private:
  Node *first;
public:
  linkedlist(){first = NULL;}
  linkedlist(int a[], int n);
  ~linkedlist();

  void display();
  void insert(int key, int index);
  int delte(int index);
  int length();
};

linkedlist :: linkedlist(int a[], int n)
{
  Node *last
}

int main()
{
  return 0;
}