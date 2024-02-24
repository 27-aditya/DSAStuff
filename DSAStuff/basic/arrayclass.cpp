#include<iostream>
using namespace std;
class array
{
private:
  int *a;
  int size;
  int length;
public:
  array()
  {
    size = 10;
    a = new int [10];
    length = 0;
  }

  array(int sz)
  {
    size = sz;
    length = 0;
    a = new int[size];
  }

  ~array()
  {
    delete []a;
  }

  void display();
  void insert(int index, int x);
  int Delete(int index);
};

void array :: display()
{
   for (int i = 0; i < length; i++)
   {
    cout << a[i] << " ";
   }
   cout << endl;
}
