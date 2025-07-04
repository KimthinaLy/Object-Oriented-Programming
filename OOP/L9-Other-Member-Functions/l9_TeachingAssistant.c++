
#include "Student.c++"
#include "Teacher.c++"
class TeachingAssistant : public Student, public Teacher
{
    char *assistanceId;
    char role[30];
    double gpa;

public:
    TeachingAssistant()
    {
        assistanceId = nullptr;
        setAssiId((char *)"unknown");
        setAssiRole((char *)"");
        setGPA(0);
    }

    TeachingAssistant(char *TAId, char *rol, double g, char *sId, char *dep, char *fac, double s1, double s2, double s3,
                      char *pId, char *pFName, char *pLName, Date d, Address a, char *tId, char *subj, char *uni)
        : Person(pId, pFName, pLName, d, a),
          Student(sId, dep, fac, s1, s2, s3, pId, pFName, pLName, d, a),
          Teacher(tId, subj, fac, dep, uni, pId, pFName, pLName, d, a)
    {
        assistanceId = nullptr;
        setAssiId(TAId);
        setAssiRole(rol);
        setGPA(g);
    }
    TeachingAssistant(char *aId, char *rol, char *sId, char *fac, double s1, double s2, double s3, char *pFName, char *pLName, Date d, Address a, char *tId, char *subj, char *dep)
        : Person(pFName, pLName, d, a),
          Student(sId, fac, s1, s2, s3, pFName, pLName, d, a),
          Teacher(tId, subj, fac, dep, pFName, pLName, d, a)
    {
        assistanceId = nullptr;
        setAssiId(aId);
        setAssiRole(rol);
        setGPA(0);
    }
    TeachingAssistant(char *rol, char *sId, char *dep, char *fac, char *pId, char *pFName, char *pLName, Address a, char *subj)
        : Person(pId, pFName, pLName, a),
          Student(sId, dep, fac, pId, pFName, pLName, a),
          Teacher(subj, fac, dep, pId, pFName, pLName, a)
    {
        assistanceId = nullptr;
        setAssiId((char *)"unknown");
        setAssiRole(rol);
        setGPA(0);
    }
    TeachingAssistant(char *dep, char *fac, double s1, double s2, char *pId, char *pFName, char *pLName, Date d)
        : Person(pId, pFName, pLName, d),
          Student(dep, fac, s1, s2, pId, pFName, pLName, d),
          Teacher(fac, dep, pId, pFName, pLName, d)
    {
        assistanceId = nullptr;
        setAssiId((char *)"unknown");
        setAssiRole((char *)"");
        setGPA(0);
    }
    void setAssiId(char *aId)
    {

        delete[] assistanceId;
        if (strcmp(aId, "") == 0)
        {
            assistanceId = new char[strlen("unknown") + 1];
            strcpy(assistanceId, ((char *)"unknown"));
        }
        else
        {
            assistanceId = new char[strlen(aId) + 1];
            strcpy(assistanceId, aId);
        }
    }
    void setAssiRole(char *rol)
    {
        strcpy(role, rol);
    }
    void setGPA(double g)
    {
        gpa = g;
    }
    char *getAssiId()
    {
        return assistanceId;
    }
    char *getAssiRole()
    {
        return role;
    }
    double getGPA()
    {
        return gpa;
    }
    void showTA()
    {
        cout << "---TeachingAssistance's information:--- " << endl;
        cout << "TA's Id: " << assistanceId << endl;
        cout << "TA's role: " << role << endl;
        cout << "TA's GPA: " << gpa << endl;
    }
    ~TeachingAssistant()
    {
        delete[] assistanceId;
        cout << "Destructor : Teaching Assistance" << endl;
    }

    //----------------------assignmentoperator, copyCon, iostream-------------------

    TeachingAssistant &operator=(TeachingAssistant &ta)
    {
        if (this == &ta)
            return *this;

        Teacher::operator=(ta);

        this->setDepartment(ta.getDepm());
        this->setFaculty(ta.getFaculty());
        this->getAvg() = ta.getAvg();
        this->setStdId(ta.getStudId());

        strcpy(role, ta.role);
        gpa = ta.gpa;
        if (assistanceId != nullptr)
        {
            delete[] assistanceId;
        }

        if (ta.assistanceId != nullptr)
        {
            assistanceId = new char[strlen(ta.assistanceId) + 1];
            strcpy(assistanceId, ta.assistanceId);
        }
        else
        {
            assistanceId = new char[strlen("unknown") + 1];
            strcpy(assistanceId, (char *)"unknown");
        }
        return *this;
    }
    TeachingAssistant &operator+=(TeachingAssistant &ta)
    {
        Teacher::operator+=(ta);

        strcat(this->getDepm(), "+");
        strcat(this->getDepm(), ta.getDepm());
        strcat(this->getFaculty(), "+");
        strcat(this->getFaculty(), ta.getFaculty());
        this->getAvg() += ta.getAvg();
        if (ta.getStudId() != nullptr)
        {
            char *newChar = new char[strlen(this->getStudId()) + strlen(ta.getStudId()) + 2];
            strcpy(newChar, this->getStudId());
            strcat(newChar, "+");
            strcat(newChar, ta.getStudId());
            this->setStdId(newChar);
            delete[] newChar;

            gpa += ta.gpa;
            strcat(role, "+");
            strcat(role, ta.role);
            if (ta.role != nullptr)
            {
                char *newChar = new char[strlen(assistanceId) + strlen(ta.assistanceId) + 2];
                strcpy(newChar, assistanceId);
                strcat(newChar, "+");
                strcat(newChar, ta.assistanceId);
                delete[] assistanceId;
                assistanceId = newChar;
            }
            return *this;
        }
    }
    TeachingAssistant(const TeachingAssistant &ta) : Student(ta), Teacher(ta), Person(ta)
    {
        cout << "copy constructor of class TeachingAssistant is called" << endl;
        gpa = ta.gpa;
        strcpy(role, ta.role);
        if (ta.assistanceId != nullptr)
        {
            assistanceId = new char[strlen(ta.assistanceId) + 1];
            strcpy(assistanceId, ta.assistanceId);
        }
        else
        {
            assistanceId = new char[strlen("unknown") + 1];
            strcpy(assistanceId, (char *)"unknown");
        }
    }
    void print(ostream &os)
    {
        Teacher::print(os);
        this->showStudInfo();
        os << "---TeachingAssistance's information:--- " << endl;
        os << "TA's Id: " << assistanceId << endl;
        os << "TA's role: " << role << endl;
        os << "TA's GPA: " << gpa << endl;
    }
    void input(istream &is)
    {
        Teacher::input(is);

        int score1, score2, score3;
        char newStudentId[30], newDep[30], newFac[30];
        cout << "Enter student's id: ";
        is >> newStudentId;
        this->setStdId(newStudentId);
        cout << "Enter department: ";
        is >> newDep;
        this->setDepartment(newDep);
        cout << "Enter faculty: ";
        is >> newFac;
        this->setFaculty(newFac);
        cout << "Enter homework score: ";
        is >> score1;
        cout << "Enter midterm score: ";
        is >> score2;
        cout << "Enter final  score: ";
        is >> score3;

        findAvg(score1, score2, score3);

        char newTAId[30];
        cout << "Enter TA id: ";
        is >> newTAId;
        setAssiId(newTAId);
        cout << "Enter TA role: ";
        is >> role;
        cout << "Enter TA gpa: ";
        is >> gpa;
    }
};
ostream &operator<<(ostream &os, TeachingAssistant &ta)
{
    ta.TeachingAssistant::print(os);
    return os;
}
istream &operator>>(istream &is, TeachingAssistant &ta)
{
    ta.TeachingAssistant::input(is);
    return is;
}

int Person::count;
int main()
{
    Address addr2((char *)"67", (char *)"Ramkhamheang24/10", (char *)"Village A", (char *)"Hua Mak", (char *)"Bank kapi", (char *)"Bankok", 10240);
    Date date2(13, 11, 2002);
    TeachingAssistant TA1((char *)"aaaaaaaaaaa", (char *)"Lab", 3.78, (char *)"1001", (char *)"Science", (char *)"Computer Science", 50, 50, 25.5, (char *)"2001", (char *)"Visith", (char *)"Lay", date2, addr2, (char *)"0", (char *)"Programming Language", (char *)"XYZ");
    cout << endl
         << "-----------cout-TA1:---------" << endl;
    cout << TA1;

    TeachingAssistant TA2;
    cout << "---------cin-TA2----------" << endl;
    cin >> TA2;
    cout << endl
         << "-----------cout-TA2:---------" << endl;
    cout << TA2;

    TA1 += TA2;
    cout << "----------TA1+=TA2----------" << endl;
    cout << TA1;

    TeachingAssistant TA3;
    cout << endl;
    cout << "------------cout-TA3----------" << endl;
    cout << TA3;
    cout << "------------TA3=TA1----------" << endl;
    TA3 = TA1;
    operator<<(cout, TA3);

    cout << "------TA2:Teacher---------" << endl;
    TA2.Teacher::print(cout);
    cout << "------TA3before modify teacher---------" << endl;
    TA3.Teacher::print(cout);
    TA3.Teacher::operator+=(TA2);
    cout << "------TA3+=TA2:Teacher---------" << endl;
    TA3.Teacher::print(cout);

    TeachingAssistant TA4 = TA3;
    cout << "------------cout-TA3----------" << endl;
    cout << TA3;
    cout << "------------cout-TA4----------" << endl;
    operator<<(cout, TA4);

    TeachingAssistant TA5;
    cout << "--------------TA5--------------" << endl;
    cout << TA5;
    cout << "-------------TA4:Person------------" << endl;
    TA4.Person::print(cout);
    cout << "------------after modify person of TA5------" << endl;
    TA5.Person::operator=(TA4);
    TA5.Person::print(cout);

    TeachingAssistant TA6(TA5);
    cout << "---------------TA6-------------" << endl;
    cout << TA6;
}