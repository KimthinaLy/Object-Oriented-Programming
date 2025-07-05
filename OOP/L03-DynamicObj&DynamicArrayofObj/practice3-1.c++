/*Create a class called MyRect that stores objects of class Rectangle(from exercise 2.2) in the form of a 2-demensional dynamic array which rows and columns of the array are resizable
Create a default constructor, a constructor to set the size and allocate memory for array and a destructor to deallocate the reserved memory
*/

#include <iostream>

using namespace std;

class Rectangle
{
public:
    double width;
    double length;
    static int num;

public:
    Rectangle()
    {
        num++;
        setLenght(0);
        setWidth(0);
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
        width = w;
    }

    void setLenght(double l)
    {
        length = l;
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
        cout << "Destructor: Objects= " << num << endl;
    }
};

int Rectangle::num;

class MyRect
{
public:
    int row, col;
    Rectangle **a;

private:
    void deleteArr()
    {
        if (a != 0)
        {
            for (int i = 0; i < row; i++)
                delete[] a[i];
            delete[] a;
        }
    }
    void getDyArr(int r, int c)
    {
        row = r;
        col = c;
        a = new Rectangle *[row];
        for (int i = 0; i < row; i++)
        {
            a[i] = new Rectangle[col];
        }
    }

public:
    MyRect()
    {
        a = 0;
        row = col = 0;
    }
    MyRect(int i, int j);
    ~MyRect();
    void setRect();
    Rectangle getRect(int, int);
    void reSet(int, int);
    void show();
};

MyRect::MyRect(int r, int c)
{
    getDyArr(r, c);
}
MyRect::~MyRect()
{
    deleteArr();
}
void MyRect::setRect()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Input width of a[" << i << "][" << j << "]= ";
            cin >> a[i][j].length;
            cout << "Input length of a[" << i << "][" << j << "]= ";
            cin >> a[i][j].width;
        }
    }
}

void MyRect::reSet(int r, int c)
{
    if (a != 0)
    {
        deleteArr();
    }
    getDyArr(r, c);
    setRect();
}

Rectangle MyRect::getRect(int i, int j)
{
    return a[i][j];
}

void MyRect::show()
{
    cout << "show: " << endl;
    cout << "Number of row= " << row << endl;
    cout << "Number of column= " << col << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << " rectangle[" << i << "][" << j << "]: " << endl;
            a[i][j].show();
        }
    }
}
int main()
{
    cout << "Object= " << Rectangle::count() << endl;
    Rectangle myObj1;
    cout << "Object= " << Rectangle::count() << endl;
    {
        Rectangle myObj2(5.5);
        cout << "Object= " << Rectangle::count() << endl;
    }
    Rectangle myObj3(2.5, 0.5);
    cout << "Object= " << Rectangle::count() << endl;

    myObj1.setWidth(2.5);
    myObj1.setLenght(6.0);

    double area, circum;
    area = myObj1.findArea();
    circum = myObj1.findCircumference();

    cout << endl;
    cout << "myObject1: " << endl;
    cout << "Area of ractangle= " << area << endl;
    cout << "Circumference of ractangle= " << circum << endl;
    cout << endl;

    cout << "myObject1: " << endl;
    cout << "getWidth= " << myObj1.getWidth() << endl;
    cout << "getLength= " << myObj1.getLength() << endl;
    cout << "getArea= " << myObj1.findArea() << endl;
    cout << "getCircumference= " << myObj1.findCircumference() << endl;
    cout << endl;

    cout << "myObject1: " << endl;
    myObj1.show();

    cout << "Object3: " << endl;
    myObj3.show();
    cout << "------------------class MyRect--------------------" << endl;
    MyRect x(2, 3);
    x.setRect();
    x.getRect(1, 1).show();
    x.reSet(2, 5);
    x.show();

    return 0;
}
