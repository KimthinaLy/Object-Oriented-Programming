/* Create a Point class that consists of a coordinate point(x, y) in   decimal form and a point name(name)
Create a default constructor, constructor overloading and destructor that print the name of an object to the screen
Create function set to set values and fuction get to return the value
*/

#include <iostream>
#include<string.h>
using namespace std;

class Point{
    double x;
    double y;
    string name1;
    char name2[20];
    static int num;
    
    public:
    Point(){
        num++;setX(0);setY(0);setName1("");setName2("");
    }
    Point(string a,char* b){
        num++;setX(0);setY(0);setName1(a);setName2(b);
    }
    Point(double a,double b){
        num++;setX(a);setY(b);setName1("");setName2("");
    }
    Point(string a){
        num++;setX(0);setY(0);setName1(a);setName2("");
    }
    Point(string a,double b){
        num++;setX(b);setY(b);setName1(a);setName2("");
    }
    Point(double a,double b,string c,char* d){
        num++;setX(a);setY(b);setName1(c);setName2(d);
    }
    void setX(double a){
        x=a;
    }
    void setY(double b){
        y=b;
    }
    void setName1(string person1){
        name1=person1;
    }
    void setName2(char* person2){
        strcpy(name2,person2);
    }
    void show(){
        cout<<"x= "<<x<<endl;
        cout<<"y= "<<y<<endl;
        cout<<"name1: "<<name1<<endl;
        cout<<"name2: "<<name2<<endl;
        cout<<endl;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    string getName1(){
        return name1;
    }
    char* getName2(){
        return name2;
    }
    static int count(){return num;}
    ~Point(){
        num--;
        cout<<"object= "<<num<<endl;
    }

};
int Point::num;

int main(){
    cout<<"object= "<<Point::count()<<endl;
    Point myPoint;
    cout<<"object= "<<Point::count()<<endl;
    {
        Point itPoint("aa","aa");
        cout<<"object= "<<Point::count()<<endl;
        itPoint.show();
    }
    
    Point yourPoint(1.1,1.2);
    cout<<"object= "<<Point::count()<<endl;
    Point herPoint("a");
    cout<<"object= "<<Point::count()<<endl;
    Point hisPoint("###",0.001);
    cout<<"object= "<<Point::count()<<endl;
    Point theirPoint(1.01,2.0,"cc","dd");
    cout<<"object= "<<Point::count()<<endl;
    myPoint.setX(1.0);
    myPoint.setY(2.0);
    myPoint.setName1("Nida");
    myPoint.setName2("Nisa");
    yourPoint.setName1("Boy");

    cout<<"myPoint:"<<endl;
    myPoint.show();
    cout<<"yourPoint:"<<endl;
    yourPoint.show();
    cout<<"herPoint:"<<endl;
    herPoint.show();
    cout<<"hisPoint:"<<endl;
    hisPoint.show();
    cout<<"theirPoint:"<<endl;
    theirPoint.show();

    cout<<"Return: x= "<<myPoint.getX()<<endl;
    cout<<"Return: y= "<<myPoint.getY()<<endl;
    cout<<"Return: name1= "<<myPoint.getName1()<<endl;
    cout<<"Return: name2= "<<myPoint.getName2()<<endl;
    cout<<"Return: name3= "<<yourPoint.getName1()<<endl;
    cout<<endl;

    return 0;
}
