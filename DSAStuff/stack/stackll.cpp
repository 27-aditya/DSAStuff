#include<iostream>
using namespace std;

class node{
  public:
    int data;
    node *next;
};

class stack{
  private:
    node *top;
  public:
    stack(){top = NULL;}
    void push(int x);
    int pop();
    void display();
};

void stack :: push(int x){
  node *t = new node;
  if(t == NULL)
    cout <<"stack is full" << endl;
  else{
    t->data = x;
    t->next = top;
    top = t;
  }
}

int stack :: pop(){
  int x = -1;
  if(top == NULL){
    cout <<"stack is empty\n" << endl;
  }
  else{
    x = top->data;
    node *t = top;
    top = top->next;
    delete t;
  }
  return x;
}

void stack :: display(){
  node *p = top;
  while (p != NULL){
    cout<< p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int main(){
  stack stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);

  stk.display();

  stk.pop();

  stk.display();
}