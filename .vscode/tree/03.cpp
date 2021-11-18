#include<iostream>
#include<cstring>
using namespace std;
typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *Huffmantree;
typedef char **HuffmanCode;
Huffmantree p;
void Select(Huffmantree HT, int j, int &s1, int &s2)
{
    int i, min1 = 9999, min2 = 9999;
    for (i = 1; i <= j;i++)
    {
        if (HT[i].parent == 0 && min1 > HT[i].weight)
        {
            min1 = HT[i].weight;
            s1 = i;
        }
    }
    for (i = 1; i <= j; i++)
    {
        if (i != s1 && HT[i].parent == 0)
            if (HT[i].weight < min2)
            {
                min2 = HT[i].weight;
                s2 = i;
            }
    }
}
void HuffmanCoding(Huffmantree &HT,HuffmanCode &HC,int *w,int n)
{
    int m, i, s1, s2, start, c, f;
    if(n<=1)
        return;
    m = 2 * n - 1;
    HT = (Huffmantree)malloc((m + 1) * sizeof(HTNode));
    for (i = 1; i <= n;++i,++p,++w)
    {
        HT[i] = {*w, 0, 0, 0};
    }
    for (i = n + 1; i <= m; ++i)
    {
        HT[i] = {0, 0, 0, 0};
    }
    for (i = n + 1; i <= m;++i)
    {
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    HC = (HuffmanCode)malloc((n + 1) * sizeof(char *));
    char *cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for (i = 1; i <= n;i++)
    {
        start = n - 1;
        for (c = i, f = HT[i].parent; f != 0;c=f,f=HT[f].parent)
        {
            if(HT[f].lchild==c)
                cd[--start] = '0';
            else
                cd[--start] = '1';
        }
        HC[i] = (char *)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}
int main()
{
    int n, *w;
    Huffmantree HT;
    HuffmanCode HC;
    cin >> n;
    w = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n;i++)
    {
        cin >> w[i];
    }
    HuffmanCoding(HT, HC, w, n);
    for (int i = 1; i <= n;i++)
    {
        cout << HC[i] << endl;
    }
    system("pause");
    return 0;
}