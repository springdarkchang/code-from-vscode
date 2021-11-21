#include<iostream>
using namespace std;
class Figure{
    int sidenum;
public:
    Figure() { cout << "Figure." << endl; }
    Figure(int temp) : sidenum(temp) { cout << "The figure has " << sidenum << " sides" << endl; }
};
class Quadrangle1:virtual public Figure{
public:
    Quadrangle1() { cout << "Quadrangle1." << endl; }
    Quadrangle1(int temp):Figure(temp)
    {
        cout << "This is a quadrilateral with two diagonal lines perpendicular to each other." << endl;
    }
};
class Parallelogram:virtual public Figure{
public:
    Parallelogram() { cout << "Parallelogram." << endl; }
    Parallelogram(int temp):Figure(temp)
    {
        cout << "This is a parallelogram." << endl;
    }
};
class Quadrangle2:virtual public Figure{
public:
    Quadrangle2() { cout << "Quadrangle2." << endl; }
    Quadrangle2(int temp):Figure(temp)
    {
        cout << "This is a quadrilateral with fout 90 degree interior angles." << endl;
    }
};
class Rectangle : virtual public Quadrangle2, virtual public Parallelogram
{
public:
    int angle;
    Rectangle() { cout << "Rectangle." << endl; }
    Rectangle(int temp, int tempa) : Figure(temp), angle(tempa)
    {
        cout << "This is a rectangle." << endl;
    }
};
class Rhombus:virtual public Quadrangle1,virtual public Parallelogram{
public:
    int sidelength;
    Rhombus() { cout << "Rhombus." << endl; }
    Rhombus(int temp,int templ):Figure(temp),sidelength(templ)
    {
        cout << "This is a rhombus." << endl;
    }
};
class Square : public Rhombus, public Rectangle
{
public:
    Square() { cout << "Square." << endl; }
    Square(int t1, int t2, int t3) : Rhombus(t1, t2), Rectangle(t1, t3), Quadrangle1(t1),
                                     Parallelogram(t1), Quadrangle2(t1), Figure(t1)
    {
        cout << "The figure is a square!" << endl
             << "All angles of the square are " << angle << " degrees." << endl
             << "The sidelength of the square is " << sidelength << "." << endl
             << "The area of the square is "
             << sidelength * sidelength << endl;
    }
};

int main()
{
    Square s(4, 10, 90);
}