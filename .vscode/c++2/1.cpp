#include<iostream>
using namespace std;
int water(int n)
{
    int a, b, c, s;
    a = n / 100;
    b = n / 10 % 10;
    c = n % 10;
    s = a * a * a + b * b * b + c * c * c;
    if (s == n)
        return 1;
    else
        return 0;
}
int main()
{
    int num;
    cout << "Please input a number:";
    cin >> num;
    if(water(num))
        cout << num << "是水仙花数" << endl;
    else
        cout << num << "不是水仙花数" << endl;
}