#include "Person.c++"
class Student : virtual public Person
{
    char *studentId;
    char department[50];
    char faculty[50];
    double avg;

public:
    Student()
    {
        studentId = nullptr;
        setStdId((char *)"unknown");
        setDepartment((char *)"unknown");
        setFaculty((char *)"unknown");
        findAvg(0, 0, 0);
    }
    Student(char *sId, char *dep, char *fac, double s1, double s2, double s3, char *pId, char *pFName, char *pLName, Date d, Address a) : Person(pId, pFName, pLName, d, a)
    {
        studentId = nullptr;
        setStdId(sId);
        setDepartment(dep);
        setFaculty(fac);
        findAvg(s1, s2, s3);
    }
    Student(char *sId, char *fac, double s1, double s2, double s3, char *pFName, char *pLName, Date d, Address a) : Person(pFName, pLName, d, a)
    {
        studentId = nullptr;
        setStdId(sId);
        setDepartment((char *)"unknown");
        setFaculty(fac);
        findAvg(s1, s2, s3);
    }
    Student(char *sId, double s1, double s2, double s3, char *pId, Date d, Address a) : Person(pId, d, a)
    {
        studentId = nullptr;
        setStdId(sId);
        setDepartment((char *)"unknown");
        setFaculty((char *)"unknown");
        findAvg(s1, s2, s3);
    }
    Student(char *sId, char *dep, char *fac, char *pId, char *pFName, char *pLName, Address a) : Person(pId, pFName, pLName, a)
    {
        studentId = nullptr;
        setStdId(sId);
        setDepartment(dep);
        setFaculty(fac);
        findAvg(0, 0, 0);
    }
    Student(char *dep, char *fac, double s1, double s2, char *pId, char *pFName, char *pLName, Date d) : Person(pId, pFName, pLName, d)
    {
        studentId = nullptr;
        setStdId((char *)"unknown");
        setDepartment(dep);
        setFaculty(fac);
        findAvg(s1, s2, 0);
    }
    Student(char *sId, char *dep, char *fac)
    {
        studentId = nullptr;
        setStdId(sId);
        setDepartment(dep);
        setFaculty(fac);
        findAvg(0, 0, 0);
    }

    void setStdId(char *id)
    {
        if (studentId != nullptr)
        {
            delete[] studentId;
        }
        studentId = new char[strlen(id) + 1];
        strcpy(studentId, id);
    }
    void setDepartment(char *depm)
    {
        strcpy(department, depm);
    }
    void setFaculty(char *fac)
    {
        strcpy(faculty, fac);
    }
    void findAvg(double score1, double score2, double score3)
    {
        avg = (score1 + score2 + score3) / 3;
    }
    double& getAvg()
    {
        return avg;
    }
    char *getStudId()
    {
        return studentId;
    }
    char *getDepm()
    {
        return department;
    }
    char *getFaculty()
    {
        return faculty;
    }
    void showStudInfo()
    {
        cout << "----Student's information:----" << endl;
        cout << "Student's id = " << studentId << endl;
        cout << "Department of " << department << endl;
        cout << "Faculty of " << faculty << endl;
        cout << "Average score = " << avg << endl;
    }
    ~Student()
    {
        delete[] studentId;
        cout << "Destructor : Student" << endl;
    }

//----------------assigmentOperator, copyCon, iostream------------------------
Student(const Student &s):Person(s)
{
    cout << "copy constructor of class Student is called" << endl;
    strcpy(department,s.department);
    strcpy(this->faculty, s.faculty);
    this->avg = s.avg;
    if (s.studentId == 0)
    {
        studentId = new char[strlen("unknown") + 1];
        strcpy(studentId, "unknown");
    }

    else
    {
        this->studentId = new char[strlen(s.studentId) + 1];
        strcpy(studentId, s.studentId);
    }
}

Student &operator=(const Student &s)
{
    if (this == &s)
        return *this;
    Person::operator=(s);
    
    strcpy(department,s.department);
    strcpy(faculty, s.faculty);
    avg = s.avg;
    if (studentId != nullptr)
        delete[] studentId;
    if (s.studentId == nullptr)
    {
        this->studentId = new char[strlen("unknown") + 1];
        strcpy(studentId, (char *)"unknown");
    }
    else
    {
        this->studentId = new char[strlen(s.studentId) + 1];
        strcpy(studentId, s.studentId);
    }
    return *this;
}
Student &operator+=(const Student &s)
{
    Person::operator+=(s);
    strcat(department, "+");
    strcat(department, s.department);
    strcat(faculty, "+");
    strcat(faculty, s.faculty);
    this->avg += s.avg;
    if (s.studentId != nullptr)
    {
        char *newChar = new char[strlen(studentId) + strlen(s.studentId) + 2];
        strcpy(newChar,studentId);
        strcat(newChar, "+");
        strcat(newChar, s.studentId);
        delete[] studentId;
        studentId = newChar;
    }
    return *this;
}

 void print(ostream& os) {
    Person::print(os);
     os << "--------Student----------" << endl;
     os << "student's id = " << studentId << endl;
     os << "department = " << department<<endl;
     os << "faculty = " << faculty << endl;
     os << "avg = " << avg << endl;
     
 }

   void input(istream& is) {
    Person::input(is);
     int score1, score2, score3;
     char tempId[30];
     cout << "Enter student's id: "; is >> tempId;
     delete[] studentId;
     studentId = new char[strlen(tempId) + 1];
     strcpy(studentId,tempId);
     cout << "Enter department: "; is >> department;
     cout << "Enter faculty: "; is >> faculty;
     cout << "Enter homework score: "; is >> score1;
     cout << "Enter midterm score: "; is >> score2;
     cout << "Enter final  score: "; is >> score3;

     findAvg(score1, score2, score3);
 }
};

ostream& operator<<(ostream& os, Student& s){
    s.print(os);
    return os;
}
istream& operator>>(istream& is, Student& s){
    s.input(is);
    return is;
}
