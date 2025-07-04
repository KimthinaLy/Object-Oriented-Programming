// From class Rectangle(exercise 2.3)
// Create an overloading operator++ to increment length by one unit(making it prefix) and increment to width by 1 unit (making it a postfix)
// Create an overloading operator-- to decrement the length by 1 unit (making it a prefix) and decrement the width by 1 unit (making it a postfix) (create the operator-- as a friend fuction)

#include <iostream>

using namespace std;

class Rectangle
{
private:
  double width;
  double length;
  static int num;

public:
  Rectangle()
  {
    num++;
    setLenght(1);
    setWidth(1);
  }
  Rectangle(double a, double b)
  {
    num++;
    setLenght(a);
    setWidth(b);
  }
  Rectangle(double a)
  {
    num++;
    setWidth(a);
    setLenght(1);
  }

  void setWidth(double w)
  {
    if (w > 0)
      width = w;
    else
      width = 1;
  }

  void setLenght(double l)
  {
    if (l > 0)
      length = l;
    else
      length = 1;
  }

  double findArea()
  {
    double a;
    a = width * length;
    return a;
  }

  double findCircumference()
  {
    double c;
    c = 2 * (width + length);
    return c;
  }
  double getWidth()
  {
    return width;
  }
  double getLength()
  {
    return length;
  }
  void show()
  {
    cout << "Width= " << width << endl;
    cout << "Length= " << length << endl;
    cout << "Area= " << findArea() << endl;
    cout << "Circumference= " << findCircumference() << endl;
    cout << endl;
  }
  static int count() { return num; }
  ~Rectangle()
  {
    num--;
    // cout << "Destructor: Objects= " << num << endl;
  }

  //---------------OperatornOverloading---------------------

  Rectangle operator++()
  { // prefix++
    ++length;
    return *this;
  }
  Rectangle operator++(int)
  { // postfix++
    return Rectangle(++width, length);
  }
  friend Rectangle operator--(Rectangle &rec)
  { // prefix--
    if (rec.length > 1)
      rec.length--;
    return rec;
  }
  friend Rectangle operator--(Rectangle &rec, int)
  { // postfix--
    if (rec.width > 1)
      rec.width--;
    return rec;
  }

  //----------perator> , < , >= , <=------------
  bool operator>(Rectangle rec)
  {
    return (findArea() > rec.findArea()) ? true : false;
  }
  friend bool operator<(Rectangle rec1, Rectangle rec2);
  bool operator>=(Rectangle);
  friend bool operator<=(Rectangle rec1, Rectangle rec2)
  {
    return (rec1.findArea() <= rec2.findArea()) ? true : false;
  }
  bool operator!=(Rectangle rec)
  {
    return (findArea() != rec.findArea()) ? true : false;
  }

  //------------FuntionCallOperator-----------------
  double operator()(double w, double l)
  {
    if (w > 0)
      width = w;
    if (l > 0)
      length = l;
    return width * length;
  }
  double operator()(double w)
  {
    if (w > 0)
      width = w;
    return findArea();
  }
  double operator()()
  {
    return findArea();
  }

  //---------------SubscriptOperator------------------
  double &operator[](int i)
  {
    if (i == 1)
      return width;
    else
      return length;
  }
};

bool operator<(Rectangle rec1, Rectangle rec2)
{
  return (rec1.findArea(), rec2.findArea()) ? true : false;
}
bool Rectangle::operator>=(Rectangle rec)
{
  return (findArea() >= rec.findArea()) ? true : false;
}

int Rectangle::num;

int main()
{
  Rectangle rect1, rect2(3, 2.5);
  cout << "rect1 before ++: " << endl;
  rect1.show();
  ++rect1;
  rect1++;
  cout << "rect1 after ++: " << endl;
  rect1.show();

  cout << "rect2:" << endl;
  rect2.show();

  rect1 = rect2--;
  cout << "rect1:" << endl;
  rect1.show();
  cout << "rect2 " << endl;
  rect2.show();
  if (rect1 != rect2)
    cout << "area of rect1 != area of rect2" << endl;
  else
    cout << "area of rect1 = area of rect2" << endl;

  Rectangle rect3;
  rect3 = rect1++;
  cout << "\nrect3:" << endl;
  rect3.show();
  cout << "rect1:" << endl;
  rect1.show();
  if (rect3 != rect1)
  {
    cout << "rect3!=rect1" << endl;
    if (rect3 > rect1)
      cout << "area of rect3 > area of rect1" << endl;
    else
      cout << "area of rect3 < area of rect1" << endl;
  }
  else
    cout << "area of rect3 = area of rect1" << endl;
  cout << "Area of rect3 = " << rect3() << endl;
  rect3[2] = rect1.getLength();
  cout << "\nAfter usingn supscript operator:" << endl;
  if (rect3 != rect1)
    cout << "area of rect3 != area of rect1" << endl;
  else
    cout << "area of rect3 = area of rect1" << endl;

  Rectangle rect4;
  cout << "\narea of rect4 = " << rect4(4, 3) << endl;
  rect4[2] = 4.5;
  rect4(2.5);
  cout << "rect4:" << endl;
  rect4.show();
  if (rect4 >= rect2)
    cout << "area of rect4 >= area of rect2" << endl;
  else
    cout << "area of rect4 < area of rect2" << endl;
  cout << "area of rect2 = " << rect2() << endl;
  rect2 = --rect4;
  rect2[1] = rect4.getWidth();
  cout << "\nrect2:" << endl;
  rect2.show();
  if (rect2 != rect4)
    cout << "area of rect2 != area of rect4" << endl;
  else
    cout << "area of rect2 = area of rect4" << endl;

  Rectangle rect5;
  rect5 = ++rect4;
  cout << "\nrect5:" << endl;
  rect5.show();
  cout << "rect4:" << endl;
  rect4.show();
  if (rect5 != rect4)
    cout << "area of rect5 != area of rect4" << endl;
  else
    cout << "area of rect5 = area of rect4" << endl;
  rect5[3] = 10;
  cout << "length of rect5 = " << rect5.getLength();
}