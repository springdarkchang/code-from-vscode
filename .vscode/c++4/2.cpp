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
void TransposeMatrix(int d1, int d2, int **matrix)
{
    cout << "The transposed matrix is:" << endl;
    for (int j = 0; j < d2; j++)
    {
        for (int i = 0; i < d1; i++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "---------------------------------------------------------" << endl;
}
int main()
{
    int i, d1, d2, **matrix;
    char flag = 'y';
    while (tolower(flag) == 'y')
    {
        cout << "Please input two dimensions of the matrix: ";
        cin >> d1 >> d2;
        matrix = new int *[d1];
        for (i = 0; i < d1; i++)
            matrix[i] = new int[d2];
        if (matrix == NULL)
        {
            cout << "动态分配空间失败，请检查程序!" << endl;
            exit(1);
        }
        InputMatrix(d1, d2, matrix);
        OutputMatrix(d1, d2, matrix);
        TransposeMatrix(d1, d2, matrix);
        cout << "Do you want to continue to transpose the matrix?(Y/N)";
        cin >> flag;
    }
    for (i = 0; i < d1; i++)
        delete[] matrix[i];
    delete[] matrix;
}