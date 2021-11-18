#include<iostream>
using namespace std;
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
    int info;
}ArcNode;
typedef struct VNode
{
    char data;
    ArcNode *firstarc;
} VNode, AdjList[20];
typedef struct
{
    AdjList vertices;
    int vexnum;
    int arcnum;
} ALGraph;
int i, j;
int LocateVex(ALGraph G,char v)
{
    for (j = 0; j < G.vexnum;j++)
    {
        if(G.vertices[j].data==v)
            return j;
    }
    return -1;
}
void CreatGraph(ALGraph &G)//创建邻接表
{
    int a, b, w;
    char v1, v2;
    cin >> G.vexnum >> G.arcnum;
    for (i = 0; i < G.vexnum;i++)
    {
        cin >> G.vertices[i].data;
        G.vertices[i].firstarc = NULL;
    }
    for (i = 0; i < G.arcnum;i++)
    {
        cin >> v1 >> v2 >> w;
        a = LocateVex(G, v1);
        b = LocateVex(G, v2);
        ArcNode* p1 = (ArcNode *)malloc(sizeof(ArcNode));
        p1->adjvex = b;
        p1->info = w;
        p1->nextarc = G.vertices[a].firstarc;
        G.vertices[a].firstarc = p1;
        ArcNode *p2 = (ArcNode *)malloc(sizeof(ArcNode));
        p2->adjvex = a;
        p2->info = w;
        p2->nextarc = G.vertices[b].firstarc;
        G.vertices[b].firstarc = p2;
    }
}
void PrintMap(ALGraph G)//输出邻接表
{
    for (i = 0; i < G.vexnum;i++)
    {
        cout << G.vertices[i].data<<"  ";
        while (G.vertices[i].firstarc != NULL)
        {
            cout << G.vertices[i].firstarc->adjvex << " " << G.vertices[i].firstarc->info << "  ";
            G.vertices[i].firstarc = G.vertices[i].firstarc->nextarc;
        }
        cout << endl;
    }
}
int main()
{
    ALGraph G;
    CreatGraph(G);
    PrintMap(G);
    system("pause");
}