#ifndef _Person_h_
#define _Person_h_
#include <cstring>
#include "Date.c++"
#include "Address.c++"

class Person
{
    char *id;
    char firstName[50];
    char lastName[50];
    Date date;
    Address addr;
    static int count;

public:
    Person()
    {
        count++;
        id = nullptr;
        setId((char *)"unknown");
        setLName((char *)"");
        setFName((char *)"");
    }
    Person(char *personId, char *fName, char *lName, Date d, Address adr)
    {
        count++;
        id = nullptr;
        setId(personId);
        setLName(lName);
        setFName(fName);
        setDate(d);
        setAddress(adr);
    }
    Person(char *fName, char *lName, Date d, Address adr)
    {
        count++;
        id = nullptr;
        setId((char *)"unknown");
        setLName(lName);
        setFName(fName);
        setDate(d);
        setAddress(adr);
    }
    Person(char *personId, Date d, Address adr)
    {
        count++;
        id = nullptr;
        setId(personId);
        setLName((char *)"No name");
        setFName((char *)"");
        setDate(d);
        setAddress(adr);
    }
    Person(char *personId, char *fName, char *lName, Address adr)
    {
        count++;
        id = nullptr;
        setId(personId);
        setLName(lName);
        setFName(fName);
        setDate(Date());
        setAddress(adr);
    }
    Person(char *personId, char *fName, char *lName, Date d)
    {
        count++;
        id = nullptr;
        setId(personId);
        setLName(lName);
        setFName(fName);
        setDate(d);
        setAddress(Address());
    }
    void setId(char *personId)
    {
        if (personId != nullptr)
        {
            delete[] id;
        }
        id = new char[strlen(personId) + 1];
        strcpy(id, personId);
    }
    void setFName(char *fname)
    {
        strcpy(firstName, fname);
    }
    void setLName(char *lName)
    {
        strcpy(lastName, lName);
    }
    void setDate(Date d)
    {
        date = d;
    }
    void setAddress(Address a)
    {
        addr = a;
    }
    char *getId()
    {
        return id;
    }
    char *getfName()
    {
        return firstName;
    }
    char *getlName()
    {
        return lastName;
    }
    Date &getDate()
    {
        return date;
    }
    Address &getAddress()
    {
        return addr;
    }
    int getAge(int currentYear)
    {
        int age = 0;
        if (date.getYear() != 0 && currentYear >= date.getYear())
            age = currentYear - date.getYear();
        else
            cout << "Age error" << endl;
        return age;
    }
    void showPerson()
    {
        cout << "--------Person---------" << endl;
        cout << "Citizen id: " << id << endl;
        cout << "Full name: " << firstName << " " << lastName << endl;
        cout << "Age = " << getAge(2024) << endl;
    }
    static int countObj() { return count; }
    virtual ~Person()
    {
        delete[] id;
        count--;
        // cout << "Destructor object = " << count << endl;
        cout << "Destructor: Person  " << endl;
    }

    //-----------------assignmentOperator conpyCon iostream--------------

    Person &operator=(const Person &p)
    {
        if (this == &p)
            return *this;
        if (id != nullptr)
        {
            delete[] id;
        }
        if (p.id != nullptr)
        {
            id = new char[strlen(p.id) + 1];
            strcpy(id, p.id);
        }
        else
        {
            id = new char[strlen("no data") + 1];
            strcpy(id, (char *)"no data");
        }
        strcpy(firstName, p.firstName);
        strcpy(lastName, p.lastName);
        date = p.date;
        addr = p.addr;
        return *this;
    }
    Person &operator+=(const Person &p)
    {
        if (p.id != nullptr)
        {
            char *newId = new char[strlen(id) + strlen(p.id) + 2];
            strcpy(newId, id);
            strcat(newId, "+");
            strcat(newId, p.id);
            delete[] id;
            id = newId;
        }
        strcat(firstName, "+");
        strcat(firstName, p.firstName);
        strcat(lastName, "+");
        strcat(lastName, p.lastName);
        date += p.date;
        addr += p.addr;
    }

    Person(const Person &p)
    {
        cout << "copy constructor of class Person is called" << endl;
        if (p.id == nullptr)
        {
            id = new char[strlen("unknow") + 1];
            strcpy(id, "unknow");
        }
        else
        {
            id = new char[strlen(p.id) + 1];
            strcpy(id, p.id);
        }

        strcpy(firstName, p.firstName);
        strcpy(lastName, p.lastName);
        date = p.date;
        addr.operator=(p.addr);
    }
    virtual void print(ostream &os)
    {
        os << "Person: id= " << id << ", Fullname: " << firstName << " " << lastName << endl;
        addr.print(os);
        os << "Person: data of birth= " << date.getDay() << "\\" << date.getMonth() << "\\" << date.getYear() << endl;
    }
    virtual void input(istream &is)
    {
        char newChar[30];
        cout << "Input person id: ";
        is >> newChar;
        setId(newChar);
        cout << "Input person firstName: ";
        is >> firstName;
        cout << "Input person lastName: ";
        is >> lastName;
        int newDay, newMonth, newYear;
        setDate(Date());
        cout << "Input day of birth: ";
        is >> newDay;
        date.setDay(newDay);
        cout << "Input month of birth: ";
        is >> newMonth;
        date.setMonth(newMonth);
        cout << "Input year of birth: ";
        is >> newYear;
        date.setYear(newYear);
        char newHouseNo[30], newRoad[30], newVill[30], newSubDis[30], newDistr[30], newProv[30];
        int newPostCode;
        cout << "Enter house number: ";
        is >> newHouseNo;
        cout << "Enter road: ";
        is >> newRoad;
        cout << "Enter village: ";
        is >> newVill;
        cout << "Enter subDistrict: ";
        is >> newSubDis;
        cout << "Enter district: ";
        is >> newDistr;
        cout << "Enter province: ";
        is >> newProv;
        cout << "Enter postCode: ";
        is >> newPostCode;

        setAddress(Address(newHouseNo, newRoad, newVill, newSubDis, newDistr, newProv, newPostCode));
    }
};

int Person::count;

#endif