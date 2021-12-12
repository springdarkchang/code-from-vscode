#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#define NUM 3
using namespace std;
class Singer
{
    string name, gender, song;
    int age;

public:
    Singer()
    {
        cout << "提示信息:调用Singer构造函数!" << endl;
    }
    void Enroll();
    void Show();
    void Modify();
    ~Singer()
    {
        cout << "提示信息:调用Singer析构函数!" << endl;
    }
};
void Singer::Enroll()
{
    cout << "请输入歌手的信息(姓名、性别、年龄、演唱曲目):";
    cin >> name >> gender >> age >> song;
}
void Singer::Show()
{
    cout << name << "   " << gender << "    " << age << "   " << song << endl;
}
void Singer::Modify()
{
    int i;
    cout << "1.姓名 2.性别 3.年龄 4.演唱曲目" << endl
         << "请选择需要修改的选项";
    cin >> i;
    switch (i)
    {
    case 1:
        cout << "请输入新的姓名:";
        cin >> name;
        break;
    case 2:
        cout << "请输入新的性别:";
        cin >> gender;
        break;
    case 3:
        cout << "请输入新的年龄:";
        cin >> age;
        break;
    case 4:
        cout << "请输入新的演唱曲目";
        cin >> song;
    default:
        break;
    }
    cout << "歌手信息修改成功!" << endl
         << "修改后的歌手信息如下所示:" << endl;
    this->Show();
}
int main()
{
    int i, num;
    Singer s[NUM];
    char flag = 'y';
    cout << "****************************************************" << endl
         << "请输入这次报名歌手的数量(<=3):";
    cin >> num;
    for (i = 0; i < num;i++)
    {
        s[i].Enroll();
    }
    cout << "报名歌手的信息如下所示:" << endl;
    for (i = 0; i < num; i++)
    {
        s[i].Show();
    }
    cout << "是否需要修改报名歌手的信息(Y/N):";
    cin >> flag;
    while (tolower(flag) == 'y')
    {
        cout << "请输入需要修改的歌手信息序号:";
        cin >> i;
        s[i-1].Modify();
        cout << "是否继续修改报名歌手的信息?(Y/N)";
        cin >> flag;
    }
}
