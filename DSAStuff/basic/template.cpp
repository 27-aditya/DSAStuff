#include<iostream>
using namespace std;

template<class T>
class arithmetic
{
private:
  T a;
  T b;
public:
  arithmetic(T a, T b);
  T add();
  T sub();
};

template<class T>
arithmetic<T>::arithmetic(T a, T b)
{
  this->a = a;
  this->b = b;
}
template<class T>
T arithmetic<T>::add()
{
  return a+b;
}
template<class T>
T arithmetic<T> :: sub()
{
  return a-b;
}

int main()
{
  arithmetic<int> a{10,5};
  cout<<"add"<<a.add()<<endl;
  cout<<"sub"<<a.sub()<<endl;
}


