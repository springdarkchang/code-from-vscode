#include <iostream>
#include <string>
using namespace std;
class Course
{
public:
    int cno;
    string cname;
    Course(int tempcno, string tempcname) : cno(tempcno), cname(tempcname) {}
    Course(Course &tempcs) : cno(tempcs.cno), cname(tempcs.cname) {}
    void course_show();
};
void Course::course_show()
{
    cout << "The all information of the course is:  " << cno << "  " << cname << endl;
}
class Score
{
public:
    int score;
    Score(int tempscore) : score(tempscore) {}
    Score(Score &tempss) : score(tempss.score) {}
    void score_show();
};
void Score::score_show()
{
    cout << "The all information of the score is:  " << score << endl;
}
class Student
{
public:
    int sno;
    string sname, gender, grade;
    Course sc;
    Score ss;
    Student(int tempsno, string tempsname, string tempgender, string tempgrade, Course tempsc, Score tempss) : sno(tempsno), sname(tempsname), gender(tempgender), grade(tempgrade), sc(tempsc), ss(tempss) {}
    void student_show();
};
void Student::student_show()
{
    cout << "The all information of the student is:  " << sno << "  " << sname << "  " << gender << "  " << grade << "  " << sc.cname << "  " << ss.score << endl;
}
int main()
{
    Course cs1(19218120, "C++");
    Score sc1(90);
    Student st1(201811219, "张三", "男", "计科161", cs1, sc1);
    st1.student_show();
}
