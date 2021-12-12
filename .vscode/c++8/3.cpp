#include <iostream>
#include <string>
using namespace std;
const int SNUM = 2;
const int TNUM = 2;
const int ANUM = 2;
int i;
class Person
{
protected:
    string name, gender;
    int age;

public:
    Person() {}
    Person(string tname, string tgender, int tage) : name(tname), gender(tgender), age(tage) {}
};
class Student : public Person
{
protected:
    int sno;
    string major;

public:
    Student() {}
    Student(int tsno, string tname, string tgender, int tage, string tmajor)
        : Person(tname, tgender, tage), sno(tsno), major(tmajor) { Enroll(); }
    void Enroll() { cout << "一个学生注册完成!" << endl; }
    void ShowStudent() { cout << sno << "  " << name << "  " << gender << "  " << age << "  " << major << endl; }
    void LikeOrNot() {}
};
class Teacher : public Person
{
protected:
    int tno;
    string college;

public:
    Teacher() {}
    Teacher(int ttno, string tname, string tgender, int tage, string tcollege)
        : Person(tname, tgender, tage), tno(ttno), college(tcollege) { Recruit(); }
    void Recruit() { cout << "一个教师招聘完成!" << endl; }
    void ShowTeacher() { cout << tno << "  " << name << "  " << gender << "  " << age << "  " << college << endl; }
    void Course() {}
};
class Administrator : public Person
{
protected:
    int ano;
    string section;

public:
    Administrator() {}
    Administrator(int tano, string tname, string tgender, int tage, string tsection)
        : Person(tname, tgender, tage), ano(tano), section(tsection) { Employ(); }
    void Employ() { cout << "一个管理人员招聘完成!" << endl; }
    void ShowAdministrator() { cout << ano << "  " << name << "  " << gender << "  " << age << "  " << section << endl; }
    void ManageStudent() {}
    void ArrangeCourse() {}
};
class University
{
    string uname, uaddress;
    Student s[SNUM];
    Teacher t[TNUM];
    Administrator a[ANUM];

public:
    University() {}
    University(string tname, string taddress, Student *sp, Teacher *tp, Administrator *ap)
        : uname(tname), uaddress(taddress)
    {
        for (i = 0; i < SNUM; i++)
        {
            s[i] = sp[i];
        }
        for (i = 0; i < TNUM; i++)
        {
            t[i] = tp[i];
        }
        for (i = 0; i < ANUM; i++)
        {
            a[i] = ap[i];
        }
    }
    void TermBegin() {}
    void ShowUniversity()
    {
        cout << "该大学的基本信息显示如下:" << endl
             << uname << "  " << uaddress << endl;
        cout << "该大学的学生信息显示如下:" << endl;
        for (int i = 0; i < SNUM; i++)
        {
            s[i].ShowStudent();
        }
        cout << "该大学的教师信息显示如下:" << endl;
        for (i = 0; i < TNUM; i++)
        {
            t[i].ShowTeacher();
        }
        cout << "该大学的管理人员信息显示如下:" << endl;
        for (i = 0; i < ANUM; i++)
        {
            a[i].ShowAdministrator();
        }
    }
};
int main()
{
    cout << "请输入大学的名称和地址: ";
    string tuname, tuaddress;
    cin >> tuname >> tuaddress;
    int i, tempno, tempage;
    string tempname, tempgender, tempstr;
    Student ts[SNUM];
    cout << "请按照如下格式输入" << SNUM << "个学生的信息:" << endl
         << "(学号 姓名 性别 年龄 专业)" << endl;
    for (i = 0; i < SNUM; i++)
    {
        cin >> tempno >> tempname >> tempgender >> tempage >> tempstr;
        ts[i] = Student(tempno, tempname, tempgender, tempage, tempstr);
    }
    cout << "请按照如下格式输入" << TNUM << "个教师的信息:" << endl
         << "(工号 姓名 性别 年龄 学院)" << endl;
    Teacher tt[TNUM];
    for (i = 0; i < TNUM; i++)
    {
        cin >> tempno >> tempname >> tempgender >> tempage >> tempstr;
        tt[i] = Teacher(tempno, tempname, tempgender, tempage, tempstr);
    }
    cout << "请按照如下格式输入" << ANUM << "个管理人员的信息:" << endl
         << "(工号 姓名 性别 年龄 部门)" << endl;
    Administrator ta[ANUM];
    for (i = 0; i < ANUM; i++)
    {
        cin >> tempno >> tempname >> tempgender >> tempage >> tempstr;
        ta[i] = Administrator(tempno, tempname, tempgender, tempage, tempstr);
    }
    University u(tuname, tuaddress, ts, tt, ta);
    u.ShowUniversity();
}
