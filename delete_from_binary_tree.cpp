#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
void delete_node(Node *root, int to_delete)
{
    Node *target = NULL, *rightMost = NULL;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (q.empty() && temp -> left == NULL && temp -> right == NULL)
        {
            rightMost = temp;
        }
        if (temp -> data == to_delete)
        {
            target = temp;
        }
        if (temp -> left)
        {
            q.push(temp -> left);
        }
        if (temp -> right)
        {
            q.push(temp -> right);
        }
    }
    target -> data = rightMost -> data;
    q.push(root);
    Node *parent = NULL;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if ((temp -> left && temp -> left == rightMost) || (temp -> right && temp -> right == rightMost))
        {
            parent = temp;
            break;
        }
        if (temp -> left)
        {
            q.push(temp -> left);
        }
        if (temp -> right)
        {
            q.push(temp -> right);
        }
    }
    if (parent && parent -> left == rightMost)
    {
        parent -> left = NULL;
    }
    if (parent && parent -> right == rightMost)
    {
        parent -> right = NULL;
    }
    if (rightMost == root)
    {
        root = NULL;
    }
    delete rightMost;
}
int main()
{
    Node *root = buildTree();
    print(root);
    delete_node(root, 1);
    cout << endl;
    print(root);
}


