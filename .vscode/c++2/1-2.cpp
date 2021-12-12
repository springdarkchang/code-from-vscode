#include <iostream>
using namespace std;
int water(int n)
{
    int a, b, c, s;
    a = n / 100;
    b = n / 10 % 10;
    c = n % 10;
    s = a * a * a + b * b * b + c * c * c;
    if(s==n)
        return 1;
    else
        return 0;
}
int main()
{
    int i;
    for (i = 99; i < 1000;i++)
    {
        if(water(i))
            cout << i << "  ";
    }
    return 0;
}