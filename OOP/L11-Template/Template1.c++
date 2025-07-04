//Create a template function to find the minimun and miximun of three data sets

#include <iostream>
using namespace std;

class A
{
    int x, y;

public:
    A()
    {
        x = 0;
        y = 0;
    }
    A(int a, int b)
    {
        x = a;
        y = b;
    }
    void print(ostream &os) const
    {
        os << "A(" << x << "," << y << ")";
    }
    bool operator>(A a)
    {
        return ((x > a.x) && (y > a.y) ? true : false);
    }
    bool operator==(A a)
    {
        return ((x == a.x) && (y == a.y) ? true : false);
    }
    A(const A &a)
    {
        cout << "Copy constructor called" << endl;
        x = a.x;
        y = a.y;
    }
};

template <class T>
T findMax(T a, T b, T c)
{
    if ((a > b && a > c) || (a == b && a > c) || (a == c && a > b))
    {
        return a;
    }
    else if ((b > a && b > c) || (b == a && b > c) || (b == c && b > a))
    {
        return b;
    }
    else
    {
        return c;
    }
}

ostream &operator<<(ostream &os, const A &a)
{
    a.print(os);
    return os;
}

int main()
{
    A a(1, 2), b(3, 4), c(5, 6);

    cout << "--------- A a(1, 2), b(3, 4), c(5, 6)---------" << endl;
    cout << findMax(a, b, c);
    cout << " is the biggest" << endl;

    A d(5, 6), e(3, 4), f(5, 6);

    cout << "--------- A d(5, 6), e(3, 4), f(5, 6)---------" << endl;
    cout << findMax(d, e, f);
    cout << " is the biggest" << endl;

    cout << "--------- 6, 4, 3---------" << endl;
    cout << findMax(6, 4, 3) << " is the biggest" << endl;

    cout << "--------- 6.5, 4.5, 3.5---------" << endl;
    cout << findMax(6.5, 4.5, 3.5) << " is the biggest" << endl;

    cout << "--------- 'a', 'b', 'c'---------" << endl;
    cout << findMax('a', 'b', 'c') << " is the biggest" << endl;

    return 0;
}