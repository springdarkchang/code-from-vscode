#include<iostream>
using namespace std;
class Matrix
{
    int mat[50][50];
public:
    static int m, n;
    Matrix(int x, int y);
    friend Matrix operator+(Matrix &, Matrix &);
    friend Matrix operator-(Matrix &, Matrix &);
    friend Matrix operator*(Matrix &, Matrix &);
    friend Matrix operator/(Matrix &, Matrix &);
    void input();
    void display();
};
int Matrix::m = 2;
int Matrix::n = 2;
Matrix::Matrix(int x,int y)
{
    m = x;
    n = y;
    for (int i = 0; i < x;i++)
        for (int j = 0; j < y;j++)
            mat[i][j] = 0;
}
void Matrix::input()
{
    int i, j;
    for (i = 0; i < m;i++)
    {
        for (j = 0; j < n;j++)
        {
            cin >> mat[i][j];
        }
    }
}
void Matrix::display()
{
    int i, j;
    for (i = 0; i < m;i++)
    {
        for (j = 0; j < n;j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
Matrix operator+(Matrix &a,Matrix &b)
{
    int i, j;
    Matrix c(a.m, a.n);
    for (i = 0; i < a.m;i++)
    {
        for (j = 0; j < a.n;j++)
        {
            c.mat[i][j] = a.mat[i][j] + b.mat[i][j];
        }
    }
    return c;
}
Matrix operator-(Matrix &a,Matrix &b)
{
    int i, j;
    Matrix c(a.m, a.n);
    for (i = 0; i < a.m; i++)
    {
        for (j = 0; j < a.n; j++)
        {
            c.mat[i][j] = a.mat[i][j] - b.mat[i][j];
        }
    }
    return c;
}
Matrix operator*(Matrix &a,Matrix &b)
{
    int i, j;
    Matrix c(a.m, a.n);
    for (i = 0; i < a.m; i++)
    {
        for (j = 0; j < a.n; j++)
        {
            c.mat[i][j] = a.mat[i][j] * b.mat[i][j];
        }
    }
    return c;
}
Matrix operator/(Matrix &a,Matrix &b)
{
    int i, j;
    Matrix c(a.m, a.n);
    for (i = 0; i < a.m; i++)
    {
        for (j = 0; j < a.n; j++)
        {
            c.mat[i][j] = a.mat[i][j] / b.mat[i][j];
        }
    }
    return c;
}
int main()
{
    cout << "Please input two dimensions of the matrix:  ";
    cin >> Matrix::m >> Matrix::n;
    Matrix a(Matrix::m, Matrix::n), b(Matrix::m, Matrix::n), c(Matrix::m, Matrix::n);
    cout << "input the value of matrix:" << endl;
    a.input();
    cout << "input the value of matrix:" << endl;
    b.input();
    
    cout << endl
         << "Matrix a:" << endl;
    a.display();
    cout << endl
         << "Matrix b:" << endl;
    b.display();
    c = a + b;
    cout << endl
         << "Matrix c = Matrix a + Matrix b :" << endl;
    c.display();
    c = a - b;
    cout << endl
         << "Matrix c = Matrix a - Matrix b :" << endl;
    c.display();
    c = a * b;
    cout << endl
         << "Matrix c = Matrix a * Matrix b :" << endl;
    c.display();
    c = a / b;
    cout << endl
         << "Matrix c = Matrix a / Matrix b :" << endl;
    c.display();
    return 0;
}