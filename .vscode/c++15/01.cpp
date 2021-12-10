#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int x = 30, y = 300, z = 1024;
    double t = 22.0 / 7;
    cout << "Decimal:" << x << ' ' << y << ' ' << z << endl;
    cout << "Octal:" << oct << x << ' ' << y << ' ' << z << endl;
    cout << "Hexadecimal:" << hex << x << ' ' << y << ' ' << z << endl;
    cout << setiosflags(ios::uppercase);
    cout << "Hexadecimal:" << x << ' ' << y << ' ' << z << endl;
    cout << resetiosflags(ios::uppercase);
    cout << "Hexadecimal:" << x << ' ' << y << ' ' << z << endl;
    cout << "Decimal:" << dec << x << ' ' << y << ' ' << z << endl;
    cout << setw(5) << x << endl;
    cout << setw(2) << y << endl;
    cout << t << endl;
    cout << setprecision(3) << t << endl;
    cout << setprecision(4) << t << endl;
}