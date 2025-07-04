//Createa template class to find the minimun and maximun value from the data stored in array

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
    bool operator<(A a)
    {
        return ((x < a.x) && (y < a.y) ? true : false);
    }
};

template <class T>
class Arr
{
    T *arr;
    int size;

public:
    Arr(int size)
    {
        this->size = size;
        arr = new T[size];
    }
    Arr(int size, T *a)
    {
        this->size = size;
        arr = new T[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = a[i];
        }
    }
    void setArr(int i, T a)
    {
        arr[i] = a;
    }
    T getArr(int i)
    {
        return arr[i];
    }
    T findMax()
    {
        T max = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
    T findMin()
    {
        T min = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }
    ~Arr()
    {
        delete[] arr;
    }
};
ostream &operator<<(ostream &os, const A &a)
{
    a.print(os);
    return os;
}
int main()
{
    A data[] = {A(1, 2), A(3, 4), A(5, 6)};
    Arr<A> arr1(3, data);
    cout << arr1.findMax() << " is the maximun of arr1" << endl;
    cout << arr1.findMin() << " is the minimun of arr1" << endl;

    int intData[] = {1, 2, 3,4};
    Arr<int> arr2(4,intData);
    cout << arr2.findMax() << " is the maximun of arr2" << endl;
    cout << arr2.findMin() << " is the minimun of arr2" << endl;

    float floatData[] = {1.1, 2.2, 3.3,4.4,5.6};
    Arr<float> arr3(5,floatData);
    cout << arr3.findMax() << " is the maximun of arr3" << endl;
    cout << arr3.findMin() << " is the minimun of arr3" << endl;

    char charData[] = {'a', 'b', 'c','d','e','f'};
    Arr<char> arr4(6,charData);
    cout << arr4.findMax() << " is the maximun of arr4" << endl;
    cout << arr4.findMin() << " is the minimun of arr4" << endl;

    Arr<int> arr5(3);
    arr5.setArr(0, 10);
    arr5.setArr(1, 20);
    cout << arr5.findMax() << " is the maximun of arr5" << endl;
    cout << arr5.findMin() << " is the minimun of arr5" << endl;

    return 0;

}