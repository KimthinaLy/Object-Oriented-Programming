#include "Person.c++"
class Teacher : virtual public Person
{
    char teacherId[50];
    char subject[50];
    char faculty[50];
    char department[50];
    char **university;

public:
    Teacher()
    {
        university = new char *[1];
        university[0] = nullptr;
        setTId((char *)"");
        setSubj((char *)"");
        setFac((char *)"");
        setDep((char *)"");
        setUni((char *)"unknown");
    }
    Teacher(char *tId, char *subj, char *fac, char *dep, char *uni, char *pId, char *pFName, char *pLName, Date d, Address a) : Person(pId, pFName, pLName, d, a)
    {
        university = new char *[1];
        university[0] = nullptr;
        setTId(tId);
        setSubj(subj);
        setFac(fac);
        setDep(dep);
        setUni(uni);
    }
    Teacher(char *tId, char *subj, char *fac, char *dep, char *pFName, char *pLName, Date d, Address a)
    {
        university = new char *[1];
        university[0] = nullptr;
        setTId(tId);
        setSubj(subj);
        setFac(fac);
        setDep(dep);
        setUni((char *)"unknown");
        setFName(pFName);
        setLName(pLName);
        setDate(d);
        setAddress(a);
    }
    Teacher(char *subj, char *fac, char *dep, char *pId, char *pFName, char *pLName, Address a)
    {
        university = new char *[1];
        university[0] = nullptr;
        setTId((char *)"");
        setSubj(subj);
        setFac(fac);
        setDep(dep);
        setUni((char *)"unknown");
        setId(pId);
        setFName(pFName);
        setLName(pLName);
        setAddress(a);
    }
    Teacher(char *fac, char *dep, char *pId, char *pFName, char *pLName, Date d)
    {
        university = new char *[1];
        university[0] = nullptr;
        setTId((char *)"");
        setSubj((char *)"");
        setFac(fac);
        setDep(dep);
        setUni((char *)"unknown");
        setId(pId);
        setFName(pFName);
        setLName(pLName);
        setDate(d);
    }
    Teacher(char *subj, char *pId, char *pFName, char *pLName, Date d, Address a)
    {
        university = new char *[1];
        university[0] = nullptr;
        setTId((char *)"");
        setSubj(subj);
        setFac((char *)"");
        setDep((char *)"");
        setUni((char *)"unknown");
        setId(pId);
        setFName(pFName);
        setLName(pLName);
        setDate(d);
        setAddress(a);
    }
    void setTId(char *tId)
    {
        strcpy(teacherId, tId);
    }
    void setSubj(char *subj)
    {
        strcpy(subject, subj);
    }
    void setFac(char *fac)
    {
        strcpy(faculty, fac);
    }
    void setDep(char *dep)
    {
        strcpy(department, dep);
    }
    void setUni(char *uni)
    {
        if (university[0] != nullptr)
        {
            delete university[0];
        }
        if (strcmp(uni, "") == 0)
        {
            university[0] = new char[strlen("unknown") + 1];
            strcpy(university[0],(char *)"unknown");
        }
        else
        {
            university[0] = new char[strlen(uni) + 1];
            strcpy(university[0], uni);
        }
    }
    char *getTId()
    {
        return teacherId;
    }
    char *getSubj()
    {
        return subject;
    }
    char *getFac()
    {
        return faculty;
    }
    char *getDep()
    {
        return department;
    }
    char *getUni()
    {
        return university[0];
    }
    void showTInfo()
    {
        cout << "---Teacher's information--- : " << endl;
        cout << "Teacher's id : " << teacherId << endl;
        cout << "Teaching subject : " << subject << endl;
        cout << "Faculty : " << faculty << endl;
        cout << "Department : " << department << endl;
        cout << "University : " << university[0] << endl;
    }
    ~Teacher()
    {
        delete[] university[0];
        delete[] university;
        cout << "Destructor: Teacher" << endl;
    }

    //-------------------assignmentOperator, copyCon, iostream--------------------
    Teacher &operator=(const Teacher &t)
    { 
        Person::operator=(t);
        if (this == &t)
            return *this;
            
        strcpy(teacherId, t.teacherId);
        strcpy(subject, t.subject);
        strcpy(faculty, t.faculty);
        strcpy(department, t.department);
        if(university[0]!=nullptr){
            delete university[0];
        }

        if (t.university[0] != nullptr)
        {
            university[0] = new char[strlen(t.university[0]) + 1];
            strcpy(university[0], t.university[0]);
        }
        else
        {
            university[0] = new char[strlen("unknown") + 1];
            strcpy(university[0], (char *)"unknown");
        }
        return *this;
    }

    Teacher &operator+=(const Teacher &t)
    {
        Person::operator+=(t);
        strcat(teacherId, "+");
        strcat(teacherId, t.teacherId);
        strcat(subject, "+");
        strcat(subject, t.subject);
        strcat(faculty, "+");
        strcat(faculty, t.faculty);
        strcat(department, "+");
        strcat(department, t.department);
        if (t.university[0] != nullptr)
        {
            char *newChar = new char[strlen(university[0]) + strlen(t.university[0]) + 2];
            strcpy(newChar, university[0]);
            strcat(newChar, "+");
            strcat(newChar, t.university[0]);
            delete[] university[0];
           university[0]=newChar;
        }
        return *this;
    }
    Teacher(const Teacher &t): Person(t)
    {
     cout<<"copy constructor of class Teacher is called"<<endl;   

         strcpy(teacherId,t.teacherId);
         strcpy(subject,t.subject);
         strcpy(faculty,t.faculty);
         strcpy(department, t.department);
         university=new char*[1];
         if(t.university[0]!=nullptr){
            
             university[0]=new char[strlen(t.university[0])+1];
             strcpy(university[0],t.university[0]);
         }else{
             university[0]=new char[strlen("unknown")+1];
             strcpy(university[0],(char*)"unknown");
         }
    }
    void print(ostream &os)
    {
        Person::print(os);
        os << "Teacher id= " << teacherId << endl;
        os << "Teacher subject= " << subject << endl;
        os << "Teacher faculty= " << faculty << endl;
        os << "Teacher department= " << department << endl;
        os << "Teacher university= " << university[0] << endl;
    }

    void input(istream &is)
    {
        Person::input(is);
        cout << "Input teacher id: ";
        is >> teacherId;
        cout << "Input teacher subject: ";
        is >> subject;
        cout << "Input teacher faculty: ";
        is >> faculty;
        cout << "Input teacher department: ";
        is >> department;
        char tempUni[30];
        cout << "Enter teacher university: ";
        is >> tempUni;
        delete[] university[0];
        university[0] = new char[strlen(tempUni) + 1];
        strcpy(university[0], tempUni);
    }
};

ostream &operator<<(ostream &os, Teacher &s)
{
    s.print(os);
    return os;
}
istream &operator>>(istream &is, Teacher &t)
{
    t.input(is);
    return is;
}
