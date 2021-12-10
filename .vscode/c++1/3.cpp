#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char *t[5];
    char *p;
    int i, j, min;
    cout << "请输入五个字符串:" << endl;
    for (i = 0; i < 5; i++)
    {
        t[i] = new char[20];
        cin >> t[i];
    }
    for (i = 0; i < 4; i++)
    {
        min = i;
        for (j = i + 1; j < 5; j++)
            if (strcmp(t[min], t[j]) > 0)
                min = j;
        p = t[i];
        t[i] = t[min];
        t[min] = p;
    }
    cout << "排好序后的字符串如下所示:" << endl;
    for (i = 0; i < 5; i++)
        cout << t[i] << endl;
    for (i = 0; i < 5; i++)
        delete t[i];
    return 0;
}
