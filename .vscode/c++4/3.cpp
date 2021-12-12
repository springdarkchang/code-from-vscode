#include <iostream>
#include <ctype.h>
#include <stdlib.h>
using namespace std;
void InputMatrix(int d1, int d2, int **matrix)
{
    cout << "Please input the elements of the matrix: ";
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
            cin >> matrix[i][j];
    }
    cout << "---------------------------------------------------------" << endl;
}
void OutputMatrix(int d1, int d2, int **matrix)
{
    cout << "The original matrix you input is:" << endl;
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}
void RotateMatrix(int d1, int d2, int **matrix)
{
    int i, j, angle;
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
int main()
{
    int i, d1, d2;
    cout << "Please input two dimensions of the matrix: ";
    cin >> d1 >> d2;
    int **matrix = new int *[d1];
    for (i = 0; i < d1; i++)
        matrix[i] = new int[d2];
    if (matrix == NULL)
    {
        cout << "动态分配空间失败，请检查程序!" << endl;
        exit(1);
    }
    InputMatrix(d1, d2, matrix);
    OutputMatrix(d1, d2, matrix);
    RotateMatrix(d1, d2, matrix);
    for (i = 0; i < d1; i++)
        delete[] matrix[i];
    delete[] matrix;
}