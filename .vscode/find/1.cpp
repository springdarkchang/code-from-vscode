#include<iostream>
using namespace std;
typedef struct{
    int key;
    int num;
} ElemType;
typedef struct{
    ElemType *elem;
    int length;
} SSTable;
void InitSSTable(SSTable &ST)
{
    cin >> ST.length;
    ST.elem = (ElemType *)malloc((ST.length + 1) * sizeof(ElemType));
    for (int i = 1; i <= ST.length;i++)
    {
        cin >> ST.elem[i].key >> ST.elem[i].num;
    }
}
void Search_Seq(SSTable ST,int key)
{
    ST.elem[0].key = key;
    int i = ST.length, j = 0;
    while(ST.elem[i].key!=key)
    {
        i--;
        j++;
    }
    if(i==0)
        cout << "NotFind " << ++j << endl;
    else
        cout << "Find " << ++j << endl;
}
void Search_Bin(SSTable ST,int key)
{
    int low = 1, high = ST.length, i = 0, f = 0;
    while(low<=high)
    {
        int mid = (low + high) / 2;
        if(ST.elem[mid].key==key)
        {
            cout << "Find " << ++i << endl;
            f = 1;
            break;
        }
        else
        {
            if(key<ST.elem[mid].key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        i++;
    }
    if(f==0)
        cout << "NotFind " << i << endl;
}
int main()
{
    int key;
    SSTable ST;
    InitSSTable(ST);
    cin >> key;
    Search_Seq(ST, key);
    Search_Bin(ST, key);
    return 0;
}