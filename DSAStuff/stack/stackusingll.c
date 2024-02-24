#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
  //char data;
  int data;
  struct Node *next;
}*top = NULL;

void push(int x){
  struct Node *t;
  t = (struct Node*)malloc(sizeof(struct Node));
  if(t == NULL)
    printf("Stack is full\n");
  else{
    t->data = x;
    t->next = top;
    top = t;
  }
}

int pop(){
  struct Node *t;
  int x = -1;
  if(top == NULL)
    printf("stack is empty");
  else{
    t = top;
    top = top->next;
    x = t->data;
    free(t); 
  }
  return x;
}

void display(){
  struct Node *p;
  p = top;
  while (p != NULL){
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}

int isbalanced(char *exp){
  int i;
  char x;
  for (i = 0; exp[i] != '\0'; i++)
  {
    if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
      push(exp[i]);
    else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
      if(top == NULL){
        return 0;
      }
      else{
        x = pop();
        if(exp[i] - x == 1 || exp[i] - x == 2){
          continue;
        }
        else{
          return 0;
        }
      }
    }
  }
  if(top == NULL) 
      return 1;
  else 
    return 0;
}

int pre(char x){
  if (x == '+' || x == '-')
    return 1;
  else if(x == '*' || x == '/')
    return 2;
  return 0;
}

int isoperand(char x){
  if(x == '+' || x == '-' || x == '/' || x == '*')
    return 0;
  return 1;
}

char * intopost(char * infix){
  int i = 0, j = 0;
  char *postfix;
  int len = strlen(infix);
  postfix = (char *)malloc(sizeof(char)*(len+2));

  while (infix[i] != '\0'){
    if(isoperand(infix[i]))
      postfix[j++] = infix[i++];
    else{
      if(pre(infix[i]) > pre(top->data))                   //change the push pop fxn to char before using this
        push(infix[i++]);
      else
        postfix[j++] = pop();
    }
  } 
                  
  while (top != NULL){
    postfix[j++] = pop();
  }
  postfix[j] == '\0';
  return postfix;                                     
}

int eval(char *postfix){
  int i = 0;
  int r, x1, x2;

  for (i = 0;postfix[i] != '\0'; i++){
    if(isoperand(postfix[i]))
      push(postfix[i]-'0');
    else{
      x2 = pop();
      x1 = pop();
      switch (postfix[i]){
        case '+':
          r = x1+x2;
          break;
        case '-':
          r = x1-x2;
          break;
        case '/':
          r = x1/x2;
          break;
        case '*':
          r = x1*x2;
          break;
      }
      push(r);
    }   
  }
  return top->data;
}

int main(){
  
  //char *infix = "a+b*c-d/e";
  //push('#');

  //char *postfix=intopost(infix);
  //printf("%s ",postfix);
  char *postfix = "234*+82/-";
  printf("%d ",eval(postfix));
  return 0;
}