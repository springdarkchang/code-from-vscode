#include <iostream>
using namespace std;
double factorial(int x)
{
    if (x <= 0)
        return 1;
    else
        return x * factorial(x - 1);
}
int main()
{
    int i, n;
    double primenumber[21];
    static double sum = 0;
    cout << "Please input a number: ";
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        primenumber[i] = factorial(i);
        cout << primenumber[i] << "    ";
        sum += primenumber[i];
        cout << sum << endl;
    }
    cout << "The sum is:";
    cout << sum << endl;
    return 0;
}
