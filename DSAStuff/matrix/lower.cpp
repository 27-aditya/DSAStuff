#include <iostream>

// this implementation is for row major 
// as for column major put index as n*(j-1)+(j-2)(j-1)/2 + (i-j)
using namespace std;

class lowertriangular{
  private:
    int n;
    int *a;
  public:
    lowertriangular(){
      n = 2;
      a = new int[2*(2+1)/2];
    }
    lowertriangular(int n){
      this->n = n;
      a = new int[n*(n+1)/2];
    }
    ~lowertriangular(){
      delete []a;
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int getdimension(){return n;};
};

void lowertriangular :: set(int i, int j, int x){
  if(i >= j)
    a[i*(i-1)/2+j-1] = x;
}

int lowertriangular :: get(int i, int j){
  if(i >= j)
    return a[i*(i-1)/2+j-1];
  else  
    return 0;
} 

void lowertriangular :: display(){
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if(i >= j) 
        cout << a[i*(i-1)/2+j-1] << " ";
      else
        cout << 0 << " ";
    }
    cout << endl;
  }
}

int main(){
  int d;
  cout << "enter the dimension" << endl;
  cin >> d;
  lowertriangular lm(d);
  int x;
  cout << "enter the element" << endl;
  for (int i = 1; i <= d; i++){
    for (int j = 1; j <= d; j++){
      cin >> x;
      lm.set(i,j,x);
    }
  }

  lm.display();
  
  
}