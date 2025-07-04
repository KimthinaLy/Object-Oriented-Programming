#include <iostream>
using namespace std;
class Date
{
    int day;
    int month;
    int *year;

public:
    Date()
    {
        year = new int;
        setDay(0);
        setMonth(0);
        setYear(0);
    }
    Date(int m)
    {
        year = new int;
        setDay(0);
        setMonth(m);
        setYear(0);
    }
    Date(int m, int y)
    {
        year = new int;
        setDay(0);
        setMonth(m);
        setYear(y);
    }
    Date(int d, int m, int y)
    {
        year = new int;
        setDay(d);
        setMonth(m);
        setYear(y);
    }
    void setDay(int d)
    {
        day = d;
    }
    void setMonth(int m)
    {
        month = m;
    }
    void setYear(int y)
    {
        *year = y;
    }
    void setDateOfBirth(int d, int m, int y)
    {
        day = d;
        month = m;
        *year = y;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return *year;
    }
    int getDayofMonth()
    {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
            return 31;
        else if (month == 2)
            if (*year % 4 == 0 && *year % 100 != 0)
                return 29;
            else
                return 28;
        else if (month == 0)
            return 0;
        else
            return 30;
    }
    void showDateOfBirth()
    {
        cout << "---Date of birth--- : " << endl;
        cout << day << " / " << month << " / " << *year << endl;
    }
    ~Date()
    {
        delete year;
        cout << "Destructor: Date " << endl;
    }

    //--------------------assignment operator, copy con, iostream-------------------
    Date &operator=(const Date &d)
    {
        if (this == &d)
            return *this;
        this->day = d.day;
        this->month = d.month;

        delete year;
        year = new int;
        *this->year = *d.year;
        return *this;
    }
    Date &operator+=(const Date &d)
    {
        this->day += d.day;
        this->month += d.month;
        if (this->year == nullptr)
        {
            this->year = new int;
            *this->year = 0;
        }
        if (d.year != nullptr)
        {
            *this->year += *d.year;
        }

        if (this->month > 12)
            this->month = 12;

        if (this->month == 2)
        {
            if (this->day > 28)
                this->day = 28;
        }
        else if (this->month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if (day > 31)
                day = 31;
        }
        else
        {
            if (day > 30)
                day = 30;
        }

        if(*this->year>2025)
            *this->year=2025;

        return *this;
    }

    Date(const Date& d){
        cout<<"copy constructor of class Date is called"<<endl;
        this->day=d.day;
        this->month=d.month;
        if(d.year!=nullptr){
            this->year=new int(*d.year);
        }else{
            this->year=new int(0);
        }
    }
    void Input(istream &is){
        cout<<"Input day of birth: "; is>>day;
        cout<<"Input month of birth: "; is>>month;
        int tempInt;
        cout<<"Input year of birth: "; is>>tempInt;
        setYear(tempInt);
    }
};

istream &operator>>(istream& is, Date &d){
    d.Input(is);
    return is;
}
ostream &operator<<(ostream& os, Date &d){
    d.showDateOfBirth();
    return os;
}

/*
int main()
{
    Date d;
    Date d2(1, 8, 2001);
    cout << "d: " << endl;
    d.showDateOfBirth();
    cout << "---------d2--------" << endl;
    d2.showDateOfBirth();
    // cout<<d2.getYear();

    cout << "operator +=" << endl;
    d2 += d;
    d2 += d;
    d2.showDateOfBirth();
    cout << "operator =" << endl;
    d = d2;
    d.showDateOfBirth();

    d2 += d;
    d2.showDateOfBirth();
    cin>>d;
    cout<<d;
    cout<<"--------d3-------"<<endl;
    Date d3(d);
    cout<<d3;
    d3.setYear(8888);
    cout<<d3.getYear()<<endl;
}*/
    