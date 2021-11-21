#include<iostream>
#include<string>
using namespace std;
class A{
    int i;
protected:
    char c;
public:
    string s;
    A(int tempi,char tempc,string temps):i(tempi),c(tempc),s(temps){}
    void show() { cout << "A::i=" << i << "  A::c=" << c << "  A::s=" << s << endl; }
};
class B:public A{
public:
    B(int tempi, char tempc, string temps) : A(tempi, tempc, temps) {}
};
class C:public A{
public:
    C(int tempi, char tempc, string temps) : A(tempi, tempc, temps) {}
};
class D:public B,public C{
public:
    D(int tempbi,char tempbc,string tempbs,int tempci,char tempcc,string tempcs):
    B(tempbi,tempbc,tempbs),C(tempci,tempcc,tempcs){}
};
int main()
{
    D d(98, 'b', "bs", 99, 'c', "cs");
    d.B::show();
    d.C::show();
}