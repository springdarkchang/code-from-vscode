#include<iostream>
using namespace std;
class Rational{
    int m, n;
public:
    Rational(int nn = 1, int mm = 1);
    friend Rational operator+(Rational &a, Rational &b); //加法
    friend Rational operator-(Rational &a, Rational &b); //减法
    friend Rational operator*(Rational &a, Rational &b); //乘法
    friend Rational operator/(Rational &a, Rational &b); //除法
    Rational operator-();     //取反
    Rational &operator++();   //r=++r1
    Rational operator++(int); //r=r1++
    Rational &operator--();   //r=--r1
    Rational operator--(int); //r =r1--
    void simple();
    void print();
};
Rational::Rational(int nn,int mm)
{
    m = mm;
    n = nn;
    simple();
}
void Rational::print()
{
    cout << "The value is " << n << "/" << m << endl;
}
void Rational::simple()
{
    if(m<0)
    {
        m = -m;
        n = -n;
    }
    int fz = abs(n), fm = abs(m);
    while(fm>0)
    {
        int t = fz % fm;
        fz = fm;
        fm = t;
    }
    m /= fz;
    n /= fz;
}
Rational operator+(Rational &a,Rational &b)
{
    int mm, nn;
    mm = a.m * b.m;
    nn = a.n * b.m + b.n * a.m;
    return Rational(nn,mm);
}
Rational operator-(Rational &a,Rational &b)
{
    int mm, nn;
    mm = a.m * b.m;
    nn = a.n * b.m - b.n * a.m;
    return Rational(nn,mm);
}
Rational operator*(Rational &a,Rational &b)
{
    int mm, nn;
    mm = a.m * b.m;
    nn = a.n * b.n;
    return Rational(nn,mm);
}
Rational operator/(Rational &a,Rational &b)
{
    int mm, nn;
    mm = a.m * b.n;
    nn = a.n * b.m;
    return Rational(nn,mm);
}
Rational Rational::operator-()
{
    int mm, nn;
    nn = -n;
    mm = m;
    return Rational(nn,mm);
}
Rational &Rational::operator++()
{
    n = m + n;
    return *this;
}
Rational &Rational::operator--()
{
    n = n - m;
    return *this;
}
Rational Rational::operator++(int )
{
    Rational c;
    c.n = n;
    c.m = m;
    n = m + n;
    return c;
}
Rational Rational::operator--(int )
{
    Rational c;
    c.n = n;
    c.m = m;
    n = n - m;
    return c;
}
int main()
{
    Rational A(1, 2), B(3, -4), C;
    C = A + B;
    C.print();
    C = A - B;
    C.print();
    C = A * B;
    C.print();
    C = A / B;
    C.print();
    C = -A;
    C.print();
    C = ++A;
    A.print();
    C.print();
    C = A++;
    A.print();
    C.print();
    C = --B;
    B.print();
    C.print();
    C = B--;
    B.print();
    C.print();
    system("pause");
    return 0;
}
