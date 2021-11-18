#include <iostream>
#include <limits.h>
using namespace std;
#define MaxInt INT_MAX
#define MaxN 20
typedef struct
{
    char vexs[MaxN];
    int arcs[MaxN][MaxN];
    int vexnum, arcnum;
} MGraph;
int i, j;
bool visited[MaxN];
int Locate(MGraph G, char v)
{
    for (j = 0; j < G.vexnum; j++)
    {
        if (G.vexs[j] == v)
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
    for (i = 0; i < G.vexnum; i++)
        cin >> G.vexs[i];
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
            G.arcs[i][j] = MaxInt;
    }
    for (i = 0; i < G.arcnum; i++)
    {
        cin >> v1 >> v2 >> w;
        a = Locate(G, v1);
        b = Locate(G, v2);
        G.arcs[a][b] = w;
        G.arcs[b][a] = G.arcs[a][b];
    }
}
int FirstAdjVex(MGraph G,int v)//搜索第一个邻接点
{
    for (j = 0; j < G.vexnum;j++)
    {
        if(G.arcs[v][j]!=MaxInt)
            return j;
    }
    return -1;
}
int NextAdjVex(MGraph G,int v)//搜索下一个邻接点
{
    for (j=j+1; j < G.vexnum;j++)
    {
        if(G.arcs[v][j]!=MaxInt)
            return j;
    }
    return -1;
}
void DFS(MGraph G,int v)
{
    int w;
    cout << G.vexs[v] << " ";
    visited[v] = true;
    for (w = FirstAdjVex(G, v); w >= 0;w=NextAdjVex(G,v))
    {
        if(!visited[w])
            DFS(G, w);
    }
}
void DFSTraverse(MGraph G)//深度优先搜索
{
    for (i = 0; i < G.vexnum;i++)
    {
        visited[i] = false;
    }
    for (i = 0; i < G.vexnum;i++)
    {
        if(!visited[i])
            DFS(G, i);
    }
}
int main()
{
    MGraph G;
    CreatUDN(G);
    DFSTraverse(G);
    system("pause");
    return 0;
}
