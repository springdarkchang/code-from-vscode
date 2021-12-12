#include <iostream>
using namespace std;
int main()
{
    int i, dimn, num, matrix[100];
    cout << "Please input the dimension of the matrix: ";
    cin >> dimn;
    cout << "Please input the elements of the matrix: ";
    for (i = 0; i < dimn * dimn; i++)
    {
        cin >> matrix[i];
    }
    cout << "The original matrix you input is:";
    for (i = 0; i < dimn * dimn; i++)
    {
        if (i % dimn == 0)
        {
            cout << endl
                 << matrix[i] << "  ";
        }
        else
        {
            cout << matrix[i] << "  ";
        }
    }
    cout << endl
         << "Please input the number that will multiply the matrix:";
    cin >> num;
    cout << "The matrix multiplied by the number is:";
    for (i = 0; i < dimn * dimn; i++)
    {
        if (i % dimn == 0)
        {
            cout << endl
                 << num * matrix[i] << "  ";
        }
        else
        {
            cout << num * matrix[i] << "  ";
        }
    }
    cout << endl;
}
