#include <iostream>
#include <ctype.h>
#include <conio.h>
using namespace std;
int main()
{
    int num, i;
    char flag = 'y';
    while (tolower(flag) == 'y')
    {
        cout << "请输入一个数:";
        cin >> num;
        for (i = 2; i < num; i++)
        {
            if (num % i == 0)
                break;
        }
        if (i == num)
            cout << "是素数!" << endl;
        else
            cout << "不是素数!" << endl;
        cout << "是否需要继续判断素数(y-是, n-否)？";
        flag = getche();
        cout << endl;
        while (tolower(flag) != 'y' && tolower(flag) != 'n')
        {
            cout << "输入错误，请重新输入一个字符(y-是, n-否): ";
            flag = getche();
            cout << endl;
        }
    }
}
