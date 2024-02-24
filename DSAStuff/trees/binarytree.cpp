#include<iostream>
using namespace std;

class node{
  public:
    int data;
    node *lchild;
    node *rchild;
};

class queue{
  private:
    int front;
    int rear;
    int size;
    node **Q;

  public:
    queue(){front = rear = -1; size = 10; Q = new node*[size];}
    queue(int size){front = rear = -1; this->size = size; Q = new node*[this->size];}
    void enqueue(node *x);
    node* dequeue();
    void display();
    int isempty(){return front == rear;}
};

void queue :: enqueue(node *x){
  if(rear == size-1)
    cout << "Queue is full" << endl;
  else{
    rear++;
    Q[rear] = x;
  }
}

node* queue :: dequeue(){
  node *x = NULL;
  if(front == rear)
    cout << "Queue is empty" << endl;
  else{
    x = Q[front+1];
    front++;
  }
  return x;
}

void queue :: display(){
  for (int i = front+1; i < size; i++)
  {
    printf("%d ",Q[i]);
  }
  cout << endl;
}

class tree{
public:
  node *root;
  tree(){root = NULL;}
  void createtree();
  void preorder(node *p);
  void inorder(node *p);
  void postorder(node *p);
  void levelorder(node *p);
  void height(node *root);
};

void tree :: createtree(){
  node *p,*t;
  int x;
  queue q(100);

  printf("Enter the root value");
  scanf("%d",&x);
  root = new node;
  root->data = x;
  root->lchild = root->rchild = NULL;

  q.enqueue(root);
  while(!q.isempty()){
    p = q.dequeue();
    printf("Enter the left child value of %d",p->data);
    scanf("%d",&x);
    if (x != -1){
      t = new node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->lchild = t;
      q.enqueue(t);
    }
    printf("Enter the right child value of %d",p->data);
    scanf("%d",&x);
    if (x != -1){
      t = new node;
      t->data = x;
      t->lchild = t->rchild = NULL;
      p->rchild = t;
      q.enqueue(t);
    }
  }
}

void tree :: preorder(node* root){
  if(root){
    printf("%d ",root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void tree :: inorder(node* root){
  if(root){
    inorder(root->lchild);
    printf("%d ",root->data);
    inorder(root->rchild);
  }
}

void tree :: postorder(node* root){
  if(root){
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ",root->data);
  }
}

int main(){
  tree t;
  t.createtree();
  t.preorder(t.root);
  t.inorder(t.root);
  t.postorder(t.root);

  return 0;
}