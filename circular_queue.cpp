#include<iostream>
using namespace std;
struct node
{
    int info;
    node *link;
}*en = NULL, *start = NULL;
void push()
{
    node *t = new node;
    cin>>t->info;
    if (en == NULL)
    {
        start = t;
        en = t;
        en->link = en;
    }
    else
    {
        t->link = start;
        en->link = t;
        en = t;
    }
}
void show()
{
    if (start == NULL)
    {
        return;
    }
    node *temp = start;
    while (temp != en)
    {
        cout<<temp->info<<" ";
        temp = temp->link;
    }
    cout<<en->info;
}
void del()
{
    if (en == start)
    {
        en = NULL;
        start = NULL;
    }
    else
    {
        en->link = (en->link)->link;
        start->link = NULL;
        start = en->link;
    }
}
int main()
{
    for (int i = 0;i < 5;i++)
    {
        push();
    }
    for (int i = 0;i < 5;i++)
    {
        show();
        cout<<endl;
        del();
    }
}
