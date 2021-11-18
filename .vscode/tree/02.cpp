#include <iostream>
#include<queue>
using namespace std;
typedef struct BiNode
{
    char data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;
BiTree q;
void CreateBiTree(BiTree &T) //创建二叉树
{
    char a;
    cin >> a;
    if (a == '*')
    {
        T = NULL;
    }
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode));
        T->data = a;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void PrintBiTree(BiTree T)//二叉树层次遍历
{
    queue<BiTree> S;
    S.push(T);
    while(!S.empty())
    {
        q = S.front();
        S.pop();
        cout << q->data;
        if (q->lchild != NULL)
        {
            S.push(q->lchild);
        }
        if(q->rchild!=NULL)
        {
            S.push(q->rchild);
        }
    }
}
int main()
{
    BiTree T;
    CreateBiTree(T);
    PrintBiTree(T);
    return 0;
}