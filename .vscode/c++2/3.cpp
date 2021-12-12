#include<iostream>
using namespace std;
#include <iostream>
using namespace std;
int c[20], cnt = 0, N = 8;
bool isPlaceOK(int n, int i)
{
    for (int j = 1; j <= n - 1; ++j)
    {
        if (c[j] == i || c[j] - j == i - n || c[j] + j == i + n)
            return false;
    }
    return true;
}

void print()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << (c[i] == j ? "#" : ".") << " ";
        }
        cout << endl;
    }
    cout << endl;
    //system("pause");
}

void search(int n)
{
    if (n > N)
    {
        print();
        cnt++;
        return;
    }
    for (int i = 1; i <= N; ++i)
    {
        if (isPlaceOK(n, i))
        {
            c[n] = i;
            search(n + 1);
        }
    }
}

int main()
{
    search(1);
    cout << "八皇后问题共有:" << cnt << "种解法!" << endl;
    return 0;
}