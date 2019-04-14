#include<iostream>
using namespace std;
int n = 0;
int tree[100];
int k;
void dis()
{
    for (int i = 1;i <= k;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
}
void insheap()
{
    int item;
    cin>>item;
    n++;
    int ptr = n;
    int par;
    while(ptr > 1)
    {
        par = ptr/2;
        if (item > tree[par])
        {
            tree[ptr] = tree[par];
            ptr = par;
        }
        else
        {
            tree[ptr] = item;
            return;
        }
    }
    tree[1] = item;
    return;
}
void delheap()
{
    int item = tree[1];
    int last = tree[n];
    tree[n] = item;
    n--;
    int ptr = 1,left = 2,right = 3;
    while (right <= n)
    {
        if (last >= tree[left] && last >= tree[right])
        {
            tree[ptr] = last;
            return;
        }
        if (tree[right] <= tree[left])
        {
            tree[ptr] = tree[left];
            ptr = left;
        }
        else
        {
            tree[ptr] = tree[right];
            ptr = right;
        }
        left = 2 * ptr;
        right = left + 1;
    }
    if (left == n && last < tree[left])
    {
        tree[ptr] = tree[left];
        ptr = left;
    }
    tree[ptr] = last;
}
void heapsort()
{
    cout<<"\nElements you want to enter ";
    int c;
    cin>>c;
    for (int i = 0;i < c;i++)
    {
        insheap();
    }
    k = n;
    dis();
    while (n > 1)
    {
        delheap();
        dis();
    }
    dis();
}
int main()
{
    heapsort();

}
