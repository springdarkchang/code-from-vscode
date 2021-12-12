#include <iostream>
#include <string>
using namespace std;
class GrandFather
{
private:
    int CardID;
    void showCardID() { cout << "GrandFather::CardID=" << CardID << endl; }

protected:
    int Age;
    void showAge() { cout << "GrandFather::Age=" << Age << endl; }

public:
    string Name;
    void showName() { cout << "GrandFather::Name=" << Name << endl; }
    GrandFather(string name, int age, int cardid) : Name(name), Age(age), CardID(cardid) {}
};
class Father : public GrandFather
{
private:
    int CardID;
    void showCardID() { cout << "Father::CardID=" << CardID << endl; }

protected:
    int Age;
    void showAge() { cout << "Father::Age=" << Age << endl; }

public:
    string Name;
    void showName() { cout << "Father::Name=" << Name << endl; }
    Father(string gname, int gage, int gcardid, string fname, int fage, int fcardid) : GrandFather(gname, gage, gcardid), Name(fname), Age(fage), CardID(fcardid) {}
};
class Child : public Father
{
private:
    int CardID;
    void showCardID() { cout << "Child::CardID=" << CardID << endl; }

protected:
    int Age;
    void showAge() { cout << "Child::Age=" << Age << endl; }

public:
    string Name;
    Child(string gname, int gage, int gcardid, string fname, int fage, int fcardid, string cname, int cage, int ccardid)
        : Father(gname, gage, gcardid, fname, fage, fcardid), Name(cname), Age(cage), CardID(ccardid) {}
};
int main()
{
    GrandFather g("GrandFather", 70, 123);
    g.showName();

    Father f("GrandFather", 70, 123, "Father", 40, 456);
    f.showName();

    Child c("GrandFather", 70, 123, "Father", 40, 456, "Child", 10, 789);
    f.GrandFather::showName();
    c.GrandFather::showName();
    c.Father::showName();

    c.showName();
}
