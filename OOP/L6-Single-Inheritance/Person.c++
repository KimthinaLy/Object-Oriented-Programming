#include "Address.c++"
#include "Date.c++"
#include <string.h>

class Person
{
  char id[20];
  char firstName[30];
  char lastName[30];
  Date date;
  Address addr;
  static int count;

public:
  Person()
  {
    count++;
    setId((char *)"");
    setLName((char *)"");
    setFName((char *)"");
  }
  Person(char *personId, char *fName, char *lName, Date d, Address adr)
  {
    count++;
    setId(personId);
    setLName(lName);
    setFName(fName);
    setDate(d);
    setAddress(adr);
  }
  Person(char *fName, char *lName, Date d, Address adr)
  {
    count++;
    setId((char *)"unknown");
    setLName(lName);
    setFName(fName);
    setDate(d);
    setAddress(adr);
  }
  Person(char *personId, Date d, Address adr)
  {
    count++;
    setId(personId);
    setLName((char *)"No name");
    setFName((char *)"");
    setDate(d);
    setAddress(adr);
  }
  Person(char *personId, char *fName, char *lName, Address adr)
  {
    count++;
    setId(personId);
    setLName(lName);
    setFName(fName);
    setDate(Date());
    setAddress(adr);
  }
  Person(char *personId, char *fName, char *lName, Date d)
  {
    count++;
    setId(personId);
    setLName(lName);
    setFName(fName);
    setDate(d);
    setAddress(Address());
  }
  void setId(char *personId)
  {
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
  Date getDate()
  {
    return date;
  }
  Address getAddress()
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
  void show()
  {
    cout << "id: " << id << endl;
    cout << "Full name: " << firstName << " " << lastName << endl;
    cout << "Age = " << getAge(2024) << endl;
  }
  static int countObj() { return count; }
  ~Person()
  {
    count--;
    // cout << "Destructor object = " << count << endl;
    cout << "Destructor: Person  " << endl;
  }
};