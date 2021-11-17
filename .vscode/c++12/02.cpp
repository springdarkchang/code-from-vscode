#include <iostream>
#include <string.h>
using namespace std;
template <class T>
T Max(T value[], int size)
{
    T max = value[0], temp;
    for (int i = 0; i < size; i++)
        if (value[i] > max)
        {
            temp = max;
            max = value[i];
            value[i] = temp;
        }
    return max;
}
int main()
{
    int i, arr[5];
    double dou[5];
    cout << "输入5个整数" << endl;
    for (i = 0; i < 5; i++)
        cin >> arr[i];
    cout << "最大值为" << Max(arr, 5) << endl
         << "输入5个双精度型数据" << endl;
    for (i = 0; i < 5; i++)
        cin >> dou[i];
    cout << "最大值为" << Max(dou, 5) << endl;
}
