/*Create a class Rectangle consists of width and length
Create a default constructor, constructor overloading and a destructor 
Create fuction 'set' and 'get', function calculate the area and curcumference of rectangle
*/

#include <iostream>

using namespace std;

class Rectangle{
    double width;
    double length;
    static int num;
    
    public:
    Rectangle(){
        num++;
        setLenght(0);
        setWidth(0);
    }
    Rectangle(double a,double b){
        num++;
        setLenght(a);
        setWidth(b);
    }
    Rectangle(double a){
        num++;
        setWidth(a);
        setLenght(1);
    }
    
    void setWidth(double w){
        width=w;
    }

    void setLenght(double l){
        length=l;
    }

    double findArea(){
        double a;
        a=width*length;
        return a;
    }

    double findCircumference(){
        double c;
        c=2*(width+length);
        return c;
    }
    double getWidth(){
        return width;
    }
    double getLength(){
        return length;
    }    
    void show(){
        cout<<"Width= "<<width<<endl;
        cout<<"Length= "<<length<<endl;
        cout<<"Area= "<<findArea()<<endl;
        cout<<"Circumference= "<<findCircumference()<<endl;
        cout<<endl;
    }
    static int count(){return num;}
    ~Rectangle(){
        num--;
        cout<<"Destructor: Objects= "<<num<<endl;
    }
    
};

int Rectangle::num;

int main(){
    cout<<"Object= "<<Rectangle::count()<<endl;
    Rectangle myObj1;
    cout<<"Object= "<<Rectangle::count()<<endl;
    {
    Rectangle myObj2(5.5);
    cout<<"Object= "<<Rectangle::count()<<endl;
    }
    Rectangle myObj3(2.5,0.5);
    cout<<"Object= "<<Rectangle::count()<<endl;

    myObj1.setWidth(2.5);
    myObj1.setLenght(6.0);

    double area,circum;
    area=myObj1.findArea();
    circum=myObj1.findCircumference();

    cout<<endl;
    cout<<"myObject1: "<<endl;
    cout<<"Area of ractangle= "<<area<<endl;
    cout<<"Circumference of ractangle= "<<circum<<endl;
    cout<<endl;

    cout<<"myObject1: "<<endl;
    cout<<"getWidth= "<<myObj1.getWidth()<<endl;
    cout<<"getLength= "<<myObj1.getLength()<<endl;
    cout<<"getArea= "<<myObj1.findArea()<<endl;
    cout<<"getCircumference= "<<myObj1.findCircumference()<<endl;
    cout<<endl;
    
    cout<<"myObject1: "<<endl;
    myObj1.show();

    cout<<"Object3: "<<endl;
    myObj3.show();

    return 0;
}
