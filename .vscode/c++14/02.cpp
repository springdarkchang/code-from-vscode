#include <iostream>
#include <cmath>
using namespace std;
class Shape
{
public:
    void SetData() {}
    virtual void Perimeter() = 0;
    virtual void Area() = 0;
};
class Circle : public Shape
{
    int r;
public:
    void SetData(int t) { r = t; }
    void Perimeter() { cout << "The circle's perimeter is:" << 2 * 3.14 * r << endl; }
    void Area() { cout << "The circle's area is:" << 3.14 * r * r << endl; }
};
class Triangle : public Shape
{
    int s1, s2, s3;
public:
    void SetData(int t1, int t2, int t3)
    {
        s1 = t1;
        s2 = t2;
        s3 = t3;
    }
    void Perimeter() { cout << "The triangle's perimeter is:" << s1 + s2 + s3 << endl; }
    void Area()
    {
        int temp = (s1 + s2 + s3) / 2;
        cout << "The triangle's area is:" << sqrt(temp * (temp - s1) * (temp - s2) * (temp - s3)) << endl;
    }
};
class Quadrilateral : public Shape
{
    int side;
public:
    Quadrilateral(int t1) : side(t1) {}
    void Area() {}
    void Perimeter() { cout << "The quadrilateral's perimeter is:" << 4 * side << endl; }
};
class Square : public Quadrilateral
{
    int side;
public:
    Square(int t1) : Quadrilateral(t1), side(t1) {}
    void Area() { cout << "The square's area is:" << side * side << endl; }
};
int main()
{
    Shape *p;
    Circle c;
    Triangle t;
    Square s(10);
    c.SetData(1);
    t.SetData(8, 6, 4);
    p = &c;
    p->Perimeter();
    p->Area();
    p = &t;
    p->Perimeter();
    p->Area();
    p = &s;
    p->Perimeter();
    p->Area();
    return 0;
}
