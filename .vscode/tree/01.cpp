#include<iostream>
using namespace std;
typedef struct BiNode
{
    char data;
    struct BiNode *lchild, *rchild;
} BiTNode, *BiTree;
BiTree p;
int e;
void CreateBiTree(BiTree &T)//创建二叉树
{
    char a;
    cin >> a;
    if (a == '*')
    {
        T = NULL;
    }
    else
    {
        T = (BiTNode*)malloc(sizeof(BiTNode));
        T->data = a;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void PrintBiTree1(BiTree T)//先序遍历二叉树
{
    if(T!=NULL)
    {
        cout << T->data;
        PrintBiTree1(T->lchild);
        PrintBiTree1(T->rchild);
    }
}
void PrintBiTree2(BiTree T) //中序遍历二叉树
{
    if (T != NULL)
    {
        PrintBiTree2(T->lchild);
        cout << T->data;
        PrintBiTree2(T->rchild);
    }
}
void PrintBiTree3(BiTree T) //后序遍历二叉树
{
    if (T != NULL)
    {
        PrintBiTree3(T->lchild);
        PrintBiTree3(T->rchild);
        cout << T->data;
    }
}
int TreeDepth(BiTree T)//求二叉树深度
{
    if(T!=NULL)
    {
        int l = TreeDepth(T->lchild);
        int r = TreeDepth(T->rchild);
        int m = l >= r ? l + 1 : r + 1;
        return m;
    }
    return 0;
}
int NodeCount(BiTree T)//求总节点数
{
    if(T==NULL)
        return 0;
    int l = NodeCount(T->lchild);
    int r = NodeCount(T->rchild);
    int m = l + r + 1;
    return m;
}
int LeaveCount(BiTree T)//求叶子节点数
{
    if(T==NULL)
        return 0;
    if(T->lchild==NULL&&T->rchild==NULL)
        e++;
    LeaveCount(T->lchild);
    LeaveCount(T->rchild);
    return 0;
}
void TreeSwap(BiTree T)//交换左右子树
{
    if(T!=NULL)
    {
        TreeSwap(T->lchild);
        TreeSwap(T->rchild);
        p = T->lchild;
        T->lchild = T->rchild;
        T->rchild = p;
    }
}
int main()
{
    BiTree T;
    CreateBiTree(T);
    PrintBiTree1(T);
    cout << " ";
    PrintBiTree2(T);
    cout << " ";
    PrintBiTree3(T);
    LeaveCount(T);
    cout << endl
         << e << " " << TreeDepth(T) << endl;
    TreeSwap(T);
    PrintBiTree1(T);
    cout << " ";
    PrintBiTree2(T);
    cout << " ";
    PrintBiTree3(T);
    system("pause");
    return 0;
}