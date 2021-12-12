#include <iostream>
using namespace std;
class Box
{
    int length, width, height;
public:
    Box(int l,int w,int h):length(l),width(w),height(h){}
    Box(Box &a):length(a.length*2),width(a.width*2),height(a.height*2){}
    Box(Box &a, Box &b):length(a.length+b.length),width(a.width+b.width),height(a.height+b.height){}
    void compute_perimeter();
    void compute_area();
    void compute_volume();

};
void Box::compute_perimeter()
{
    cout << "The perimeter of the box is:" << 4 * (length + width + height) << endl;
}
void Box::compute_area()
{
    cout << "The superficialarea of the box is:" << 2 * (length * width + length * height + width * height) << endl;
}
void Box::compute_volume()
{
    cout << "The volume of the box is:" << length * width * height << endl;
}
int main()
{
    int l, w, h;
    char flag = 'y';
    while (flag == 'y')
    {
        cout << "Please input the length,width and height of the box:";
        cin >> l >> w >> h;
        Box box1(l, w, h);
        box1.compute_perimeter();
        box1.compute_area();
        box1.compute_volume();
        Box box2(box1);
        cout << "The perimeter,superficialarea and volume of a box with double length,width and height is as follows:" << endl;
        box2.compute_perimeter();
        box2.compute_area();
        box2.compute_volume();
        Box box3(box1, box2);
        cout << "The perimeter,superficialarea and volume of a box withmerging the length,width and height of box1 and box2 is as follows:" << endl;
        box3.compute_perimeter();
        box3.compute_area();
        box3.compute_volume();
        cout << "Do you want to continue to compute the perimeter,superficialarea and volume of a box(y or n)?";
        cin >> flag;
    }
}
