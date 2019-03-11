#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *left, *right, *parent;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};
class Heap
{
public:
    node *root;
    Heap(int d)
    {
        node *t = new node(d);
        root = t;
    }
    void insert(int d)
    {
        queue<node*> q;
        node *t = new node(d);
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            if (temp -> left)
            {
                q.push(temp->left);
            }
            else
            {
                t -> parent = temp;
                temp -> left = t;
                break;
            }
            if (temp -> right)
            {
                q.push(temp -> right);
            }
            else
            {
                t -> parent = temp;
                temp -> right = t;
                break;
            }
        }
        node *temp = t;
        while (temp -> parent != NULL)
        {
            if (temp -> data > temp -> parent -> data)
            {
                swap(temp -> data, temp -> parent -> data);
            }
            temp = temp -> parent;
        }
    }
    void show()
    {
        queue<node*> q;
        q.push(root);
        while (!q.empty())
        {
            node *temp = q.front();
            q.pop();
            cout << temp -> data << endl;
            if (temp -> left)
            {
                q.push(temp -> left);
            }
            if (temp -> right)
            {
                q.push(temp -> right);
            }
        }
    }
};
int main()
{
    Heap h(5);
    h.insert(2);
    h.insert(4);
    h.insert(5);
    h.insert(6);
    h.show();
}
