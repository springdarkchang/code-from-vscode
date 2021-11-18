#include<iostream>
#include<limits.h>
using namespace std;
#define MaxInt INT_MAX
#define MaxN 20
typedef struct
{
    char vexs[MaxN];
    int arcs[MaxN][MaxN];
    int vexnum, arcnum;
}MGraph;
int i, j;
int Locate(MGraph G,char v)
{
    for (j = 0; j < G.vexnum;j++)
    {
        if(G.vexs[j]==v)
        {
            return j;
        }
    }
    return -1;
}
void CreatUDN(MGraph &G)//创建邻接矩阵
{
    int a, b, w;
    char v1, v2;
    cin >> G.vexnum >> G.arcnum;
    for (i = 0; i < G.vexnum;i++)
        cin >> G.vexs[i];
    for (i = 0; i < G.vexnum;i++)
    {
        for (j = 0; j < G.vexnum;j++)
            G.arcs[i][j] = MaxInt;
    }
    for (i = 0; i < G.arcnum;i++)
    {
        cin >> v1 >> v2 >> w;
        a = Locate(G, v1);
        b = Locate(G, v2);
        G.arcs[a][b] = w;
        G.arcs[b][a] = G.arcs[a][b];
    }
}
void PrintMap(MGraph G)//输出邻接矩阵
{
    for (i = 0; i < G.vexnum;i++)
    {
        for (j = 0; j < G.vexnum;j++)
            cout << G.arcs[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    MGraph G;
    CreatUDN(G);
    PrintMap(G);
}