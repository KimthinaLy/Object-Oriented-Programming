// l6Student.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

# include "Person.c++"

class Student : public Person {
    char studentId[15];
    char department[30];
    char faculty[30];
    double avg;
public:
    Student() {
        setStdId((char*)""); setDepartment((char*)""); setFaculty((char*)""); findAvg(0, 0, 0);
    }
    Student(char* sId, char* dep, char* fac, double s1, double s2, double s3, char* pId, char* pFName, char* pLName, Date d, Address a) : Person(pId, pFName, pLName,d,a) {
        setStdId(sId); setDepartment(dep); setFaculty(fac); findAvg(s1, s2, s3);
    }
    Student(char* sId, char* fac, double s1, double s2, double s3, char* pFName, char* pLName, Date d, Address a) : Person(pFName, pLName, d, a) {
        setStdId(sId); setDepartment((char*)":unknown"); setFaculty(fac); findAvg(s1, s2, s3);
    }
    Student(char* sId, double s1, double s2, double s3, char* pId, Date d, Address a) : Person(pId,d, a) {
        setStdId(sId); setDepartment((char*)":unknown"); setFaculty((char*)":unknown"); findAvg(s1, s2, s3);
    }
    Student(char* sId, char* dep, char* fac, char* pId, char* pFName,char* pLName, Address a) : Person(pId,pFName, pLName, a) {
        setStdId(sId); setDepartment(dep); setFaculty(fac); findAvg(0, 0, 0);
    }
    Student(char* dep, char* fac, double s1, double s2, char* pId, char* pFName, char* pLName, Date d) : Person(pId, pFName, pLName, d) {
        setStdId((char*)""); setDepartment(dep); setFaculty(fac); findAvg(s1, s2, 0);
    }
    Student(char* sId, char* dep, char* fac) {
        setStdId(sId); setDepartment(dep); setFaculty(fac); findAvg(0, 0, 0);
    }
    void setStdId(char* id) {
        strcpy(studentId, id);
    }
    void setDepartment(char* depm) {
        strcpy(department, depm);
    }
    void setFaculty(char* fac) {
        strcpy(faculty, fac);
    }
    void findAvg(double score1, double score2, double score3) {
        avg = (score1 + score2 + score3) / 3;
    }
    double getAvg() {
        return avg;
    }
    char* getStudId() {
        return studentId;
    }
    char* getDepm() {
        return department;
    }
    char* getFaculty() {
        return faculty;
    }
    void showStudInfo() {
        cout << "Student's id = " << studentId << endl;
        cout << "Department of " << department << endl;
        cout << "Faculty of " << faculty << endl;
        cout << "Average score = " << avg << endl;
    }
    ~Student() {
        cout << "Destructor : Student" << endl;
    }

};
int Person::count;
int main() {
    cout << "object= " << Person::countObj() << endl;

    Student student1;
    cout << endl;
    cout << "Person 1:" << endl;
    cout << "object= " << Person::countObj() << endl;
    student1.show();
    student1.getDate().showDateOfBirth();
    student1.getAddress().showAddress();
    student1.showStudInfo();

    Date date2(13, 11, 2002);
    Address addr2((char*)"67", (char*)"Ramkhamheang24/10", (char*)"Village A",(char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok",10240);
    Student student2((char*)"1001", (char*)"Science", (char*)"Computer Science", 50, 50, 25.5, (char*)"2001",(char*)"Visith", (char*)"Lay", date2, addr2);
    cout << endl;
    cout << "Person 2" << endl;
    cout << "object = " << Person::countObj() << endl;
    student2.show();
    student2.getDate().showDateOfBirth();
    student2.getAddress().showAddress();
    student2.showStudInfo();
    cout << "Month " << student2.getDate().getMonth() << " has " << student2.getDate().getDayofMonth() << " days" << endl;
   
    Date date3(4, 2004);
    Address addr3( (char*)"Ramkhamheang53/10", (char*)"Village B", (char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok", 10240);
    Student student3((char*)"1003",(char*)"Civil Enginnering", 40.5, 0, 50, (char*)"layla",(char*)"Star",date3,addr3);
    cout << endl;
    cout << "Person 3: " << endl;
    cout << "object = " << Person::countObj() << endl;
    student3.show();
    student3.setId((char*)"1003");
    cout << "After set id = " << student3.getId() << endl;
    student3.getDate().showDateOfBirth();
    student3.getAddress().showAddress();
    student3.showStudInfo();

    Date date4(12);
    Address addr4((char*)"Village B", (char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok", 10240);
    Student student4((char*)"1004", 30.5, 50, 40.5, (char*)"2004", date4, addr4);
    cout << endl;
    cout << "Person 4: " << endl;
    cout << "object = " << Person::countObj() << endl;
    student4.getDate().setYear(1999);//won't update
    student4.show();
    student4.getDate().setDay(20);//won't update
    student4.getDate().showDateOfBirth();
    student4.getAddress().showAddress();
    student4.showStudInfo();
    cout << "Month " << student4.getDate().getMonth() << " has " << student4.getDate().getDayofMonth() << " days" << endl;

    Address addr5((char*)"Phaya Thai", (char*)"Ratchatewi", (char*)"Bankok", 10400);
    Student student5((char*)"1003", (char*)"Science", (char*)"Food Science", (char*)"2005",(char*)"Vexana", (char*)"bi", addr5);
    cout << endl;
    cout << "Person 5: " << endl;
    cout << "object = " << Person::countObj() << endl;
    student5.show();
    student5.getDate().setDateOfBirth(1, 1, 2000);//won't update
    student5.getDate().showDateOfBirth();
    student5.getAddress().setProvince((char*)"Nakhon Pathum");//won't update
    student5.getAddress().showAddress();
    student5.showStudInfo();

    Date date6(2, 2024);
    Student student6((char*)"Engineering", (char*)"Machanical Engineering", 40, 30.4, (char*)"2006", (char*)"Jasmine", (char*)"Li",date6);
    cout << endl;
    student6.setStdId((char*)"1006");
    cout << "Person 6: " << endl;
    cout << "object = " << Person::countObj() << endl;
    student6.show();
    student6.getDate().showDateOfBirth();//won't update
    student6.getAddress().setProvince((char*)"Burirum");
    student6.getAddress().showAddress();
    student6.showStudInfo();

    Student student7((char*)"1007", (char*)"Engineering", (char*)"Civil Engineer");
    cout << endl;
    cout << "Person 7: " << endl;
    cout << "object = " << Person::countObj() << endl;
    student7.setFName((char*)"Somnang");
    student7.setLName((char*)"Som");
    student7.show();
    student7.getDate().showDateOfBirth();
    student7.getAddress().showAddress();
    student7.findAvg(20, 50, 50);
    student7.showStudInfo();
    cout << endl;
    
}
