#include <iostream>

using namespace std;

class Shape
{
public:
    virtual float area() = 0;
    virtual void print(ostream &os) = 0;
    virtual void input(istream &is) = 0;
    virtual ~Shape() { cout << "Shape destructor" << endl; }
};

class TwoDimensional : public Shape
{
public:
    float area() = 0;
    void print(ostream &os) = 0;
    void input(istream &is) = 0;
    ~TwoDimensional() { cout << "TwoDimensional destructor" << endl; }
};

class ThreeDimensional : public Shape
{
public:
    float area() = 0;
    virtual float volume() = 0;
    void print(ostream &os) = 0;
    void input(istream &is) = 0;
    ~ThreeDimensional() { cout << "ThreeDimensional destructor" << endl; }
};

class Rectangle : public TwoDimensional
{
private:
    float length;
    float width;

public:
    Rectangle()
    {
        length = 1;
        width = 1;
    }
    Rectangle(float l, float w)
    {
        length = l;
        width = w;
    }
    Rectangle(float l)
    {
        length = l;
        width = 1;
    }
    void setLength(float l)
    {
        length = l;
    }
    void setWidth(float w)
    {
        width = w;
    }
    float getLength()
    {
        return length;
    }
    float getWidth()
    {
        return width;
    }
    float area()
    {
        return length * width;
    }
    void print(ostream &os)
    {
        os << "Rectangle: length = " << length << ", width = " << width << ", area = " << area() << endl;
    }
    void input(istream &is)
    {
        cout << "Input length of rectangle: ";
        is >> length;
        cout << "Input width of rectangle: ";
        is >> width;
    }
    ~Rectangle() { cout << "Rectangle destructor" << endl; }
};

class Triangle : public TwoDimensional
{
private:
    float base;
    float height;

public:
    Triangle()
    {
        base = 1;
        height = 1;
    }
    Triangle(float b, float h)
    {
        base = b;
        height = h;
    }
    Triangle(float b)
    {
        base = b;
        height = 1;
    }
    void setBase(float b)
    {
        base = b;
    }
    void setHeight(float h)
    {
        height = h;
    }
    float getBase()
    {
        return base;
    }
    float getHeight()
    {
        return height;
    }
    float area()
    {
        return 0.5 * base * height;
    }
    void print(ostream &os)
    {
        os << "Triangle: base = " << base << ", height = " << height << ", area = " << area() << endl;
    }
    void input(istream &is)
    {
        cout << "Input base of triangle: ";
        is >> base;
        cout << "Input height of triangle: ";
        is >> height;
    }
    ~Triangle() { cout << "Triangle destructor" << endl; }
};

class Circle : public TwoDimensional
{
private:
    float radius;

public:
    Circle()
    {
        radius = 1;
    }
    Circle(float r)
    {
        radius = r;
    }
    void setRadius(float r)
    {
        radius = r;
    }
    float getRadius()
    {
        return radius;
    }
    float area()
    {
        return 3.14 * radius * radius;
    }
    void print(ostream &os)
    {
        os << "Circle: radius = " << radius << ", area = " << area() << endl;
    }
    void input(istream &is)
    {
        cout << "Input radius of circle: ";
        is >> radius;
    }
    ~Circle() { cout << "Circle destructor" << endl; }
};

class Cylinder : public ThreeDimensional
{
private:
    float radius;
    float height;

public:
    Cylinder()
    {
        radius = 1;
        height = 1;
    }
    Cylinder(float r, float h)
    {
        radius = r;
        height = h;
    }
    Cylinder(float r)
    {
        radius = r;
        height = 1;
    }
    void setRadius(float r)
    {
        radius = r;
    }
    void setHeight(float h)
    {
        height = h;
    }
    float getRadius()
    {
        return radius;
    }
    float getHeight()
    {
        return height;
    }
    float area()
    {
        return 2 * 3.14 * radius * height + 2 * 3.14 * radius * radius;
    }
    float volume()
    {
        return 3.14 * radius * radius * height;
    }
    void print(ostream &os)
    {
        os << "Cylinder: radius = " << radius << ", height = " << height << ", area = " << area() << ", volume = " << volume() << endl;
    }
    void input(istream &is)
    {
        cout << "Input radius of cylinder: ";
        is >> radius;
        cout << "Input height of cylinder: ";
        is >> height;
    }
    ~Cylinder() { cout << "Cylinder destructor" << endl; }
};

class Sphere : public ThreeDimensional
{
private:
    float radius;

public:
    Sphere()
    {
        radius = 1;
    }
    Sphere(float r)
    {
        radius = r;
    }
    void setRadius(float r)
    {
        radius = r;
    }
    float getRadius()
    {
        return radius;
    }
    float area()
    {
        return 4 * 3.14 * radius * radius;
    }
    float volume()
    {
        return 4 / 3 * 3.14 * radius * radius * radius;
    }
    void print(ostream &os)
    {
        os << "Sphere: radius = " << radius << ", area = " << area() << ", volume = " << volume() << endl;
    }
    void input(istream &is)
    {
        cout << "Input radius of sphere: ";
        is >> radius;
    }
    ~Sphere() { cout << "Sphere destructor" << endl; }
};
float findArea(Shape *s)
{
    return s->area();
}
float findVolume(ThreeDimensional &s)
{
    return s.volume();
}
ostream &operator<<(ostream &os, Shape &s)
{
    s.print(os);
    return os;
}
istream &operator>>(istream &is, Shape &s)
{
    s.input(is);
    return is;
}

int main()
{
    Shape *s[5];
    s[0] = new Rectangle(3, 4);
    s[1] = new Triangle(2, 5);
    s[2] = new Circle(3.4);
    s[3] = new Cylinder(4, 6);
    s[4] = new Sphere(3.5);

    for (int i = 0; i < 5; i++)
    {
        cout << "area= " << s[i]->area() << endl;
        cout << *s[i] << endl;
    }

    Rectangle rec1;
    cin >> rec1;
    cout << "Area of rectangle: " << findArea(&rec1) << endl;
    cout << rec1;

    Triangle tri1;
    cin >> tri1;
    cout << "Area of triangle: " << findArea(&tri1) << endl;
    cout << tri1;

    Circle cir1;
    cin >> cir1;
    cout << "Area of circle: " << findArea(&cir1) << endl;
    cout << cir1;

    Cylinder cyl1;
    cin >> cyl1;
    cout << "Area of cylinder: " << findArea(&cyl1) << endl;
    cout << "Volume of cylinder: " << findVolume(cyl1) << endl;
    cout << cyl1;

    Sphere sph1;
    cout << "Area of sphere: " << findArea(&sph1) << endl;
    cout << "Volume of sphere: " << findVolume(sph1) << endl;
    cout << sph1;

    cout << "--------tri2---------" << endl;
    Triangle tri2(3);
    tri2.setHeight(2);
    cout << tri2;

    cout << "--------rec2---------" << endl;
    Rectangle rec2(3);
    rec2.setWidth(2);
    cout << rec2;

    cout << "--------cir2---------" << endl;
    Circle cir2;
    cir2.setRadius(3);
    cout << cir2;

    cout << "--------cyl2---------" << endl;
    Cylinder cyl2(3);
    cyl2.setHeight(6);
    cout << cyl2;

    cout << "--------sph2---------" << endl;
    Sphere sph2;
    sph2.setRadius(4.33);
    cout << sph2;

    ThreeDimensional *t[2];
    t[0] = &cyl2;
    t[1] = &sph2;
    for (int i = 0; i < 2; i++)
    {
        cout << "volume= " << t[i]->volume() << endl;
    }
    delete[] s;
    return 0;
}