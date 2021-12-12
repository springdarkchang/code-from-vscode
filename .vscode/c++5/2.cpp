#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
const int MaxSize = 10;
class Array
{
    int length, data[MaxSize];

public:
    Array() { length = 0; }
    Array(int a[], int n);
    void Display();
    void Sort();
    void Insert(int x);
    void Delete(int x);
    int Search(int x);
};
Array::Array(int a[], int n)
{
    int i;
    length = n;
    for (i = 0; i < n; i++)
    {
        data[i] = a[i];
    }
}
void Array::Display()
{
    int i;
    cout << "显示数组元素:";
    for (i = 0; i < length; i++)
        cout << " " << data[i];
    cout << endl;
}
void Array::Sort()
{
    cout << "请输入排序方式（1-升序排序；2-降序排序）:";
    int i, j, k, m;
    cin >> k;
    if (k == 1)
    {
        for (i = 0; i < length-1; i++)
        {
            for (j = 0; j < length-1-i; j++)
            {
                if (data[j] > data[j + 1])
                {
                    m = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = m;
                }
            }
        }
    }
    else
    {
        for (i = 0; i < length-1; i++)
        {
            for (j = 0; j < length-1-i; j++)
            {
                if (data[j] < data[j + 1])
                {
                    m = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = m;
                }
            }
        }
    }
}
void Array::Insert(int x)
{
    length++;
    data[length - 1] = x;
}
void Array::Delete(int x)
{
    int i, j;
    for (i = 0; i < length;i++)
    {
        if(data[i]==x)
        {
            length--;
            for (j = i; j < length;j++)
            {
                data[j] = data[j + 1];
            }
            break;
        }
    }
}
int Array::Search(int x)
{
    int i;
    for (i = 0; i < length;i++)
    {
        if(x==data[i])
            return i + 1;
    }
    return -1;
}
int main()
{
    int i, n, olda[10], choose, x, y, z, location;
    cout << "请输入数组的长度（<10）:";
    cin >> n;
    cout << "请依次输入数组的元素:";
    for (i = 0; i < n; i++)
    {
        cin >> olda[i];
    }
    Array newa(olda, n);
    while (1)
    {
        cout << "****************************************************" << endl;
        cout << "** 1.显示  2.排序  3.插入  4.删除  5.查找  6.退出 **" << endl;
        cout << "****************************************************" << endl
             << "请选择操作项:";
        cin >> choose;
        switch (choose)
        {
        case 1:
            newa.Display();
            break;
        case 2:
            newa.Sort();
            break;
        case 3:
            cout << "请输入需要插入的数字:";
            cin >> x;
            newa.Insert(x);
            break;
        case 4:
            cout << "请输入要删除的数字:";
            cin >> y;
            newa.Delete(y);
            break;
        case 5:
            cout << "请输入要查找的数字:";
            cin >> z;
            cout << "此数字的位置是:" << newa.Search(z) << endl;
            break;
        default:
            return 0;
        }
    }
}