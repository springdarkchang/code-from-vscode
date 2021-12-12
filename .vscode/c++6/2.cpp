#include <iostream>
#include <string>
using namespace std;
class Score
{
public:
    int score;
    Score(int score) : score(score) {}
    void score_show()
    {
        cout << "The score of the student is :" << score << endl;
    }
};
class Course
{
public:
    int cno;
    string cname;
    Course(int tempcno, string tempcname) : cno(tempcno), cname(tempcname) {}
    Course(Course &tempcs) : cno(tempcs.cno), cname(tempcs.cname) {}
    void course_show()
    {
        cout << "The cno and the cname of the student is:" << cno << "  " << cname << endl;
    }
};
class Student
{
    string name, gender, grade, scourse;
    int sscore, sno;

public:
    Student(int sno, string name, string gender, string grade, Course cs1, Score sc1):sno(sno),name(name),gender(gender),grade(grade),scourse(cs1.cname),sscore(sc1.score){}
    void student_show()
    {
        cout << "The all information of the student is:" << sno << "  " << name << "  " << gender << "  " << grade << "  " << scourse << "  " << sscore << endl;
    }
};
int main()
{
    Course cs1(19218120, "C++");
    Score sc1(90);
    Student st1(201811219, "张三", "男", "计科161", cs1, sc1);
    st1.student_show();
}
