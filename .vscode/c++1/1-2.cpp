#include <iostream>
#include <ctype.h>
#include <conio.h>
using namespace std;
#define max 100
int primenum(int i)
{
    int j, flag = 1;
    for (j = 2; j < i - 1; j++)
    {
        if (i % j == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int main()
{
    int i, counter = 0, prime[max + 1];
    for (i = 2; i < max; i++)
        prime[i] = 1;
    for (i = 3; i <= max; i++)
        prime[i] = primenum(i);
    cout << max;
    cout << "以内的素数如下" << endl;
    for (i = 2; i < max; i++)
    {
        if (prime[i] == 1)
        {
            cout << i << " ";
            counter++;
            if (counter % 10 == 0)
                cout << endl;
        }
    }
    cout << endl;
}
