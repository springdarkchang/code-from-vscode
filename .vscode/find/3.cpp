#include<iostream>
using namespace std;
typedef struct{
    int key;              
    int value;
    int isfull;
} HashNode;
typedef struct{
    HashNode *elem;
    int sizeindex;
} HashTable;
int mo;
void InitHash(HashTable &H,int m)
{
    int i;
    H.sizeindex = m;
    H.elem = (HashNode*)malloc(H.sizeindex * sizeof(HashNode));
    for (i = 0; i < H.sizeindex;i++)
        H.elem[i].isfull = 0;
}
int Hash(int key)
{
    int hash= key % mo;
    return hash;
}
void InsertHash(HashTable &H,int key,int value)
{
    int p = Hash(key);
    while(H.elem[p].isfull==1)
        p = (p + 1) % mo;
    H.elem[p].key = key;
    H.elem[p].value = value;
    H.elem[p].isfull = 1;
}
int SearchHash(HashTable H,int key)
{
    int p = Hash(key);
    while(H.elem[p].isfull==1&&H.elem[p].key!=key)
    {
        p = (p + 1) % mo;
        if(H.elem[p].isfull==0||p==Hash(key))
            return -1;
    }
    return p;
}
int main()
{
    HashTable H;
    int m, n, key, value, p;
    cin >> m >> mo >> n;
    InitHash(H,m);
    for (int i = 0; i < n;i++)
    {
        cin >> key >> value;
        InsertHash(H, key, value);
    }
    cin >> key;
    p=SearchHash(H, key);
    if(p==-1)
        cout << "NotFind" << endl;
    else
    {
        cout << "Find " << p << endl
             << H.elem[p].key << " " << H.elem[p].value << endl;
    }
    return 0;
}