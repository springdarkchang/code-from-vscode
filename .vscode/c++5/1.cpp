#include <iostream>
#include <ctype.h>
using namespace std;
class Matrix
{
public:
    int d1, d2, m[100][100];
    void Input();
    void Show();
    void Multiply();
    void Transpose();
    void Rotate();
};
void Matrix::Input()
{
    cout << "Please input two dimensions of the Matrix: ";
    cin >> d1 >> d2;
    cout << "Please input the elements of the matrix: ";
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            cin >> m[i][j];
}
void Matrix::Show()
{
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
            cout << m[i][j] << "   ";
        cout << endl;
    }
}
void Matrix::Multiply()
{
    char flag;
    int n, i, j;
    cout << "Do you want to multiply the matrix with a number(Y/N)?";
    cin >> flag;
    while(flag=='y')
    {
        cout << "Please input the number that will multiply the matrix:";
        cin >> n;
        cout << "The matrix multiplied by the number is:" << endl;
        for (i = 0; i < d1; i++)
        {
            for (j = 0; j < d2; j++)
                cout << m[i][j] * n << "   ";
            cout << endl;
        }
        cout << "Do you want to continue to multiply the matrix(Y/N)?";
        cin >> flag;
    }
}
void Matrix::Transpose()
{
    char flag;
    cout << endl
         << "Do you want to transpose the matrix(Y/N)?";
    cin >> flag;
    if(flag=='y')
    {
        cout << "The transposed matrix is:" << endl;
        for (int j = 0; j < d2; j++)
        {
            for (int i = 0; i < d1; i++)
            {
                cout << m[i][j] << "  ";
            }
            cout << endl;
        }
    }
}
void Matrix::Rotate()
{
    cout << endl
         << "Do you want to rotate the matrix(Y/N)? ";
    char flag;
    int angle, i, j;
    cin >> flag;
    while (tolower(flag) == 'y')
    {
        cout << "Please input the angle you want to rotate(90, 180 or 270): ";
        cin >> angle;
        switch (angle)
        {
        case 90:
            cout << "The matrix after rotating 90 is:" << endl;
            for (j = 0; j < d2; j++)
            {
                for (i = (d1 - 1); i >= 0; i--)
                {
                    cout << m[i][j] << "  ";
                }
                cout << endl;
            }
            break;
        case 180:
            cout << "The matrix after rotating 180 is:" << endl;
            for (i = (d1 - 1); i >= 0; i--)
            {
                for (j = (d2 - 1); j >= 0; j--)
                {
                    cout << m[i][j] << "  ";
                }
                cout << endl;
            }
            break;
        case 270:
            cout << "The matrix after rotating 270 is:" << endl;
            for (j = (d2 - 1); j >= 0; j--)
            {
                for (i = 0; i < d1; i++)
                {
                    cout << m[i][j] << "  ";
                }
                cout << endl;
            }
            break;
        default:
            cout << "You input a wrong angle!" << endl;
            break;
        }
        cout << "Do you want to continue to rotate the matrix?(Y/N)";
        cin >> flag;
    }
}
int main()
{
    Matrix m;
    m.Input();
    cout << "The original matrix you inputted is:" << endl;
    m.Show();
    m.Multiply();
    m.Transpose();
    m.Rotate();
}