#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left;
    node *right;
}*start = NULL,
*tail = NULL,
*temp = NULL;

void insertBeg()
{
    node *t = new node;
    cin >> t->info;
    t->right = NULL;
    t->left = NULL;
    if (start == NULL)
    {
        start = t;
        tail = t;
    }
    else
    {
        t->right = start;
        start->left = t;
        start = t;
    }
}

void deleteBeg()
{
    if (start == tail)
    {
        start = NULL;
        tail = NULL;
    }
    else
    {
        start = start->right;
        start->left = NULL;
    }
}

void insertEnd()
{
    node *t = new node;
    cin >> t->info;
    t->right = NULL;
    t->left = NULL;
    if (start == NULL)
    {
        start = t;
        tail = t;
    }
    else
    {
        tail->right = t;
        t->left = tail;
        tail = t;
    }
}

void deleteEnd()
{
    if (start == tail)
    {
        start = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->left;
        tail->right = NULL;
    }
}

void display()
{
    if (start == NULL)
    {
        cout<<"\nList Empty\n";
    }
    temp = start;
    while (temp != NULL)
    {
        cout<<temp->info<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

void showFront()
{
    if (start == NULL)
    {
        cout<<"\nList Empty\n";
    }
    else
    {
        cout<<start->info<<endl;
    }
}

void showEnd()
{
    if (tail == NULL)
    {
        cout<<"\nList Empty\n";
    }
    else
    {
        cout<<tail->info<<endl;
    }
}

int main()
{
    int choice;
    while (1)
    {
        cout<<"\n1. Insert at Beg\n2. Insert at End\n3. Delete from Beg\n4. Delete from End\n5. Show Front\n6. Show Tail\n7. Display\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            insertBeg();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            deleteBeg();
            break;
        case 4:
            deleteEnd();
            break;
        case 5:
            showFront();
            break;
        case 6:
            showEnd();
            break;
        case 7:
            display();
            break;
        default:
            cout<<"\nWrong\n";
        }
    }
}
