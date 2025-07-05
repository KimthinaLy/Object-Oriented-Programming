#include <iostream>
using namespace std;
class Date  {
    int day, month, year;
public:
    Date() {
        setDay(0); setMonth(0); setYear(0);
    }
    Date(int m)  {
        setDay(0); setMonth(m); setYear(0);
    }
    Date(int m, int y) {
        setDay(0); setMonth(m); setYear(y);
    }
    Date(int d, int m, int y)  {
        setDay(d); setMonth(m); setYear(y);
    }
    void setDay(int d) {
        day = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setYear(int y) {
        year = y;
    }
    void setDateOfBirth(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    int getDayofMonth() {
        if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
            return 31;
        else if (month == 2)
            if (year % 4 == 0 && year % 100 != 0)
                return 29;
            else
                return 28;
        else if (month == 0)
            return 0;
        else
            return 30;
    }
    void showDateOfBirth() {
        cout << "Date of birth : " << endl;
        cout << day << " / " << month << " / " << year << endl;
    }
    ~Date() {
        cout << "Destructor: Date " << endl;
    }
};
