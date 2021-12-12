#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
    int i, j, d1, d2, matrix[100][100], angle;
    cout << "Please input two dimensions of the matrix: ";
    cin >> d1 >> d2;
    cout << "Please input the elements of the matrix: ";
    for (i = 0; i < d1; i++)
    {
        for (j = 0; j < d2; j++)
            cin >> matrix[i][j];
    }
    cout << "The original matrix you inputted is:" << endl;
    for (i = 0; i < d1; i++)
    {
        for (j = 0; j < d2; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    char flag = 'y';
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
                    cout << matrix[i][j] << "  ";
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
                    cout << matrix[i][j] << "  ";
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
                    cout << matrix[i][j] << "  ";
                }
                cout << endl;
            }
            break;
        default:
            cout << "You input a wrong angle!" << endl;
            break;
        }
        cout << "--------------------------------------------------------------" << endl;
        cout << "Do you want to continue to rotate the matrix?(Y/N)";
        cin >> flag;
    }
}