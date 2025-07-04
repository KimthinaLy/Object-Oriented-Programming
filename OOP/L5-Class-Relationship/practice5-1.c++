// Create a called "Circle" consisting of a radius and a central point when the central point is an object of the class Point
// Create a freind fuction to check whether any point, which is an object of the class Point, is inside a circle, which is an object of the class Circle.
// Create function set, get and show.

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Circle;
class Point
{
  double x;
  double y;
  string name1;
  char name2[20];
  static int num;

public:
  Point()
  {
    num++;
    setX(0);
    setY(0);
    setName1("");
    setName2((char *)"");
  }
  Point(string a, char *b)
  {
    num++;
    setX(0);
    setY(0);
    setName1(a);
    setName2(b);
  }
  Point(double a, double b)
  {
    num++;
    setX(a);
    setY(b);
    setName1("");
    setName2((char *)"");
  }
  Point(double a)
  {
    num++;
    setX(a);
    setY(0);
    setName1("");
    setName2((char *)"");
  }
  Point(string a)
  {
    num++;
    setX(0);
    setY(0);
    setName1(a);
    setName2((char *)"");
  }
  Point(string a, double b)
  {
    num++;
    setX(b);
    setY(b);
    setName1(a);
    setName2((char *)"");
  }
  Point(double a, double b, string c, char *d)
  {
    num++;
    setX(a);
    setY(b);
    setName1(c);
    setName2(d);
  }
  void setX(double a)
  {
    x = a;
  }
  void setY(double b)
  {
    y = b;
  }
  void setName1(string person1)
  {
    name1 = person1;
  }
  void setName2(char *person2)
  {
    strcpy(name2, person2);
  }
  void show()
  {
    cout << "x= " << x << endl;
    cout << "y= " << y << endl;
    cout << "name1: " << name1 << endl;
    cout << "name2: " << name2 << endl;
    cout << endl;
  }
  double getX()
  {
    return x;
  }
  double getY()
  {
    return y;
  }
  string getName1()
  {
    return name1;
  }
  char *getName2()
  {
    return name2;
  }
  static int count() { return num; }
  ~Point()
  {
    num--;
    // cout << "object= " << num << endl;
  }
  friend bool cmplength(Circle, Point);
};

class Circle
{
  double radius;
  Point midPoint;

public:
  Circle()
  {
    setR(1.0);
    setP(0);
  }
  Circle(double R, Point obj)
  {
    setR(R);
    setP(obj);
  }
  Circle(Point obj)
  {
    setP(obj);
    setR(1);
  }
  Circle(double R)
  {
    setR(R);
    setP(0);
  }

  void setR(int R)
  {
    radius = R;
  }
  void setP(Point obj)
  {
    midPoint = obj;
  }
  Point getP()
  {
    return midPoint;
  }
  double getR()
  {
    return radius;
  }
  void showCircle()
  {
    cout << "Radian = " << radius << endl;
    cout << "Middle point of the circle: " << endl;
    midPoint.show();
  }
  ~Circle()
  {
    cout << "delete object" << endl;
  }
  // friend bool cmplength(Circle, Point);
};
bool cmplength(Circle myCir, Point pointA)
{
  double length;
  length = sqrt((pointA.x - myCir.getP().x) * (pointA.x - myCir.getP().x) + (pointA.y - myCir.getP().y) * (pointA.y - myCir.getP().y));
  if (length <= myCir.getR())
    return true;
  else
    return false;
}
void result(bool cmp, char *pointName)
{
  if (!cmp)
  {
    cout << pointName << " is not in the circle" << endl;
  }
  else
  {
    cout << pointName << " is in the circle" << endl;
  }
}

int Point::num;

int main()
{
  bool cmp;

  Point pointA(3, 5);
  Circle myCir1;
  cout << endl;
  cout << "Point A: " << endl;
  pointA.show();
  myCir1.showCircle();
  cmp = cmplength(myCir1, pointA);
  result(cmp, (char *)"Point A");

  Point pointB(3.0, 5.0);
  Point midPoint1(2.0, 4.0);
  Circle myCir2(5.5, midPoint1);
  cout << endl;
  cout << "Point B: " << endl;
  pointB.show();
  myCir2.showCircle();
  cmp = cmplength(myCir2, pointB);
  result(cmp, (char *)"Point B");

  Point pointC(4.0);
  Point midPoint2(3.0);
  Circle myCir3(midPoint2);
  cout << endl;
  cout << "Point C: " << endl;
  pointC.show();
  myCir3.showCircle();
  cmp = cmplength(myCir3, pointC);
  result(cmp, (char *)"Point C");

  Circle myCir4(5);
  Point pointD(2, 3);
  cout << endl;
  cout << "Point D: " << endl;
  pointD.show();
  myCir4.showCircle();
  cmp = cmplength(myCir4, pointD);
  result(cmp, (char *)"Point D");

  return 0;
}