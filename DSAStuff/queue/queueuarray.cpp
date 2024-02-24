#include<iostream>
using namespace std;

class queue{
  private:
    int front;
    int rear;
    int size;
    int *Q;

  public:
    queue(){front = rear = -1; size = 10; Q = new int[size];}
    queue(int size){front = rear = -1; this->size = size; Q = new int[this->size];}
    void enqueue(int x);
    int dequeue();
    void display();
};

void queue :: enqueue(int x){
  if(rear == size-1)
    cout << "Queue is full" << endl;
  else{
    rear++;
    Q[rear] = x;
  }
}

int queue :: dequeue(){
  int x;
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

int main(){
  queue q(5);

  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);

  q.display();
}