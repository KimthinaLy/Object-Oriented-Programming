// l6Teavher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
# include "Person.c++"

using namespace std;

class Teacher: public Person {
    char teacherId[30];
    char subject[30];
    char faculty[30];
    char department[30];
    char university[50];
public:
    Teacher() {
        setTId((char*)""); setSubj((char*)""); setFac((char*)"");
        setDep((char*)""); setUni((char*)"");
    }
    Teacher(char* tId, char* subj, char* fac, char* dep, char* uni, char* pId, char* pFName, char* pLName, Date d, Address a ) :Person(pId, pFName, pLName, d, a) {
        setTId(tId); setSubj(subj); setFac(fac);
        setDep(dep); setUni(uni);
    }
    Teacher(char* tId, char* subj, char* fac, char* dep, char* pFName, char* pLName, Date d, Address a) /* : Person(pFName, pLName, d, a) */  {
        setTId(tId); setSubj(subj); setFac(fac); setDep(dep); setUni((char*)"");
        setFName(pFName); setLName(pLName); setDate(d); setAddress(a);
    }
    Teacher(char* subj, char* fac, char* dep, char* pId, char* pFName, char* pLName, Address a)/* : Person(pId, pFName, pLName, a) */ {
        setTId((char*)""); setSubj(subj); setFac(fac); setDep(dep); setUni((char*)"");
        setId(pId); setFName(pFName); setLName(pLName);  setAddress(a);
    }
    Teacher(char* fac, char* dep, char* pId, char* pFName, char* pLName, Date d) /* : Person(pId, pFName, pLName, d)*/ {
        setTId((char*)""); setSubj((char*)""); setFac(fac); setDep(dep); setUni((char*)"");
        setId(pId); setFName(pFName); setLName(pLName); setDate(d);
    }
    Teacher(char* subj, char* pId, char* pFName, char* pLName, Date d,Address a) /*: Person(pId, pFName, pLName, d,a)*/ {
        setTId((char*)""); setSubj(subj); setFac((char*)""); setDep((char*)""); setUni((char*)"");
        setId(pId); setFName(pFName); setLName(pLName); setDate(d); setAddress(a);
    }
    void setTId(char* tId) {
        strcpy(teacherId, tId);
    }
    void setSubj(char* subj) {
        strcpy(subject, subj);
    }
    void setFac(char* fac) {
        strcpy(faculty, fac);
    }
    void setDep(char* dep) {
        strcpy(department, dep);
    }
    void setUni(char* uni) {
        strcpy(university, uni);
    }
    char* getTId() {
        return teacherId;
    }
    char* getSubj() {
        return subject;
    }
    char* getFac() {
        return faculty;
    }
    char* getDep() {
        return department;
    }
    char* getUni() {
        return university;
    }
    void showTInfo() {
        cout << "---Teacher's information--- : " << endl;
        cout << "Teacher's id : " << teacherId << endl;
        cout << "Teaching subject : " << subject << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl;
        cout << "University : " << university << endl;
    }
    ~Teacher() {
    cout<<"Destructor: Teacher" << endl;
    }
};

int Person::count;

int main()
{
    cout << "object= " << Person::countObj() << endl;
    
    Teacher teacher1;
    cout << endl;
    cout << "-------- Teacher1 -------- " << endl;
    cout << "object= " << Person::countObj() << endl;
    teacher1.show();
    teacher1.getDate().showDateOfBirth();
    teacher1.getAddress().showAddress();
    teacher1.showTInfo();

    Date date2(2, 6, 1980);
    Address addr2((char*)"67", (char*)"Ramkhamheang24/10", (char*)"Village A", (char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok", 10240);
    Teacher teacher2((char*)"3002", (char*)"Data Structure", (char*)"Computer Science", (char*)"Science", (char*)"Mahidol",(char*)"4002",(char*)"Sombath",(char*)"Sri",date2, addr2);
    cout << endl;
    cout << "-------- Teacher2 --------" << endl;
    cout << "object= " << Person::countObj() << endl;
    teacher2.show();
    teacher2.getDate().showDateOfBirth();
    teacher2.getAddress().showAddress();
    teacher2.showTInfo();

    Date date3(5);
    Address addr3((char*)"Latprav53/10", (char*)"Village B", (char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok", 10240);
    Teacher teacher3((char*)"3003",(char*)"Calculous1", (char*)"Mathematic",(char*)"Science",(char*)"Alaxa",(char*)"Jasmin",date3,addr3);
    cout << endl;
    cout << "-------- Teacher3 --------" << endl;
    cout << "object= " << Person::countObj() << endl;
    teacher3.getDate().setDay(12);
    teacher3.getDate().setYear(1978);
    teacher3.show();
    teacher3.getDate().showDateOfBirth();
    teacher3.getAddress().showAddress();
    teacher3.setUni((char*)"University of Teachonology");
    teacher3.showTInfo();

    Address addr4((char*)"Village B", (char*)"Wat Phraya Krai", (char*)"Bang Kho Laem", (char*)"Bankok", 10120);
    Teacher teacher4((char*)"Calculous2",(char*)"Mathematic",(char*)"Science",(char*)"3004",(char*)"Vivoth",(char*)"Kang",addr4);
    cout << endl;
    cout << "-------- Teacher4 --------" << endl;
    cout << "object= " << Person::countObj() << endl;
    Date date4(30,4,1990);
    teacher4.setDate(date4);
    teacher4.show();
    
    teacher4.getDate().showDateOfBirth();
    cout << "Month " <<teacher4.getDate().getMonth() << " has " << teacher4.getDate().getDayofMonth() << " days" << endl;
    teacher4.getAddress().showAddress();
    teacher4.setTId((char*)"3004");
    teacher4.setUni((char*)"Ramkhamhaeng University");
    teacher4.showTInfo();

    Date date5(8,1997);
    Teacher teacher5((char*)"Civil Engineering",(char*)"Engineering", (char*)"3005", (char*)"Devit", (char*)"Jin", date5);
    cout << endl;
    cout << "-------- Teacher5 --------" << endl;
    cout << "object= " << Person::countObj() << endl;
    teacher5.show();
    teacher5.getDate().setDay(5);
    teacher5.getDate().showDateOfBirth();
    Address addr5((char*)"60", (char*)"Phetchaburi5", (char*)"Village D", (char*)"Phaya Thai", (char*)"Ratchathewi", (char*)"Bankok", 10400);
    teacher5.setAddress(addr5);
    teacher5.getAddress().showAddress();
    teacher5.setTId((char*)"3005");
    teacher5.setSubj((char*)"Environmental Health");
    teacher5.setUni((char*)"University of Wishconsin Madison");
    teacher5.showTInfo();

    Date date6(4, 4, 1990);
    Address addr6((char*)"67", (char*)"Phetchaburi15", (char*)"Village C", (char*)"Phaya Thai", (char*)"Ratchathewi", (char*)"Bankok", 10400);
    Teacher teacher6((char*)"Art", (char*)"4006", (char*)"Nawat", (char*)"Tiw", date6, addr6);
    cout << endl;
    cout << "-------- Teacher6 --------" << endl;
    cout << "object= " << Person::countObj() << endl;
    teacher6.show();
    teacher6.getDate().showDateOfBirth();
    cout << "Month " << teacher6.getDate().getMonth() << " has " << teacher6.getDate().getDayofMonth() << " days" << endl;
    teacher6.getAddress().showAddress();
    teacher6.setFac((char*)"Architecture");
    teacher6.setUni((char*)"National University of Arts");
    teacher6.showTInfo();
}


