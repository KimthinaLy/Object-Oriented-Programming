//This program can catch various types of exception such as int, double, char, char* and others(...)
//It also shows the importance of the order of exception handling, such that changing the order will show different results
//There is a chain of nested functions, where exceptions can be thrown and caught at each level
//Class D and E inherit the properties of the Exception class and handle their own exceptions

#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

template <class T>
void checkPositive(T x)
{
    if (x < 0)
    {
        throw x;
    }
    cout << "Number " << x << " is positive" << endl;
}

void checkAlpha(char x)
{
    if (x >= 'a' && x <= 'z')
    {
        cout << "Character '" << x << "' is a lower case alphabet" << endl;
    }
    else if (x >= 'A' && x <= 'Z')
    {
        cout << "Character '" << x << "' is an upper case alphabet" << endl;
    }
    else
    {
        throw x;
    }
}

void checkNull(char *c)
{
    if (c == nullptr)
    {
        throw c;
    }
    cout << "String \" " << c << " \" is not null" << endl;
}

class A
{
public:
    A()
    {
        cout << "Constructor A called" << endl;
    }
    ~A()
    {
        cout << "Destructor A called" << endl;
    }
};
class B : public A
{
public:
    B()
    {
        cout << "Constructor B called" << endl;
    }
    ~B()
    {
        cout << "Destructor B called" << endl;
    }
};
class C : public B
{
public:
    C()
    {
        cout << "Constructor C called" << endl;
    }
    ~C()
    {
        cout << "Destructor C called" << endl;
    }
};

class D : public exception
{
public:
    virtual const char *what() const throw()
    {
        return "Exception: D is thrown";
    }
    virtual void test(){
        cout<<"Hello D"<<endl;
    }
};

class E : public D
{
public:
     const char *what() const throw()
    {
        return "Exception: E is thrown";
    }
    virtual void test(){
        cout<<"Hello E"<<endl;
    }
};

int main()
{
    try
    {
        checkPositive(5);
        checkPositive(-5);
    }
    catch (int i)
    {
        cout << "Exception: number " << i << " is negative" << endl;
    }
    try
    {
        checkPositive(3.333333333333);
        checkPositive(-8.8888888888888);
    }
    catch (double d)
    {
        cout << "Exception: number " << d << " is negative" << endl;
    }
    try
    {
        checkPositive(7.01f);
        checkPositive(-7.01f);
    }
    catch (float f)
    {
        cout << "Exception: number " << f << " is negative" << endl;
    }
    try
    {
        checkAlpha('a');
        checkAlpha('7');
        // not execute after throw
        checkAlpha('-');
    }
    catch (char c)
    {
        cout << "Exception: character '" << c << "' is not an alphabet" << endl;
    }
    try
    {

        char *z = new char[strlen("test") + 1];
        strcpy(z, "test");
        checkNull(z);
        char *y = nullptr;
        checkNull(y);

        delete[] z;
    }

    catch (char *p)
    {
        cout << "Exception: string is null" << endl;
    }

    try
    {
        try
        {
            try
            {
                B b;
                throw b;
            }
            //
            catch (A a)
            {
                cout << "Caught object of class A" << endl;
            }
            catch (B b)
            {
                cout << "Caught object of class B" << endl;
            }
            catch (C c)
            {
                cout << "Caught object of class C" << endl;
            }

            B b2;
            throw b2;
        }
        //
        catch (C c)
        {
            cout << "Caught object of class C" << endl;
        }
        catch (B b)
        {
            cout << "Caught object of class B" << endl;
        }
        catch (A a)
        {
            cout << "Caught object of class A" << endl;
        }

        C c1;
        throw c1;
    }
    //
    catch (...)
    {
        cout << "Other exception" << endl;
    }
    /* -------error , cannot write any catch block after catch(...) block
        catch (C c)
        {
            cout << "Caught object of class C" << endl;
        }
    */
    try
    {
        cout<<"Throwing exception D"<<endl;
        throw D();
    }
    catch (D d)
    {
        cout << d.what() << endl;
    }

    try
    {
        cout<<"Throwing exception E"<<endl;
        E e;
        D *d2;
        d2=&e;
        cout<<"Test d2"<<endl;
        d2->test();
        cout<<endl;
        throw d2;
    }
    //-----------------
    catch (exception &e){
        cout<<"Exception? "<<e.what()<<endl;
    }
    catch (D& d)
    {
        cout << " &d "<<d.what() << endl;
    }
    
    catch (D* d)
    {
        cout <<" *d "<< d->what() << endl;
    }

    try
    {
        cout<<"Throwing exception E2"<<endl;
        E e2;
        throw e2;
    }
    catch (D& d)
    {
        cout << d.what() << endl;
    }

    cout<<"Code after throwing works normally. "<<endl;
    return 0;
}
