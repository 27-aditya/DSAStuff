#include <iostream>

class rectangle
{
private:
  int length;
  int breadth;
public:
  rectangle()
  {
    length = 0;
    breadth = 0;
  }
  rectangle(int l, int b)
  {
    length = l;
    breadth = b;
  }

  int area()
  {
    return length*breadth;
  }
  int perimeter()
  {
    return 2*(length+breadth);
  }

  int getlength()
  {
    return length;
  }
  int getreadth()
  {
    return breadth;
  }

  void setlength(int l)
  {
    length = l;
  }
  void setbreadth(int b)
  {
    breadth = b;
  }
  ~rectangle()
  {
    printf("Destroy0");
  }
};

int main()
{
  rectangle r(10, 5);
  //cout<<"Area"<<r.area()<<endl;
  //cout<<"Perimeter"<<r.perimeter()<<endl;
  printf("%d",r.area());
  printf("%d",r.perimeter());
}