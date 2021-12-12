#include <iostream>
#include <stdlib.h>
using namespace std;
void InputMatrix(int d1, int d2, int **matrix)
{
    cout << "Please input the elements of the matrix: ";
    for (int i = 0; i < d1; i++)
        for (int j = 0; j < d2; j++)
            cin >> matrix[i][j];
}
void OutputMatrix(int d1, int d2, int **matrix)
{
    cout << "The original matrix you input is:" << endl;
    for (int i = 0; i < d1; i++)
    {
        for (int j = 0; j < d2; j++)
            cout << matrix[i][j] << "   ";
        cout << endl;
    }
}
void MultiplyMatrix(int d1, int d2, int **matrix)
{
    int i, j, number;
    cout << "Please input the number that will multiply the matrix:";
    cin >> number;
    cout << "The matrix multiplied by the number is:" << endl;
    for (i = 0; i < d1; i++)
    {
        for (j = 0; j < d2; j++)
            cout << matrix[i][j] * number << "   ";
        cout << endl;
    }
}
int main()
{
    int i, d1, d2;
    cout << "Please input two dimensions of the Matrix: ";
    cin >> d1 >> d2;
    int **matrix = (int **)malloc(sizeof(int *) * d1);
    for (i = 0; i < d1; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * d2);
    }
    if (matrix == NULL)
    {
        cout << "动态分配空间失败，请检查程序!" << endl;
        exit(1);
    }
    InputMatrix(d1, d2, matrix);
    cout << "---------------------------------------------------------" << endl;
    OutputMatrix(d1, d2, matrix);
    char flag = 'y';
    while (tolower(flag) == 'y')
    {
        cout << "---------------------------------------------------------" << endl;
        MultiplyMatrix(d1, d2, matrix);
        cout << "Do you want to continue to multiply the matrix?(Y/N)";
        cin >> flag;
    }
    for (i = 0; i < d1; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
