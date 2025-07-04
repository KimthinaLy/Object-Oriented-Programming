/*From class Point(exercise 2.1) add a fuction called "dot(Point&)" that return the dot product of an object and another function called "midpoint(Point&, Point&)" that calculates the middle point between 2 points of an object
*/

#include <iostream>
#include<string.h>
using namespace std;

class Point {
    double x;
    double y;
    string name1;
    char name2[20];
    static int num; //count number of objects

public:
    Point() {
        num++; setX(0); setY(0); setName1(""); setName2((char*)"");
    }
    Point(string a, char* b) {
        num++; setX(0); setY(0); setName1(a); setName2(b);
    }
    Point(double a, double b) {
        num++; setX(a); setY(b); setName1(""); setName2((char*)"");
    }
    Point(double a) {
        num++; setX(a); setY(0); setName1(""); setName2((char*)"");
    }
    Point(string a) {
        num++; setX(0); setY(0); setName1(a); setName2((char*)"");
    }
    Point(string a, double b) {
        num++; setX(b); setY(b); setName1(a); setName2((char*)"");
    }
    Point(double a, double b, string c, char* d) {
        num++; setX(a); setY(b); setName1(c); setName2(d);
    }
    void setX(double a) {
        x = a;
    }
    void setY(double b) {
        y = b;
    }
    void setName1(string person1) {
        name1 = person1;
    }
    void setName2(char* person2) {
        strcpy(name2, person2);
    }
    void show() {
        cout << "x= " << x << endl;
        cout << "y= " << y << endl;
        cout << "name1: " << name1 << endl;
        cout << "name2: " << name2 << endl;
        cout << endl;
    }
    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    string getName1() {
        return name1;
    }
    char* getName2() {
        return name2;
    }
    static int count() { return num; }
    ~Point() {
        num--;
        //cout << "object= " << num << endl;
    }

    //Do dot product
    double dot(Point obj) {
        double scalarPro;
        scalarPro = x * obj.x + y * obj.y;
        return scalarPro;
    }

    //Find middle point between 2 points
    Point  midPoint(Point& obj1, Point& obj2) {
        x = obj1.x + obj2.x / 2;
        y = obj1.y + obj2.y / 2;
        return Point(x,y);
    }


};
int Point::num;

int main() {

    //test all functions

    cout << "object= " << Point::count() << endl;
    Point myPoint;
    cout << "object= " << Point::count() << endl;
    {
        Point itPoint("aa",(char*) "aa");
        cout << "object= " << Point::count() << endl;
        itPoint.show();
    }

    Point yourPoint(1.1, 1.2);
    cout << "object= " << Point::count() << endl;
    Point herPoint("a");
    cout << "object= " << Point::count() << endl;
    Point hisPoint("###", 0.001);
    cout << "object= " << Point::count() << endl;
    Point theirPoint(1.01, 2.0, "cc", (char*)"dd");
    cout << "object= " << Point::count() << endl;
    myPoint.setX(1.0);
    myPoint.setY(2.0);
    myPoint.setName1("Nida");
    myPoint.setName2((char*)"Nisa");
    yourPoint.setName1("Boy");

    cout << "myPoint:" << endl;
    myPoint.show();
    cout << "yourPoint:" << endl;
    yourPoint.show();
    cout << "herPoint:" << endl;
    herPoint.show();
    cout << "hisPoint:" << endl;
    hisPoint.show();
    cout << "theirPoint:" << endl;
    theirPoint.show();

    cout << "Return: x= " << myPoint.getX() << endl;
    cout << "Return: y= " << myPoint.getY() << endl;
    cout << "Return: name1= " << myPoint.getName1() << endl;
    cout << "Return: name2= " << myPoint.getName2() << endl;
    cout << "Return: name3= " << yourPoint.getName1() << endl;
    cout << endl;

    cout << "------------ HW4.1 -----------" << endl;

    Point obj1(1.0);
    Point obj2(1.1, 1.2);
    Point obj3;
    Point obj4;
    double scalarProduct = obj2.dot(obj1) ;
    cout << "Scalar product between obj1 and obj2 = " << scalarProduct << endl;
    ;
    obj4=obj3.midPoint(obj1, obj2);
    cout <<endl<< "Midpoint value between two points: " << endl;
    cout << "x = " << obj3.getX()<< endl;
    cout << "y = " << obj3.getY() << endl;
    cout <<endl<< "Object1: " << endl;
    obj1.show();
    cout << endl << "Object2: " << endl;
    obj2.show();
    cout << endl << "Object3: " << endl;
    obj3.show();
    cout << endl << "Object4: " << endl;
    obj3.show();
    return 0;
}