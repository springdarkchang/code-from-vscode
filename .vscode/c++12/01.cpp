#include<iostream>
using namespace std;
template <class T>
class tem
{
    T *data;
    int size;
public:
    tem(int);
    ~tem()
    {
        delete[] data;
    }
    T& operator[](int i)
    {
        return data[i];
    }
};
template<class T>
tem<T>::tem(int n)
{
    data = new T[n];
    size = n;
}
int main()
{
    tem<int> s(5);
    int i;
    for (i = 0; i < 5;i++)
    {
        s[i] = i;
    }
    for (i = 0; i < 5;i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}