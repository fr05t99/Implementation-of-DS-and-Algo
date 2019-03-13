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
pair<int, int> diameter(Node *root)
{
    pair<int, int> temp;
    if (root == NULL)
    {
        temp.first = temp.second = 0;
        return temp;
    }
    auto p = diameter(root->left);
    auto q = diameter(root->right);
    temp.second = max(p.second, q.second) + 1;
    temp.first = max(p.first, max(q.first, p.second + q.second));
    return temp;
}
int main()
{
    Node *root = buildTree();
    print(root);
    cout << endl;
    cout << diameter(root).first;
}

