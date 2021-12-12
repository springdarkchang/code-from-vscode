#include <iostream>
#include <string>
using namespace std;
class Automobile;
class Park
{
    int N, income, numAuto;
    Automobile **spaces;

public:
    Park(int N)
    {
        spaces = new Automobile *[N];
        for (int i = 0; i < N; i++)
            spaces[i] = NULL;
        this->N = N;
        income = 0;
        numAuto = 0;
    }
    ~Park() { delete[] spaces; }
    void showInfo();
    bool assignSpace(Automobile *pa);
    bool reclaimSpace(Automobile *pa, int fee);
};
class Automobile
{
protected:
    string plateNO;

public:
    Automobile(string plateNO) : plateNO(plateNO){};
    void enter(Park &park) { park.assignSpace(this); };
    void leave(Park &park){};
    string getPlateNO() { return plateNO; };
};
class Truck : public Automobile
{
protected:
    double capacity;

public:
    Truck(string plateNO, double capacity) : Automobile(plateNO), capacity(capacity) {}
    void leave(Park &park) { park.reclaimSpace(this, 3); };
};
class Bus : public Automobile
{
protected:
    int numPassengers;

public:
    Bus(string plateNO, int numPassengers) : Automobile(plateNO), numPassengers(numPassengers) {}
    void leave(Park &park) { park.reclaimSpace(this, 2); };
};
class Car : public Automobile
{
protected:
    string brand;

public:
    Car(string plateNO, string brand) : Automobile(plateNO), brand(brand) {}
    void leave(Park &park) { park.reclaimSpace(this, 1); };
};
void Park::showInfo()
{
    if (numAuto == 0)
        cout << "停车场目前停放了" << numAuto << "辆汽车，共收入" << income << "元停车费!";
    else
    {
        cout << "停车场目前停放了" << numAuto << "辆汽车:";
        for (int i = 0; i < N; i++)
            if (spaces[i] != NULL)
                cout << spaces[i]->getPlateNO() << ",";
        cout << "共收入" << income << "元停车费!" << endl;
    }
}
bool Park::assignSpace(Automobile *pa)
{
    for (int i = 0; i < N; i++)
    {
        if (spaces[i] == NULL)
        {
            spaces[i] = pa;
            numAuto++;
            cout << pa->getPlateNO() << "进入停车场，分配停车位!" << endl;
            return true;
        }
    }
    cout << "无法为" << pa->getPlateNO() << "分配停车位!" << endl;
    return false;
}
bool Park::reclaimSpace(Automobile *pa, int fee)
{
    for (int i = 0; i < N; i++)
    {
        if (spaces[i] == pa)
        {
            spaces[i] = NULL;
            numAuto--;
            income += fee;
            cout << pa->getPlateNO() << "离开停车场，缴纳停车费" << fee << "元!" << endl;
            return true;
        }
    }
    cout << "停车场中没有车牌为" << pa->getPlateNO() << "的汽车!";
    return false;
}
int main()
{
    int N = 0;
    cout << "请输入停车位数量:";
    cin >> N;
    Park park(N);
    Truck truck("苏A-01234", 20);
    truck.enter(park);
    Car car1("苏A-56789", "Audi A8");
    car1.enter(park);
    car1.leave(park);
    Bus bus("苏A-43210", 50);
    bus.enter(park);
    park.showInfo();
    Car car2("苏A-98765", "Benz S400");
    car2.enter(park);
    bus.leave(park);
    truck.leave(park);
    park.showInfo();
}
