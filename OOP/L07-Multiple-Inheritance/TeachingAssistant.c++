# include "Person.c++"

class Student : virtual public Person {
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

class Teacher:virtual public Person {
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

class TeachingAssistant :public Student, public Teacher{
    char assistId[15];
    char role[30];
    double gpa;
public:
    TeachingAssistant() {
        setAssiId((char*)""); setAssiRole((char*)""); setGPA(0);
    }
    
    TeachingAssistant(char* aId, char* rol, double g, char* sId, char* dep, char* fac, double s1, double s2, double s3, 
                  char* pId, char* pFName, char* pLName, Date d, Address a, char* tId, char* subj, char* uni)
        :  Person(pId, pFName, pLName, d, a),
        Student(sId, dep, fac, s1, s2, s3, pId, pFName, pLName, d, a), 
        Teacher(tId, subj, fac, dep, uni, pId, pFName, pLName, d, a) { 
    setAssiId(aId);
    setAssiRole(rol);
    setGPA(g);
    }
    TeachingAssistant(char* aId, char* rol, char* sId, char* fac, double s1, double s2, double s3, char* pFName, char* pLName, Date d, Address a, char* tId, char* subj,char* dep)
        : Person( pFName, pLName, d, a),
        Student(sId,  fac, s1, s2, s3,  pFName, pLName, d, a),
        Teacher(tId, subj, fac, dep,  pFName, pLName, d, a) {
        setAssiId(aId);
        setAssiRole(rol);
        setGPA(0);
    }
    TeachingAssistant(char* rol, char* sId, char* dep, char* fac, char* pId, char* pFName, char* pLName, Address a,char* subj)
        : Person(pId, pFName, pLName, a),
        Student(sId,  dep,fac, pId, pFName,pLName, a),
        Teacher( subj, fac, dep, pId, pFName,pLName, a) {
        setAssiId((char*)"unknown");
        setAssiRole(rol);
        setGPA(0);
    }
    TeachingAssistant(char* dep, char* fac, double s1, double s2, char* pId, char* pFName, char* pLName, Date d)
    :Person(pId,pFName,pLName,d),
    Student(dep,fac,s1,s2,pId,pFName,pLName,d),
    Teacher(fac,dep, pId, pFName, pLName, d){
        setAssiId((char*)"unknown");
        setAssiRole((char*)"");
        setGPA(0);
    }
    void setAssiId(char* aId) {
        strcpy(assistId, aId);
    }
    void setAssiRole(char* rol) {
        strcpy(role, rol);
    }
    void setGPA(double g) {
        gpa = g;
    }
    char* getAssiId() {
        return assistId;
    }
    char* getAssiRole() {
        return role;
    }
    double getGPA() {
        return gpa;
    }
    void showTA() {
        cout << "---TeachingAssistance's information:--- " << endl;
        cout << "TA's Id: " << assistId << endl;
        cout << "TA's role: " << role << endl;
        cout << "TA's GPA: " << gpa << endl;
    }
    ~TeachingAssistant() {
        cout << "Destructor : Teaching Assistance" << endl;
    }
};

int Person::count;

int main(){
  TeachingAssistant TA1;
cout << "----TeachingAssitant1:----" << endl;
TA1.show(); TA1.getAddress().showAddress(); TA1.getDate().showDateOfBirth();
TA1.showStudInfo(); TA1.showTInfo(); TA1.showTA();

Address addr2((char*)"67", (char*)"Ramkhamheang24/10", (char*)"Village A", (char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok", 10240);
Date date2(13, 11, 2002);
TeachingAssistant TA2((char*)"4001",(char*)"Lab",3.78, (char*)"1001", (char*)"Science", (char*)"Computer Science", 50, 50, 25.5, (char*)"2001", (char*)"Visith", (char*)"Lay", date2, addr2,(char*)"0",(char*)"Programming Language",(char*)"XYZ");
cout << endl<<"----TeachingAssitant2:----" << endl;
TA2.show(); TA2.getAddress().showAddress(); TA2.getDate().showDateOfBirth();
TA2.showStudInfo(); TA2.showTInfo(); TA2.showTA();

Date date3(4, 2004);
date3.setDay(9);
Address addr3((char*)"Ramkhamheang53/10", (char*)"Village B", (char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok", 10240);
TeachingAssistant TA3((char*)"4002", (char*)"Lab",(char*)"1003", (char*)"Civil Enginnering", 40.5, 0, 50, (char*)"layla", (char*)"Star", date3, addr3,(char*)"0",(char*)"Machanic",(char*)"Engineering");
TA3.setGPA(3.66);
TA3.setId((char*)"2003");
TA3.setUni((char*)"AAA");
cout << endl << "----TeachingAssitant3:----" << endl;
TA3.show(); TA3.getAddress().showAddress(); TA3.getDate().showDateOfBirth();
TA3.showStudInfo(); TA3.showTInfo(); TA3.showTA();

//char* rol, char* sId, char* dep, char* fac, char* pId, char* pFName, char* pLName, Address a,char* subj
Address addr4((char*)"Phaya Thai", (char*)"Ratchatewi", (char*)"Bankok", 10400);
TeachingAssistant TA4((char*)"Lecture", (char*)"1004", (char*)"Science", (char*)"Food Science", (char*)"2005", (char*)"Vexana", (char*)"bi", addr4,(char*)"Chemistry");
TA4.getDate().setDateOfBirth(1, 1, 2000);
TA4.setGPA(4.0);
TA4.setUni((char*)"MNO");
cout <<endl<< "----TeachingAssitant4:----" << endl;
TA4.show(); TA4.getAddress().showAddress(); TA4.getDate().showDateOfBirth();
TA4.showStudInfo(); TA4.showTInfo(); TA4.showTA();

Date date5(2, 2024);
TeachingAssistant TA5((char*)"Engineering", (char*)"Machanical Engineering", 40, 30.4, (char*)"2006", (char*)"Jasmine", (char*)"Li", date5);
TA5.setStdId((char*)"1006");
Address addr5((char*)"Village B", (char*)"Hua Mak", (char*)"Bank kapi", (char*)"Bankok", 10240);
TA5.setAddress(addr5);
TA5.getAddress().setHouseNo((char*)"8A");
TA5.setGPA(3.33);
TA5.setAssiRole((char*)"Grade record");
TA5.setAssiId((char*)"4005");
TA5.setUni((char*)"ABC");
cout  << "\n----TeachingAssitant5:----" << endl;
TA5.show(); TA5.getAddress().showAddress(); TA5.getDate().showDateOfBirth();
TA5.showStudInfo(); TA5.showTInfo(); TA5.showTA();
}
