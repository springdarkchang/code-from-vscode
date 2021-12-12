#include<iostream>
using namespace std;
void move(int n, int x, int y, int z)
{
    if (n == 1)
        cout << x << "-->" << z << "    ";
    else
    {
        move(n - 1, x, z, y);
        cout << x << "-->" << z << "    ";
        move(n - 1, y, x, z);
    }
}
int main()
{
    int num;
    char flag = 'y';
    while(flag=='y')
    {
        cout << "Please input the number of the diskes:";
        cin >> num;
        cout << "The steps to moving " << num << " diskes are as follows:" << endl;
        move(num, 1, 2, 3);
        cout << endl
             << "Do you want to go on?(y for yes,no for no)";
        cin >> flag;
    }
}